
///Sum up the track_pt for BOTH primary and pileup tracks
double sumtrackpt(vector<double>* prim_track_pt,vector<double>* pile_track_pt){
	double sumpt=0;
	for (int i =0;i<prim_track_pt->size();i++){
		sumpt+=prim_track_pt->at(i);
	}
	for (int i=0;i<pile_track_pt->size();i++){
		sumpt+=pile_track_pt->at(i);
	}
	return sumpt;
}


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
 
