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

///Based on Stephan Tilchs Function calculateHR out of AnalysisFunctions.h
///Calculate the HadronicRecoil by adding up everything but Muons
TVector3 calcHadronicRecoil(vector<double>* vecCellsPt, vector<double>* vecCellsEta, vector<double>* vecCellsPhi, TVector3 mu1, TVector3 mu2, double dR = 0.1) {
		
	TVector3 HardronicRecoil;
	int ptsize = vecCellsPt->size();

	for (int i=0; i<ptsize;i++) {
		TVector3 vecCell;
		vecCell.SetPtEtaPhi(vecCellsPt->at(i),vecCellsEta->at(i),vecCellsPhi->at(i));
		
		if (vecCell.DeltaR(mu1)>=dR) if(vecCell.DeltaR(mu2)>=dR)		HardronicRecoil += vecCell; ///making sure not to count muons
			

	}
	
	return HardronicRecoil;
}

///Based on Stephan Tilchs Function calculateHR_1PVT out of AnalysisFunctions.h
///Calculate the HadronicRecoil by adding up everything but Muons, that has at least 1 track associated with the PVT and all Cells without association
TVector3 calcHadronicRecoilPrimVert(vector<double>* vecCellsPt, vector<double>* vecCellsEta, vector<double>* vecCellsPhi, TVector3 mu1, TVector3 mu2, vector<int>* NumPrimVert, vector<int>* NumPileUp, double dR = 0.1) {
	
	TVector3 HadronicRecoil;
	int ptsize = vecCellsPt->size();

	for (int i=0; i< ptsize;i++) {
		TVector3 vecCell;
		vecCell.SetPtEtaPhi(vecCellsPt->at(i),vecCellsEta->at(i),vecCellsPhi->at(i));
		
		
			if(NumPrimVert->at(i)>0) if (vecCell.DeltaR(mu1)>=dR) if (vecCell.DeltaR(mu2)>=dR){
				HadronicRecoil += vecCell; ///making sure not to count muons Count tracks from PVT
				continue;
			}
			if(NumPileUp->at(i)==0 ){
				if (NumPrimVert->at(i)==0)	if (vecCell.DeltaR(mu1)>=dR) if (vecCell.DeltaR(mu2)>=dR) HadronicRecoil +=vecCell; ///making sure not to count muons Count without association
			}
		}
			
	
	return HadronicRecoil;
}

///Based on Stephan Tilchs Function calculateHR_AsN out of AnalysisFunctions.h
///Calculate the HadronicRecoil by adding up everything but Muons, that has at least 1 track associated with the PVT, but scaled with NPV/(NPV+NPU)
TVector3 calcHadronicRecoilPrimVertScaled(vector<double>* vecCellsPt, vector<double>* vecCellsEta, vector<double>* vecCellsPhi, TVector3 mu1, TVector3 mu2, vector<int>* NumPrimVert, vector<int>* NumPileUp, double dR = 0.1) {
	
	TVector3 HadronicRecoil;
	int ptsize = vecCellsPt->size();
	for (int i=0; i< ptsize;i++) {
		TVector3 vecCell;
		vecCell.SetPtEtaPhi(vecCellsPt->at(i),vecCellsEta->at(i),vecCellsPhi->at(i));
		
			if (NumPrimVert->at(i)>0)	if (vecCell.DeltaR(mu1)>=dR) if (vecCell.DeltaR(mu2)>=dR)	{
				HadronicRecoil += NumPrimVert->at(i)/(NumPrimVert->at(i)+NumPileUp->at(i))*vecCell; ///making sure not to count muons Count tracks from PVT scaled
				continue;
			}
			if (NumPileUp->at(i)==0) if (NumPrimVert->at(i)==0)  if (vecCell.DeltaR(mu1)>=dR) if (vecCell.DeltaR(mu2)>=dR) HadronicRecoil +=vecCell; ///making sure not to count muons Count without association
	}
	
	
	return HadronicRecoil;
}

///Based on Stephan Tilchs Function calculateHR_AsN out of AnalysisFunctions.h
///Calculate the HadronicRecoil by adding up everything but Muons, that has at least 1 track associated with the PVT, but scaled with NPV/(NPV+NPU), BUT also scales the not associated Cells
TVector3 calcHadronicRecoilPrimVertScaledImp(vector<double>* vecCellsPt, vector<double>* vecCellsEta, vector<double>* vecCellsPhi, TVector3 mu1, TVector3 mu2, vector<int>* NumPrimVert, vector<int>* NumPileUp, double dR = 0.1) {
	
	TVector3 HadronicRecoil;
	
	double noAscale=0,pv=0,sv=0;
	///Calculated the TOTAL factor of NumPrimVert/(NumPileUp + NumPrimVert) to scale the non associated cells for this Event
	for (int i=0; i< vecCellsPt->size();i++) {
		pv+=NumPrimVert->at(i);
		sv+=NumPileUp->at(i);
	}	
	noAscale = pv/(pv+sv);
	
	for (int i=0; i< vecCellsPt->size();i++) {
		TVector3 vecCell;
		vecCell.SetPtEtaPhi(vecCellsPt->at(i),vecCellsEta->at(i),vecCellsPhi->at(i));
		
		if (vecCell.DeltaR(mu1)>=dR && vecCell.DeltaR(mu2)>=dR) {
			if (NumPrimVert->at(i)>0)		HadronicRecoil += NumPrimVert->at(i)/(NumPrimVert->at(i)+NumPileUp->at(i))*vecCell; ///making sure not to count muons Count tracks from PVT scaled
			if (NumPrimVert->at(i)==0 && NumPileUp->at(i)==0)		HadronicRecoil +=noAscale*vecCell; ///making sure not to count muons Count without association
		}
	}
	
	return HadronicRecoil;
}

///Based on Stephan Tilchs Function calculateHR_AsPt out of AnalysisFunctions.h
///Calculate the HadronicRecoil by adding up everything but Muons, that has at least 1 track associated with the PVT, but scaled with transverse Momentum proportion
TVector3 calcHadronicRecoilPrimVertPtScaled(vector<double>* vecCellsPt, vector<double>* vecCellsEta, vector<double>* vecCellsPhi, TVector3 mu1, TVector3 mu2, vector<int>* NumPrimVert, vector<double>* SumPtPrim, vector<int>* NumPileUp, vector<double>* SumPtPileUp, double dR = 0.1) {
	
	TVector3 HadronicRecoil;
	int ptsize = vecCellsPt->size();
	for (int i=0; i< ptsize;i++) {
		TVector3 vecCell;
		vecCell.SetPtEtaPhi(vecCellsPt->at(i),vecCellsEta->at(i),vecCellsPhi->at(i));
		
		
			if (NumPrimVert->at(i)>0) if (vecCell.DeltaR(mu1)>=dR && vecCell.DeltaR(mu2)>=dR){
				HadronicRecoil += SumPtPrim->at(i)/(SumPtPrim->at(i)+SumPtPileUp->at(i))*vecCell; ///making sure not to count muons Count tracks from PVT, but scale with PT proportion
				continue;
			}
			if (NumPrimVert->at(i)==0) if (NumPileUp->at(i)==0)	if (vecCell.DeltaR(mu1)>=dR && vecCell.DeltaR(mu2)>=dR)	HadronicRecoil +=vecCell; ///making sure not to count muons Count without association
		
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



