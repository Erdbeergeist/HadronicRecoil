///Check for wether it is a Z-Event with M e (Mmin,Mmax).
bool Zcheck(vector<int>* charge, vector<double>* pt, vector<double>* eta, vector<double>* phi, TLorentzVector &recoZ, int Mmin, int Mmax) {
	
	bool Zevent = false;
	///Basic Condition (2 mu with opposite charge)
	if (pt->size()==2 && charge->at(0) != charge->at(1)){
		TLorentzVector mu1,mu2;
		mu1.SetPtEtaPhiM(pt->at(0),eta->at(0),phi->at(0),105.6);
		mu2.SetPtEtaPhiM(pt->at(1),eta->at(1),phi->at(1),105.6);
		recoZ = mu1+mu2;
		double mass = recoZ.M()/1000;
		if (mass> Mmin) if (mass< Mmax)	Zevent = true;///Check if M is within given boundaries
	}
	return Zevent;
}
 
 
double GetMinBiasMean(TFile *fileAI,double pt, double eta, int NumberofVertices){
	double mean=0;
	array<double,6> EtaLimits = {5,10,15,20,25,40};
	array<int,6> NumberofVerticesLimits = {5,10,15,20,25,30};
	array<int,6> PTLimits = {400,700,1000,1300,1600,1900};
	//cout<<pt<<"\t"<<eta<<"\t"<<NumberofVertices<<endl;
	
	int sorteta=0,sortpt=0;
	
	
	for (int i=0;i<EtaLimits.size();i++){
		if(eta<EtaLimits[i]/10){
			sorteta = (int) (EtaLimits[i]);
			break;
		}
	}	
			for (int j=0;j<NumberofVerticesLimits.size();j++){
					if(NumberofVertices<NumberofVerticesLimits[j]){
						NumberofVertices = NumberofVerticesLimits[j];
						break;
					}	
			}		
						for (int k=0;k<PTLimits.size();k++){
							if (pt<PTLimits[k]){
								sortpt = (int) PTLimits[k];
								break;
							}	
						}
					
				
			
		
	//cout<<sortpt<<"\t"<<sorteta<<"\t"<<NumberofVertices<<endl;		
	if (eta> EtaLimits[5]/10) sorteta = (int) (EtaLimits[5]);
	if (NumberofVertices>NumberofVerticesLimits[5]) NumberofVertices = NumberofVerticesLimits[5];
	if (pt>PTLimits[5]) sortpt =  PTLimits[5];					
	//cout<<sortpt<<"\t"<<sorteta<<"\t"<<NumberofVertices<<endl;	
	string  name = "SumPTEta"+to_string(sorteta) +"NV"+ to_string(NumberofVertices) + "PT"+to_string(sortpt);
	//cout<<name<<endl;
	TH1F * h1 = new TH1F("h1","h1 title" , 100, 0, 4);
	h1 = (TH1F*)fileAI->Get(name.c_str());
	mean = 100;//h1->GetMean();
	
	
	return mean;
}

///Based on Stephan Tilchs Function calculateHR out of AnalysisFunctions.h
///Calculate the HadronicRecoil by adding up everything but Muons
vector<TVector3> calcHadronicRecoilnoasso(vector<double>* vecCellsPt, vector<double>* vecCellsEta, vector<double>* vecCellsPhi,vector<int>* NumPrimVert, vector<int>* NumPileUp,vector<double>* SumPtPrim, vector<double>* SumPtPileUp, TVector3 mu1, TVector3 mu2,int NumberofVertices,vector<double> * all_track_pt,vector<double>* all_track_eta, vector<double>* all_track_phi,TFile *fileAI){
	double dR = 0.1;
	TVector3 HadronicRecoil,HadronicRecoil2,HadronicRecoil3,HadronicRecoil4;
	vector<TVector3> hadvec;
	int ptsize = vecCellsPt->size();

	for (int i=0; i<ptsize;i++) {
		TVector3 vecCell;
		vecCell.SetPtEtaPhi(vecCellsPt->at(i),vecCellsEta->at(i),vecCellsPhi->at(i));
		
		if(NumPrimVert->at(i)>0) if (vecCell.DeltaR(mu1)>=dR) if (vecCell.DeltaR(mu2)>=dR){
				//algorithm 2 all cells that have a prim track
				HadronicRecoil2 += vecCell; ///making sure not to count muons Count tracks from PVT
				//algorithm 3 all cells that have a prim track, scaled 
				HadronicRecoil3 += NumPrimVert->at(i)/(NumPrimVert->at(i)+NumPileUp->at(i))*vecCell;
				//algorithm 4 all cells that have a prim track, scaled with pt
				HadronicRecoil4 += SumPtPrim->at(i)/(SumPtPrim->at(i)+SumPtPileUp->at(i))*vecCell;
				
			}
		
		
		if (NumPileUp->at(i) <1 && NumPrimVert->at(i) <1){
			if (vecCell.DeltaR(mu1)>=dR) if(vecCell.DeltaR(mu2)>=dR){
				double trackgespt=0;
				for (int j =0;j<all_track_pt->size();j++){
					if(sqrt(pow(vecCell.Eta()-all_track_eta->at(j),2)+pow(vecCell.Phi()-all_track_phi->at(j),2))<0.1) trackgespt+=all_track_pt->at(j);
				}
		
		
				double minbiasmean = GetMinBiasMean(fileAI, trackgespt,  fabs(vecCell.Eta()),NumberofVertices);
				//cout<<vecCellsPt->at(i)-minbiasmean<<endl;
				if (vecCell.Pt()-minbiasmean>0) {
					vecCell.SetPtEtaPhi(vecCellsPt->at(i)-minbiasmean,vecCellsEta->at(i),vecCellsPhi->at(i));
					HadronicRecoil += vecCell;
					HadronicRecoil2 += vecCell;
					HadronicRecoil3 += vecCell;
					HadronicRecoil4 += vecCell;
					
				}		
			}	
		
		}
		else if (vecCell.DeltaR(mu1)>=dR) if(vecCell.DeltaR(mu2)>=dR)		HadronicRecoil += vecCell; ///making sure not to count muons
			

	}
	
	hadvec.push_back(HadronicRecoil);
	hadvec.push_back(HadronicRecoil2);
	hadvec.push_back(HadronicRecoil3);
	hadvec.push_back(HadronicRecoil4);
	
	return hadvec;
}


///Based on Stephan Tilchs Function calculateHR_1PVT out of AnalysisFunctions.h
///Calculate the HadronicRecoil by adding up everything but Muons, that has at least 1 track associated with the PVT and all Cells without association
TVector3 calcHadronicRecoilPrimVertnoasso(vector<double>* vecCellsPt, vector<double>* vecCellsEta, vector<double>* vecCellsPhi,vector<int>* NumPrimVert, vector<int>* NumPileUp, TVector3 mu1, TVector3 mu2,int NumberofVertices,vector<double> * all_track_pt,vector<double>* all_track_eta, vector<double>* all_track_phi,TFile *fileAI) {
	double dR = 0.1;
	TVector3 HadronicRecoil;
	int ptsize = vecCellsPt->size();

	for (int i=0; i< ptsize;i++) {
		TVector3 vecCell;
		vecCell.SetPtEtaPhi(vecCellsPt->at(i),vecCellsEta->at(i),vecCellsPhi->at(i));
		
		
			if(NumPrimVert->at(i)>0) if (vecCell.DeltaR(mu1)>=dR) if (vecCell.DeltaR(mu2)>=dR){
				HadronicRecoil += vecCell; ///making sure not to count muons Count tracks from PVT
				continue;
			}
		if (NumPileUp->at(i) <1 && NumPrimVert->at(i) <1){
			if (vecCell.DeltaR(mu1)>=dR) if(vecCell.DeltaR(mu2)>=dR){
				double trackgespt=0;
				for (int j =0;j<all_track_pt->size();j++){
					if(sqrt(pow(vecCell.Eta()-all_track_eta->at(j),2)+pow(vecCell.Phi()-all_track_phi->at(j),2))<0.1) trackgespt+=all_track_pt->at(j);
				}
		
		
				double minbiasmean = GetMinBiasMean(fileAI, trackgespt,  fabs(vecCell.Eta()),NumberofVertices);
				//cout<<vecCellsPt->at(i)-minbiasmean<<endl;
				if (vecCell.Pt()-minbiasmean>0) {
					vecCell.SetPtEtaPhi(vecCellsPt->at(i)-minbiasmean,vecCellsEta->at(i),vecCellsPhi->at(i));
					HadronicRecoil += vecCell;
				}		
			}	
		
		}
		//else if (vecCell.DeltaR(mu1)>=dR) if(vecCell.DeltaR(mu2)>=dR)		HardronicRecoil += vecCell; ///making sure not to count muons	
		
	}
			
	
	return HadronicRecoil;
}

///Based on Stephan Tilchs Function calculateHR_AsN out of AnalysisFunctions.h
///Calculate the HadronicRecoil by adding up everything but Muons, that has at least 1 track associated with the PVT, but scaled with NPV/(NPV+NPU)
TVector3 calcHadronicRecoilPrimVertScalednoasso(vector<double>* vecCellsPt, vector<double>* vecCellsEta, vector<double>* vecCellsPhi,vector<int>* NumPrimVert, vector<int>* NumPileUp, TVector3 mu1, TVector3 mu2,int NumberofVertices,vector<double> * all_track_pt,vector<double>* all_track_eta, vector<double>* all_track_phi,TFile *fileAI) {
	double dR = 0.1;
	TVector3 HadronicRecoil;
	int ptsize = vecCellsPt->size();
	for (int i=0; i< ptsize;i++) {
		TVector3 vecCell;
		vecCell.SetPtEtaPhi(vecCellsPt->at(i),vecCellsEta->at(i),vecCellsPhi->at(i));
		
			if (NumPrimVert->at(i)>0)	if (vecCell.DeltaR(mu1)>=dR) if (vecCell.DeltaR(mu2)>=dR)	{
				HadronicRecoil += NumPrimVert->at(i)/(NumPrimVert->at(i)+NumPileUp->at(i))*vecCell; ///making sure not to count muons Count tracks from PVT scaled
				continue;
			}
			if (NumPileUp->at(i) <1 && NumPrimVert->at(i) <1){
			if (vecCell.DeltaR(mu1)>=dR) if(vecCell.DeltaR(mu2)>=dR){
				double trackgespt=0;
				for (int j =0;j<all_track_pt->size();j++){
					if(sqrt(pow(vecCell.Eta()-all_track_eta->at(j),2)+pow(vecCell.Phi()-all_track_phi->at(j),2))<0.1) trackgespt+=all_track_pt->at(j);
				}
		
		
				double minbiasmean = GetMinBiasMean(fileAI, trackgespt,  fabs(vecCell.Eta()),NumberofVertices);
				//cout<<vecCellsPt->at(i)-minbiasmean<<endl;
				if (vecCell.Pt()-minbiasmean>0) {
					vecCell.SetPtEtaPhi(vecCellsPt->at(i)-minbiasmean,vecCellsEta->at(i),vecCellsPhi->at(i));
					HadronicRecoil += vecCell;
				}		
			}	
		
			}
		
	}
	
	
	return HadronicRecoil;
}


///Based on Stephan Tilchs Function calculateHR_AsPt out of AnalysisFunctions.h
///Calculate the HadronicRecoil by adding up everything but Muons, that has at least 1 track associated with the PVT, but scaled with transverse Momentum proportion
TVector3 calcHadronicRecoilPrimVertPtScalednoasso(vector<double>* vecCellsPt, vector<double>* vecCellsEta, vector<double>* vecCellsPhi,vector<int>* NumPrimVert, vector<int>* NumPileUp,vector<double>* SumPtPrim, vector<double>* SumPtPileUp, TVector3 mu1, TVector3 mu2,int NumberofVertices,vector<double> * all_track_pt,vector<double>* all_track_eta, vector<double>* all_track_phi,TFile *fileAI){
	double dR = 0.1;
	TVector3 HadronicRecoil;
	int ptsize = vecCellsPt->size();
	for (int i=0; i< ptsize;i++) {
		TVector3 vecCell;
		vecCell.SetPtEtaPhi(vecCellsPt->at(i),vecCellsEta->at(i),vecCellsPhi->at(i));
		
		
			if (NumPrimVert->at(i)>0) if (vecCell.DeltaR(mu1)>=dR && vecCell.DeltaR(mu2)>=dR){
				HadronicRecoil += SumPtPrim->at(i)/(SumPtPrim->at(i)+SumPtPileUp->at(i))*vecCell; ///making sure not to count muons Count tracks from PVT, but scale with PT proportion
				continue;
			}
			if (NumPileUp->at(i) <1 && NumPrimVert->at(i) <1){
			if (vecCell.DeltaR(mu1)>=dR) if(vecCell.DeltaR(mu2)>=dR){
				double trackgespt=0;
				for (int j =0;j<all_track_pt->size();j++){
					if(sqrt(pow(vecCell.Eta()-all_track_eta->at(j),2)+pow(vecCell.Phi()-all_track_phi->at(j),2))<0.1) trackgespt+=all_track_pt->at(j);
				}
		
		
				double minbiasmean = GetMinBiasMean(fileAI, trackgespt,  fabs(vecCell.Eta()),NumberofVertices);
				//cout<<vecCellsPt->at(i)-minbiasmean<<endl;
				if (vecCell.Pt()-minbiasmean>0) {
					vecCell.SetPtEtaPhi(vecCellsPt->at(i)-minbiasmean,vecCellsEta->at(i),vecCellsPhi->at(i));
					HadronicRecoil += vecCell;
				}		
			}	
		
		}
		
		
	}
	
	return HadronicRecoil;
}

///Compare all cells - all prim- and sec- Vertex =!= all without association
TVector3 calcHadronicRecoilPileUp(vector<double>* vecCellsPt, vector<double>* vecCellsEta, vector<double>* vecCellsPhi, TVector3 mu1, TVector3 mu2,vector<int>* NumPrimVert, vector<int>* NumPileUp, double dR = 0.1) {
	TVector3 HadronicRecoil;
	
	for (int i=0; i< vecCellsPt->size();i++) {
		TVector3 vecCell;
		vecCell.SetPtEtaPhi(vecCellsPt->at(i),vecCellsEta->at(i),vecCellsPhi->at(i));
		
		if (vecCell.DeltaR(mu1)>=dR && vecCell.DeltaR(mu2)>=dR && NumPileUp->at(i)>0)		HadronicRecoil += vecCell; ///making sure not to count muons Count tracks from PVT
		if (vecCell.DeltaR(mu1)>=dR && vecCell.DeltaR(mu2)>=dR && NumPrimVert->at(i)==0 && NumPileUp->at(i)==0)		HadronicRecoil +=vecCell; ///making sure not to count muons Count without association

	}
	
	return HadronicRecoil;

}

///Based on Stephan Tilchs Function calculateHR_AsPt out of AnalysisFunctions.h
///Calculate the HadronicRecoil by adding up everything but Muons, that has at least 1 track associated with the PVT, but scaled with transverse Momentum proportion, BUT also the not associated cells get scaled
TVector3 calcHadronicRecoilPrimVertPtScaledImp(vector<double>* vecCellsPt, vector<double>* vecCellsEta, vector<double>* vecCellsPhi, TVector3 mu1, TVector3 mu2, vector<int>* NumPrimVert, vector<double>* SumPtPrim, vector<int>* NumPileUp, vector<double>* SumPtPileUp, double dR = 0.1) {
	
	TVector3 HadronicRecoil;
	double noAscale=0,pv=0,sv=0;
	///Calculated the TOTAL factor of SumPtPrim/(SumPtPrim + SumPileUp) to scale the non associated cells for this Event
	for (int i=0; i< vecCellsPt->size();i++) {
		pv+=SumPtPrim->at(i);
		sv+=SumPtPileUp->at(i);
	}	
	noAscale = pv/(pv+sv);
	for (int i=0; i< vecCellsPt->size();i++) {
		TVector3 vecCell;
		vecCell.SetPtEtaPhi(vecCellsPt->at(i),vecCellsEta->at(i),vecCellsPhi->at(i));
		
		if (vecCell.DeltaR(mu1)>=dR && vecCell.DeltaR(mu2)>=dR && NumPrimVert->at(i)>0)		HadronicRecoil += SumPtPrim->at(i)/(SumPtPrim->at(i)+SumPtPileUp->at(i))*vecCell; ///making sure not to count muons Count tracks from PVT, but scale with PT proportion
		if (vecCell.DeltaR(mu1)>=dR && vecCell.DeltaR(mu2)>=dR && NumPrimVert->at(i)==0 && NumPileUp->at(i)==0)		HadronicRecoil +=noAscale*vecCell; ///making sure not to count muons Count without association

	}
	
	return HadronicRecoil;
}

///Find P,S,noA Cells
string PSnA(vector<double>* vecCellsPt, vector<double>* vecCellsEta, vector<double>* vecCellsPhi, TVector3 mu1, TVector3 mu2,vector<int>* NumPrimVert, vector<int>* NumPileUp, double dR = 0.1){
		
		string psna="##";
				
		for (int i=0; i< vecCellsPt->size();i++) {
			TVector3 vecCell;
			vecCell.SetPtEtaPhi(vecCellsPt->at(i),vecCellsEta->at(i),vecCellsPhi->at(i));
		
			if (vecCell.DeltaR(mu1)>=dR && vecCell.DeltaR(mu2)>=dR){
				if (NumPrimVert->at(i)>0) psna+="P";
				if (NumPileUp->at(i)>0) psna+="S";
				else psna+="N";
			}
			
	}
	psna +="##\n";
	return psna;
}

///Show the sum of PT for PileUp and PrimaryVertex
void PTsum(vector<double>* vecCellsPt, vector<double>* vecCellsEta, vector<double>* vecCellsPhi, TVector3 mu1, TVector3 mu2, vector<int>* NumPrimVert, vector<double>* SumPtPrim, vector<int>* NumPileUp, vector<double>* SumPtPileUp, double dR = 0.1){
		
		double ppt=0,spt=0;
			
		for (int i=0; i< vecCellsPt->size();i++) {
			TVector3 vecCell;
			vecCell.SetPtEtaPhi(vecCellsPt->at(i),vecCellsEta->at(i),vecCellsPhi->at(i));
		
			if (vecCell.DeltaR(mu1)>=dR && vecCell.DeltaR(mu2)>=dR){
				if (NumPrimVert->at(i)>0) ppt+=SumPtPrim->at(i);
				if (NumPileUp->at(i)>0) spt+=SumPtPileUp->at(i);
				
			}
		
	}
	cout<<"PPt: "<<ppt<< "\t SPt: "<<spt<<" \t"<<ppt/spt<<endl;
}



