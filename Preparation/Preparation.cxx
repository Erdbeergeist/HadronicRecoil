#include "./EWCommonIncludes.h"
#include "./EWQuickEvent.h"
#include "./Preparation_Functions.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

/// Global Variables
EWQuickEvent 							*m_event;
std::map<std::string, TH1F*>			mapHist1D;


/// Main Program
int main(int argc, char *argv[]) {
	if (argc<3) {
		std::cout<<"Usage: ./MiniExample MiniNTupleFile.root Out_file.root"<<std::endl<<std::endl;
		return 0;
	}
	std::string filename = argv[1];
	const char* output_filename = argv[2];
	
	TFile *file0 = new TFile(output_filename, "RECREATE");
	std::vector<double> all_track_pt;
	std::vector<double> all_track_eta;
	std::vector<double> all_track_phi;
	std::vector<double> all_prim_track_pt;
	std::vector<double> all_prim_track_eta;
	std::vector<double> all_prim_track_phi;
	std::vector<double> all_pile_track_pt;
	std::vector<double> all_pile_track_eta;
	std::vector<double> all_pile_track_phi;
	std::vector<double> prim_track_pt;
	std::vector<double> prim_track_eta;
	std::vector<double> prim_track_phi;
	std::vector<double> pile_track_pt;
	std::vector<double> pile_track_eta;
	std::vector<double> pile_track_phi;
	std::vector<double> noA_track_pt;
	std::vector<double> noA_track_eta;
	std::vector<double> noA_track_phi;
	std::vector<double> vecCellsPt; 
	std::vector<double> vecCellsEta;
	std::vector<double> vecCellsPhi;
	std::vector<double> SumPtPVvec;
	std::vector<int> countPVvec;
	std::vector<double> SumPtSVvec;
	std::vector<int> countSVvec;
	UInt_t		Event_Nr;
	UInt_t		Run_Nr;
	Float_t		averageNumberOfInteractions;
	std::vector<double>		mu_pt;
	std::vector<double>		mu_eta;
	std::vector<double>		mu_phi;
	std::vector<double>		mu_IsolationParam_ptcone20;
	std::vector<int>		mu_charge;
	int		NumberOfVertices;
	std::vector<double>   		jet_pt;
	std::vector<double>   		jet_eta;
	std::vector<double>		jet_phi;

	TTree *MCCtree 			= new TTree("MainzCaloCells", "Tree with MainzCaloCells");
	
	MCCtree->Branch("Mainz_CellPt", &vecCellsPt); //vec.Pt()
	MCCtree->Branch("Mainz_CellEta", &vecCellsEta); //vec.Eta()
	MCCtree->Branch("Mainz_CellPhi", &vecCellsPhi); //vec.Phi()
	MCCtree->Branch("Mainz_Cell_sumPtOfAssociatedPrimaryTracks", &SumPtPVvec); //SumPtPV
	MCCtree->Branch("Mainz_Cell_numberOfAssociatedPrimaryTracks", &countPVvec); //countPV
	MCCtree->Branch("Mainz_Cell_sumPtOfAssociatedPileUpVertexTracks", &SumPtSVvec); //SumPtSV
	MCCtree->Branch("Mainz_Cell_numberOfAssociatedPileUpVertexTracks", &countSVvec); //countSV
	MCCtree->Branch("Event_Nr", &Event_Nr); //Event_Nr
	MCCtree->Branch("Run_Nr", &Run_Nr); //Run_Nr
	MCCtree->Branch("averageNumberOfInteractions", &averageNumberOfInteractions); //averageNumberOfInteractions
	MCCtree->Branch("mu_pt", &mu_pt); //mu_pt
	MCCtree->Branch("mu_eta", &mu_eta); //mu_eta
	MCCtree->Branch("mu_phi", &mu_phi); //mu_phi
	MCCtree->Branch("mu_IsolationParam_ptcone20", &mu_IsolationParam_ptcone20); //mu_IsolationParam_ptcone20
	MCCtree->Branch("mu_charge", &mu_charge); //mu_charge
	MCCtree->Branch("NumberOfVertices", &NumberOfVertices); //NumberOfVertices
	MCCtree->Branch("jet_pt", &jet_pt); //jet_pt
	MCCtree->Branch("jet_eta", &jet_eta); //jet_eta
	MCCtree->Branch("jet_phi", &jet_phi); //jet_phi0
	MCCtree->Branch("prim_track_pt",&prim_track_pt);
	MCCtree->Branch("prim_track_eta",&prim_track_eta);
	MCCtree->Branch("prim_track_phi",&prim_track_phi);
	MCCtree->Branch("pile_track_pt",&pile_track_pt);
	MCCtree->Branch("pile_track_eta",&pile_track_eta);
	MCCtree->Branch("pile_track_phi",&pile_track_phi);
	MCCtree->Branch("noA_track_pt",&noA_track_pt);
	MCCtree->Branch("noA_track_eta",&noA_track_eta);
	MCCtree->Branch("noA_track_phi",&noA_track_phi);
	MCCtree->Branch("all_track_pt",&all_track_pt);
	MCCtree->Branch("all_track_eta",&all_track_eta);
	MCCtree->Branch("all_track_phi",&all_track_phi);
	MCCtree->Branch("all_prim_track_pt",&all_prim_track_pt);
	MCCtree->Branch("all_prim_track_eta",&all_prim_track_eta);
	MCCtree->Branch("all_prim_track_phi",&all_prim_track_phi);
	MCCtree->Branch("all_pile_track_pt",&all_pile_track_pt);
	MCCtree->Branch("all_pile_track_eta",&all_pile_track_eta);
	MCCtree->Branch("all_pile_track_phi",&all_pile_track_phi);
	
	std::vector<std::string> vec_Filenames;
	vec_Filenames.push_back(filename.c_str());

	m_event = new EWQuickEvent(vec_Filenames, "physics");
	
	
	/// Loop over all Events
	//m_event->m_actEventNumber = 3000; //#LM y 3000 ?
	while (m_event->getNextEvent()) {
		
		// One vector per event with all information
		std::vector<MainzCaloCell> vecCaloCells;

		FillMainzCaloCellVector(m_event, vecCaloCells);
		
		std::vector<TVector3> alltracks, allprimtracks,allpiletracks;
		
		GetAllTracks(m_event,&alltracks,&allprimtracks,&allpiletracks);
		
		// Store vector in five Branches of MCCtree
		StoreInTree(m_event, vecCaloCells, vecCellsPt, vecCellsEta, vecCellsPhi, SumPtPVvec, countPVvec, SumPtSVvec, countSVvec, Event_Nr, Run_Nr, averageNumberOfInteractions, mu_pt, mu_eta, mu_phi, mu_IsolationParam_ptcone20, mu_charge, NumberOfVertices, jet_pt, jet_eta, jet_phi, MCCtree,prim_track_pt,prim_track_eta,prim_track_phi,pile_track_pt,pile_track_eta,pile_track_phi,alltracks,all_track_pt,all_track_eta,all_track_phi,noA_track_pt,noA_track_eta,noA_track_phi,allprimtracks,all_prim_track_pt,all_prim_track_eta,all_prim_track_phi,allpiletracks,all_pile_track_pt,all_pile_track_phi,all_pile_track_phi);
		
				
	}

	delete m_event;

	/// Saving Results
	
	MCCtree->Print();
	
	file0->Write();

	file0->Close();
	return 0;
}
