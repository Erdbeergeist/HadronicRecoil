
///Sum up the track_pt for BOTH primary and pileup tracks
///			--- result contains ---
///			--- result[0] contains sum PT of primary tracks ---
///			--- result[1] contains sum PT of pile up tracks ---
///			--- result[2] contains the TOTAL PT of pileup and primary tracks ---
std::vector<double> sumtrackpt(vector<double>* prim_track_pt,vector<double>* pile_track_pt){
	
	double sumpt=0,primpt=0,pilept=0;
	
	for (int i =0;i<prim_track_pt->size();i++){
		sumpt+=prim_track_pt->at(i);
		primpt+=prim_track_pt->at(i);
	}
	
	for (int i=0;i<pile_track_pt->size();i++){
		sumpt+=pile_track_pt->at(i);
		pilept+=pile_track_pt->at(i);
	}
	
	std::vector<double> result;
	result.push_back(primpt/1000);
	result.push_back(pilept/1000);
	result.push_back(sumpt/1000);
	return result;
}

///Check if an event has atleast one track within the ptthreshholds
//			--- opt = 0 at least one greater than ptthresh --- 
//			--- opt = 1 NO track greater ptthresh ---
//			--- opt = 2 MEAN lower than ptthresh --- 
bool checktrackpt(vector<double>* prim_track_pt,vector<double>*pile_track_pt,int ptthresh,int opt = 0){
	bool result = false;
	switch (opt) {
		case 0:
			for (int i = 0;i< prim_track_pt->size();i++){
				if (prim_track_pt->at(i) > ptthresh) {
					result = true;
					//cout<<prim_track_pt->at(i)<<endl;
					return result;
				}
			}	
			for (int j = 0; j < pile_track_pt->size();j++){	
				if (pile_track_pt->at(j) > ptthresh) {
					result = true;
					return result;
				}
			}
		case 1:
			for (int i = 0;i< prim_track_pt->size();i++){
				if (prim_track_pt->at(i) > ptthresh) {
					result = false;
					return result;
				}
			}
			for (int j = 0; j < pile_track_pt->size();j++){	
				if (pile_track_pt->at(j) > ptthresh) {
					result = false;
					return result;
				}
			}
		case 2:
			double sum=0;
			for (int i = 0;i< prim_track_pt->size();i++) sum += prim_track_pt->at(i);
			for (int i = 0;i< pile_track_pt->size();i++) sum += pile_track_pt->at(i);
			//cout<<sum/(prim_track_pt->size()+pile_track_pt->size())<<endl;
			if (sum/(prim_track_pt->size()+pile_track_pt->size())<ptthresh) return true;
				
				
		}
			
	return result;	
}

///Check if the Cluster has associated tracks
///			--- calls Fill2DHists with cond = : ---
///			--- 0 if cluster has no assiciation ---
///			--- 1 if cluster has primary association ---
///			--- 2 if cluster has pile up association ---
///			--- 3 if cluster has both associations ---			
void checkassociation(Hists *hist,vector<int>* countPVvec, vector<int>* countSVvec,vector<double>* vecCellsPt,vector<double>* vecCellsEta,vector<double>* vecCellsPhi,int NumberofVertices){
	bool prim = false,pile = false;
	double pt =0,eta=0,phi=0;
	for (int i=0;i<vecCellsPt->size();i++) {
		prim = false;
		pile = false;
		pt = vecCellsPt->at(i);
		eta = vecCellsEta->at(i);
		phi = vecCellsPhi->at(i);
		if (countPVvec->at(i) > 0) prim = true;
		if (countSVvec->at(i) > 0) pile = true;
		
		if (prim == true){
			hist->Fill2DHists(eta,phi,pt,1,NumberofVertices);
			if (pile == false) {
				hist->Fill2DHists(eta,phi,pt,2);
				hist->FillAssoHists(pt,1);
			}
			continue;
		}
		else {
			hist->FillAssoHists(pt,0);
			if (pile == true) {
				hist->Fill2DHists(eta,phi,pt,1,NumberofVertices);
				hist->Fill2DHists(eta,phi,pt,3);
				continue;
			}
			else hist->Fill2DHists(eta,phi,0,0);
		}
		
		/////		Has Primary OR Secondary Tracks		
		//if ((countPVvec->at(i) > 0) || (countSVvec->at(i) > 0)) {
		//	hist->Fill2DHists(vecCellsEta->at(i),vecCellsPhi->at(i),vecCellsPt->at(i),1,NumberofVertices);
		//}
		
		///		Neither Primary nor Secondary Tracks
		//if ((countPVvec->at(i) == 0) && (countSVvec->at(i) == 0)){
		//	 hist->Fill2DHists(vecCellsEta->at(i),vecCellsPhi->at(i),0,0);
			
	//	}
		///		No Primary Tracks
	//	if (countPVvec->at(i) == 0){
	//		 hist->FillAssoHists(vecCellsPt->at(i),0);
	//	}
		///		Has Primary Tracks; NO Secondary 
	//	if (countPVvec->at(i) > 0 && countSVvec->at(i)<1) {
	//		hist->Fill2DHists(vecCellsEta->at(i),vecCellsPhi->at(i),vecCellsPt->at(i),2);
		//	hist->FillAssoHists(vecCellsPt->at(i),1);
	//	}
		///		Has Secondary Tracks; NO Primary
		//if (countSVvec->at(i) > 0 && countPVvec->at(i)< 1) {
		//	hist->Fill2DHists(vecCellsEta->at(i),vecCellsPhi->at(i),vecCellsPt->at(i),3);
		//}	
		
	}
}

///Check for wether it is a Z-Event with M e (Mmin,Mmax).
bool Zcheck(vector<int>* charge, vector<double>* pt, vector<double>* eta, vector<double>* phi, TLorentzVector &recoZ, int Mmin, int Mmax,Hists *hist) {
	
	bool Zevent = false;
	///Basic Condition (2 mu with opposite charge)
	if (pt->size()==2 && charge->at(0) != charge->at(1)){
		TLorentzVector mu1,mu2;
		mu1.SetPtEtaPhiM(pt->at(0),eta->at(0),phi->at(0),105.6);
		mu2.SetPtEtaPhiM(pt->at(1),eta->at(1),phi->at(1),105.6);
		if (mu1.Pt()>=20000 && mu2.Pt()>=20000){
			recoZ = mu1+mu2;
			hist->FillZHists(0,recoZ.Pt()/1000,recoZ.M()/1000,1);
			if (recoZ.M()>=66000 && recoZ.M()<=106000){
				double pt = recoZ.Pt()/1000;
				if (pt> Mmin) if (pt< Mmax)	Zevent = true;///Check if PT is within given boundaries
			}
							
		}
	}
	hist->FillZHists(pt->size(),0,0,0);
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
 
