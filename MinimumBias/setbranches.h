/// --- START --- This Section was taken from Stephan Tilchs Analysis_Zmumu.cxx
	// Setting Branch Addresses for Reading Data
	std::vector<double>* 		vecCellsPt = 0;
	std::vector<double>* 		vecCellsEta = 0;
	std::vector<double>* 		vecCellsPhi = 0;
	std::vector<double>* 		SumPtPVvec = 0;
	std::vector<int>* 		countPVvec = 0;
	std::vector<double>* 		SumPtSVvec = 0;
	std::vector<int>*		countSVvec = 0;
	UInt_t				Event_Nr = 0;
	UInt_t				Run_Nr = 0;
	Float_t				averageNumberOfInteractions = 0;
	std::vector<double>*		mu_pt = 0;
	std::vector<double>*		mu_eta = 0;
	std::vector<double>*		mu_phi = 0;
	std::vector<double>*		mu_IsolationParam_ptcone20 = 0;
	std::vector<int>*		mu_charge = 0;
	int				NumberOfVertices = 0;
	std::vector<double>*   		jet_pt = 0;
	std::vector<double>*   		jet_eta = 0;
	std::vector<double>*		jet_phi = 0;
	std::vector<double>* 		prim_track_pt=0;
	std::vector<double>* 		prim_track_eta=0;
	std::vector<double>* 		prim_track_phi=0;
	std::vector<double>* 		pile_track_pt=0;
	std::vector<double>* 		pile_track_eta=0;
	std::vector<double>* 		pile_track_phi=0;
	std::vector<double>* 		all_track_pt=0;
	std::vector<double>* 		all_prim_track_pt=0;
	std::vector<double>* 		all_pile_track_pt=0;

	void setbranches(TTree *tree){
	tree->SetBranchAddress("Mainz_CellPt", &vecCellsPt); //vec.Pt()
	tree->SetBranchAddress("Mainz_CellEta", &vecCellsEta); //vec.Eta()
	tree->SetBranchAddress("Mainz_CellPhi", &vecCellsPhi); //vec.Phi()
	tree->SetBranchAddress("Mainz_Cell_sumPtOfAssociatedPrimaryTracks", &SumPtPVvec); //SumPtPV
	tree->SetBranchAddress("Mainz_Cell_numberOfAssociatedPrimaryTracks", &countPVvec); //countPV
	tree->SetBranchAddress("Mainz_Cell_sumPtOfAssociatedPileUpVertexTracks", &SumPtSVvec); //SumPtSV
	tree->SetBranchAddress("Mainz_Cell_numberOfAssociatedPileUpVertexTracks", &countSVvec); //countSV
	tree->SetBranchAddress("Event_Nr", &Event_Nr); //Event_Nr
	tree->SetBranchAddress("Run_Nr", &Run_Nr); //Run_Nr
	tree->SetBranchAddress("averageNumberOfInteractions", &averageNumberOfInteractions); //averageNumberOfInteractions
	tree->SetBranchAddress("mu_pt", &mu_pt); //mu_pt
	tree->SetBranchAddress("mu_eta", &mu_eta); //mu_eta
	tree->SetBranchAddress("mu_phi", &mu_phi); //mu_phi
	tree->SetBranchAddress("mu_IsolationParam_ptcone20", &mu_IsolationParam_ptcone20); //mu_IsolationParam_ptcone20
	tree->SetBranchAddress("mu_charge", &mu_charge); //mu_charge
	tree->SetBranchAddress("NumberOfVertices", &NumberOfVertices); //NumberOfVertices
	tree->SetBranchAddress("jet_pt", &jet_pt); //jet_pt
	tree->SetBranchAddress("jet_eta", &jet_eta); //jet_eta
	tree->SetBranchAddress("jet_phi", &jet_phi); //jet_phi
	tree->SetBranchAddress("prim_track_pt", &prim_track_pt);
	tree->SetBranchAddress("prim_track_eta",&prim_track_eta);
	tree->SetBranchAddress("prim_track_phi",&prim_track_phi);
	tree->SetBranchAddress("pile_track_pt",&pile_track_pt);
	tree->SetBranchAddress("pile_track_eta",&pile_track_eta);
	tree->SetBranchAddress("pile_track_phi",&pile_track_phi);
	tree->SetBranchAddress("all_track_pt",&all_track_pt);
	tree->SetBranchAddress("all_prim_track_pt",&all_prim_track_pt);
	tree->SetBranchAddress("all_pile_track_pt",&all_pile_track_pt);
	
	/// --- END ---
	
}	
