// Functions for MiniExample.cxx


struct MainzCaloCell{
	TVector3	vecCell;
	std::vector<TVector3>	primtracks;
	std::vector<TVector3>	pileuptracks;
	int			numberOfAssociatedPrimaryTracks;
	double		sumPtOfAssociatedPrimaryTracks;
	int			numberOfAssociatedPileUpVertexTracks;
	double		sumPtOfAssociatedPileUpVertexTracks;
};

//Check if the Tracks has already been associated or not
bool alrdyasso(std::vector<int> associatednums,int k){
	
		
	for (int i =0;i<associatednums.size();i++){
		if (associatednums[i] == k) return true; 
	}
	return false;
}

//Check if the Track belongs to the primary Vertex
bool isPrimaryVertexTrack(float track_pt, float track_eta, float track_d0, float track_z0sintheta, int track_PixHits, int track_SCTHits){//#LM what is PixHits,SCTHits
	// Does the Track belong to the PV?
	    	if (	(track_pt > 500)
	        	&&	(fabs(track_eta) < 2.5)
	        	&&	(fabs(track_d0) < 1.5)
	        	&&	(fabs(track_z0sintheta) < 1.5)
	        	&&	(track_PixHits >= 1)
	        	&&  (track_SCTHits >= 6) 		 ) {
	        		return true;
	        } //end of if
	        return false;
	    } //end of isPrimaryVertexTrack


//Simply save ALL Tracks no matter if associated with a Cluster or not 
//			--- allprimtracks --- primary Vertex Tracks
//			--- allpiletracks --- pileup Tracks
//			---	alltracks 	  --- ALL Tracks
void GetAllTracks(EWQuickEvent *event,std::vector<TVector3>* alltracks, std::vector<TVector3>* allprimtracks, std::vector<TVector3>* allpiletracks){
	
	TVector3 tTrack;
	
	for (int i =0;i<event->trk_eta_atCalo2ndLayer->size();i++){
		if (event->trk_eta_atCalo2ndLayer->at(i) > -10 && event->trk_eta_atCalo2ndLayer->at(i) < 10) {//#LM trk_eta_atCalo2ndLayer,trk_qoverp_wrtPV,trk_theta_wrtPV what is that ?
			if ((event->trk_qoverp_wrtPV->at(i)==0) || (event->trk_theta_wrtPV->at(i)==0)) continue;
		float track_pt = fabs(1.0/(event->trk_qoverp_wrtPV->at(i)) * sin(event->trk_theta_wrtPV->at(i)));
	
		tTrack.SetPtEtaPhi(track_pt,event->trk_eta_atCalo2ndLayer->at(i),event->trk_phi_atCalo2ndLayer->at(i));
		
		bool isPrim = isPrimaryVertexTrack(tTrack.Pt(), 
						tTrack.Eta(), 
						event->trk_d0->at(i), 
						event->trk_z0->at(i) * sin(event->trk_theta_wrtPV->at(i)),
						event->trk_nPix->at(i),
						event->trk_SCT->at(i) );
		if (isPrim==true) allprimtracks->push_back(tTrack);
		if (isPrim==false) allpiletracks->push_back(tTrack);
		alltracks->push_back(tTrack);
	}
	}
	
}

///Tracks that have not been able to be associated with a cluster get saved
void noaCtracks(EWQuickEvent *event,std::vector<int> &associatednums,std::vector<TVector3>* noaCprimtracks,std::vector<TVector3>* noaCpiletracks){
	
	for (unsigned int k=0; k<event->trk_eta_atCalo2ndLayer->size(); k++) {
		if (alrdyasso(associatednums,k)==false){
		if (event->trk_eta_atCalo2ndLayer->at(k) > -10 && event->trk_eta_atCalo2ndLayer->at(k) < 10) {//#LM trk_eta_atCalo2ndLayer,trk_qoverp_wrtPV,trk_theta_wrtPV what is that ?
			if ((event->trk_qoverp_wrtPV->at(k)==0) || (event->trk_theta_wrtPV->at(k)==0)) continue;
	
			TVector3 tTrack;
		
			float track_pt = fabs(1.0/(event->trk_qoverp_wrtPV->at(k))) * sin(event->trk_theta_wrtPV->at(k));
			tTrack.SetPtEtaPhi(track_pt, 
						event->trk_eta_atCalo2ndLayer->at(k), 
						event->trk_phi_atCalo2ndLayer->at(k));
			bool isPrim = isPrimaryVertexTrack(tTrack.Pt(), 
						tTrack.Eta(), 
						event->trk_d0->at(k), 
						event->trk_z0->at(k) * sin(event->trk_theta_wrtPV->at(k)),
						event->trk_nPix->at(k),
						event->trk_SCT->at(k) );
			if (isPrim==true) noaCprimtracks->push_back(tTrack);
			else noaCpiletracks->push_back(tTrack);
		}
		}
	}	
}

//Takes a Cell (cluster) and checks for Tracks to be associated with
// ---> All associated Tracknumbers get saved in associatednums to prevent associating a track multiple times
void MainzCaloCellLoop(EWQuickEvent *event,TVector3 vecCell, std::vector<TVector3> &primtracks, std::vector<TVector3> &pileuptracks,  double &sumPtPV, double &sumPtSV, int &countPV, int &countSV,std::vector<int> &associatednums) {
	
	for (unsigned int k=0; k<event->trk_eta_atCalo2ndLayer->size(); k++) {
	
		if (event->trk_eta_atCalo2ndLayer->at(k) > -10 && event->trk_eta_atCalo2ndLayer->at(k) < 10) {//#LM trk_eta_atCalo2ndLayer,trk_qoverp_wrtPV,trk_theta_wrtPV what is that ?
			if ((event->trk_qoverp_wrtPV->at(k)==0) || (event->trk_theta_wrtPV->at(k)==0)) continue;
	
			TVector3 tTrack;
		
			float track_pt = fabs(1.0/(event->trk_qoverp_wrtPV->at(k))) * sin(event->trk_theta_wrtPV->at(k));
			tTrack.SetPtEtaPhi(track_pt, 
						event->trk_eta_atCalo2ndLayer->at(k), 
						event->trk_phi_atCalo2ndLayer->at(k));
			bool isPrim = isPrimaryVertexTrack(tTrack.Pt(), 
						tTrack.Eta(), 
						event->trk_d0->at(k), 
						event->trk_z0->at(k) * sin(event->trk_theta_wrtPV->at(k)),
						event->trk_nPix->at(k),
						event->trk_SCT->at(k) );
					
			if ( sqrt ( pow(tTrack.Eta()-vecCell.Eta(),2) + pow(tTrack.Phi()-vecCell.Phi(),2) ) < 0.1 ){		// associated
		 		if (alrdyasso(associatednums,k) == false){
					if (isPrim == true){
					
						sumPtPV += vecCell.Pt();
						countPV += 1;
					
						primtracks.push_back(tTrack);}
		 			
					else {
						sumPtSV += vecCell.Pt();
						countSV += 1;
					
						pileuptracks.push_back(tTrack);}
					associatednums.push_back(k);
				}
					
			}
		}
	
	}

}

//DEPRECATED
void categoriseTracks(EWQuickEvent *event, std::vector<int> &vecVLeft, std::vector<int> &vecLeft, std::vector<int> &vecMiddle, std::vector<int> &vecRight, std::vector<int> &vecVRight) {
	// Tracks are stored in five eta-groups (by index)
	// Borders for usage:  -1.3 -0.45 0.45 1.3
	
	for (int i=0; i<event->trk_eta->size(); i++) {
	
		if (event->trk_eta->at(i) < -1.1){
		vecVLeft.push_back(i);}
		if (event->trk_eta->at(i) > -1.5 && event->trk_eta->at(i) < -0.3){
		vecLeft.push_back(i);}
		if (event->trk_eta->at(i) > -0.6 && event->trk_eta->at(i) < 0.6){
		vecMiddle.push_back(i);}
		if (event->trk_eta->at(i) > 0.3 && event->trk_eta->at(i) < 1.5){
		vecRight.push_back(i);}
		if (event->trk_eta->at(i) > 1.1){
		vecVRight.push_back(i);}
	
	}// end of for-loop

} 

//Store all gathered Information in Tree
void StoreInTree(EWQuickEvent *event, std::vector<MainzCaloCell> vecCaloCells, std::vector<double> &vecCellsPt, std::vector<double> &vecCellsEta, std::vector<double> &vecCellsPhi, std::vector<double> &SumPtPVvec, std::vector<int> &countPVvec, std::vector<double> &SumPtSVvec, std::vector<int> &countSVvec, UInt_t &Event_Nr, UInt_t &Run_Nr, Float_t &averageNumberOfInteractions, std::vector<double> &mu_pt, std::vector<double> &mu_eta, std::vector<double> &mu_phi, std::vector<double> &mu_IsolationParam_ptcone20, std::vector<int> &mu_charge, int &NumberOfVertices, std::vector<double> &jet_pt, std::vector<double> &jet_eta, std::vector<double> &jet_phi, TTree *tree, std::vector<double> &prim_track_pt, std::vector<double> &prim_track_eta, std::vector<double> &prim_track_phi,std::vector<double> &pile_track_pt,std::vector<double> &pile_track_eta, std::vector<double> &pile_track_phi,std::vector<TVector3> &alltracks,std::vector<double> &all_track_pt,	std::vector<double> &all_track_eta,	std::vector<double> &all_track_phi,std::vector<TVector3> &allprimtracks,std::vector<double> &all_prim_track_pt,	std::vector<double> &all_prim_track_eta,std::vector<double> &all_prim_track_phi,std::vector<TVector3> &allpiletracks,std::vector<double> &all_pile_track_pt,std::vector<double> &all_pile_track_eta,std::vector<double> &all_pile_track_phi,std::vector<TVector3> noaCprimtracks,std::vector<double> &noaC_prim_track_pt,std::vector<double> &noaC_prim_track_eta,std::vector<double> &noaC_prim_track_phi,std::vector<TVector3> noaCpiletracks,std::vector<double> &noaC_pile_track_pt,std::vector<double> &noaC_pile_track_eta,std::vector<double> &noaC_pile_track_phi){

	// Clear all variables if necessary (some are cleared at line 246-249)
	NumberOfVertices = 0;
	
	vecCellsPt.clear();
	vecCellsPhi.clear();
	vecCellsEta.clear();

	SumPtPVvec.clear();
	countPVvec.clear();

	SumPtSVvec.clear();
	countSVvec.clear();

	mu_pt.clear();
	mu_eta.clear();
	mu_phi.clear();
	mu_charge.clear();

	mu_IsolationParam_ptcone20.clear();

	jet_pt.clear();
	jet_eta.clear();
	jet_phi.clear();

	prim_track_pt.clear();
	prim_track_eta.clear();
	prim_track_phi.clear();
	pile_track_pt.clear();
	pile_track_eta.clear();
	pile_track_phi.clear();
	all_track_pt.clear();
	all_track_eta.clear();
	all_track_phi.clear();
	all_prim_track_pt.clear();
	all_prim_track_eta.clear();
	all_prim_track_phi.clear();
	all_pile_track_pt.clear();
	all_pile_track_eta.clear();
	all_pile_track_phi.clear();
	noaC_prim_track_pt.clear();
	noaC_prim_track_eta.clear();
	noaC_prim_track_phi.clear();
	noaC_pile_track_pt.clear();
	noaC_pile_track_eta.clear();
	noaC_pile_track_phi.clear();
	
	//Store all track Information
	for (unsigned int i =0;i<alltracks.size();i++){
		all_track_pt.push_back(alltracks[i].Pt());
		all_track_eta.push_back(alltracks[i].Eta());
		all_track_phi.push_back(alltracks[i].Phi());
	}
	for (unsigned int i =0;i<allprimtracks.size();i++){
		all_prim_track_pt.push_back(allprimtracks[i].Pt());
		all_prim_track_eta.push_back(allprimtracks[i].Eta());
		all_prim_track_phi.push_back(allprimtracks[i].Phi());
	}
	for (unsigned int i =0;i<allpiletracks.size();i++){
		all_pile_track_pt.push_back(allpiletracks[i].Pt());
		all_pile_track_eta.push_back(allpiletracks[i].Eta());
		all_pile_track_phi.push_back(allpiletracks[i].Phi());
	}
	
	//Store all noaC_track Information
	for (unsigned int i =0;i<noaCprimtracks.size();i++){
		noaC_prim_track_pt.push_back(noaCprimtracks[i].Pt());
		noaC_prim_track_eta.push_back(noaCprimtracks[i].Eta());
		noaC_prim_track_phi.push_back(noaCprimtracks[i].Phi());
	}
	
	//Store all noaC_track Information
	for (unsigned int i =0;i<noaCpiletracks.size();i++){
		noaC_pile_track_pt.push_back(noaCpiletracks[i].Pt());
		noaC_pile_track_eta.push_back(noaCpiletracks[i].Eta());
		noaC_pile_track_phi.push_back(noaCpiletracks[i].Phi());
	}
	
	// Store Content of vecCaloCells in 7 vectors
	for (unsigned int i=0; i<vecCaloCells.size(); i++){
	
		vecCellsPt.push_back(vecCaloCells[i].vecCell.Pt());
		vecCellsEta.push_back(vecCaloCells[i].vecCell.Eta());
		vecCellsPhi.push_back(vecCaloCells[i].vecCell.Phi());
		
		SumPtPVvec.push_back(vecCaloCells[i].sumPtOfAssociatedPrimaryTracks);
		countPVvec.push_back(vecCaloCells[i].numberOfAssociatedPrimaryTracks);
		
		SumPtSVvec.push_back(vecCaloCells[i].sumPtOfAssociatedPileUpVertexTracks);
		countSVvec.push_back(vecCaloCells[i].numberOfAssociatedPileUpVertexTracks);
		
		for (unsigned int j=0; j<vecCaloCells[i].primtracks.size();j++){
			prim_track_pt.push_back(vecCaloCells[i].primtracks[j].Pt());
			prim_track_eta.push_back(vecCaloCells[i].primtracks[j].Eta());
			prim_track_phi.push_back(vecCaloCells[i].primtracks[j].Phi());	
		}
		
		for (unsigned int k=0; k<vecCaloCells[i].pileuptracks.size();k++){
			pile_track_pt.push_back(vecCaloCells[i].pileuptracks[k].Pt());
			pile_track_eta.push_back(vecCaloCells[i].pileuptracks[k].Eta());
			pile_track_phi.push_back(vecCaloCells[i].pileuptracks[k].Phi());	
		}
		
	}

	// Integer variables
	Event_Nr = event->EventNumber;
	Run_Nr = event->RunNumber;
	averageNumberOfInteractions = event->averageIntPerXing;

	// Muon information
	for (unsigned int k = 0; k<event->mu_staco_n; k++) {

		mu_pt.push_back(event->mu_staco_pt->at(k));
		mu_eta.push_back(event->mu_staco_eta->at(k));
		mu_phi.push_back(event->mu_staco_phi->at(k));

		mu_IsolationParam_ptcone20.push_back(event->mu_staco_ptcone20->at(k));

		mu_charge.push_back(event->mu_staco_charge->at(k));
	}

	// Jet information
	for (unsigned int k = 0; k<event->jet_AntiKt4LCTopo_pt->size(); k++) {

		jet_pt.push_back(event->jet_AntiKt4LCTopo_pt->at(k));
		jet_eta.push_back(event->jet_AntiKt4LCTopo_eta->at(k));
		jet_phi.push_back(event->jet_AntiKt4LCTopo_phi->at(k));

	}
	
	// Calculate Number of vertices
	for (unsigned int j=0; j<event->vxp_n; j++) {

		if (event->vxp_trk_n->at(j) > 2) {
			NumberOfVertices += 1;
		}

	}

	tree->Fill();

}

//Creates a MainzCaloCell for every Cluster and calls the Functions to associated the tracks with the Clusters
void FillMainzCaloCellVector(EWQuickEvent *event, std::vector<MainzCaloCell> &vecCaloCells,std::vector<TVector3>*noaCprimtracks,std::vector<TVector3>* noaCpiletracks) {
	
	std::vector<int> associatednums; 
	associatednums.clear();
	//Cluster-Loop
	//For each Cluster one MainzCaloCell
	for (unsigned int j=0; j<event->cl_lc_n; j++) {	

		MainzCaloCell newCell;

		newCell.vecCell.SetPtEtaPhi(event->cl_lc_pt->at(j), event->cl_lc_eta->at(j), event->cl_lc_phi->at(j));

		newCell.numberOfAssociatedPileUpVertexTracks = 0;
		newCell.sumPtOfAssociatedPileUpVertexTracks = 0;
		newCell.numberOfAssociatedPrimaryTracks = 0;
		newCell.sumPtOfAssociatedPrimaryTracks = 0;
		
		MainzCaloCellLoop(event,newCell.vecCell,newCell.primtracks,newCell.pileuptracks, newCell.sumPtOfAssociatedPrimaryTracks, newCell.sumPtOfAssociatedPileUpVertexTracks, newCell.numberOfAssociatedPrimaryTracks, newCell.numberOfAssociatedPileUpVertexTracks,associatednums);
	
		
		
		
		vecCaloCells.push_back(newCell);
	}
	noaCtracks(event,associatednums,noaCprimtracks,noaCpiletracks);
} 
