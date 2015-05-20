class EWQuickEvent {
	public:

		EWQuickEvent(std::vector<std::string> vecFilenames, std::string Tree_Name, int NumberOfEvents=-1) {
			m_tchain = new TChain(Tree_Name.c_str());
			for (unsigned int i=0; i<vecFilenames.size(); i++)
				m_tchain->Add(vecFilenames[i].c_str());
			cleanVariables();
			addBranches();
			m_actEventNumber = 0;
			m_NumberOfEvents = m_tchain->GetEntries();
			if (NumberOfEvents!=-1) m_NumberOfEvents = NumberOfEvents;
			std::cout<<"[EWQuickEvent] Number of Events loaded: "<<m_NumberOfEvents<<std::endl;
		}

		~EWQuickEvent() {
			delete m_tchain;
		}


		bool getNextEvent() {
			if (m_actEventNumber>=m_NumberOfEvents) {
				std::cout<<std::endl;
				return false;
			}
			if (m_actEventNumber==0) std::cout<<"[EWQuickEvent] Looping over Events "<<std::endl;
			if (TMath::Nint((m_actEventNumber*10.0)/(m_NumberOfEvents+0.0))!=TMath::Nint(((m_actEventNumber+1)*10.0)/(m_NumberOfEvents+0.0))) {
				std::cout<<" - "<<TMath::Nint((m_actEventNumber*10.0)/(m_NumberOfEvents+0.0))*10<<"% done"<<std::endl;
			}
			m_tchain->GetEvent(m_actEventNumber);
			m_actEventNumber++;
			return true;
		}

		void cleanVariables() {
		    trk_pt = 0;
			trk_eta = 0;
			trk_phi = 0;
			trk_d0 = 0;
			trk_z0 = 0;
			trk_nPix = 0;
			trk_SCT = 0;
			trk_TRT = 0;
			trk_theta_wrtPV = 0;
			trk_eta_atCalo2ndLayer = 0;
			trk_phi_atCalo2ndLayer = 0;
			trk_qoverp_wrtPV = 0;
			
			cl_lc_n = 0;
			cl_lc_pt = 0;
			cl_lc_eta = 0;
			cl_lc_phi = 0;
			
			mu_staco_n = 0;
			mu_staco_charge = 0;
			mu_staco_pt = 0;
			mu_staco_eta = 0;
			mu_staco_phi = 0;
			mu_staco_ptcone20 = 0;

			jet_AntiKt4LCTopo_n = 0;
			jet_AntiKt4LCTopo_pt = 0;
			jet_AntiKt4LCTopo_eta = 0;
			jet_AntiKt4LCTopo_phi = 0;
			el_medium = 0;

			vxp_n = 0;
			vxp_trk_n = 0;

		}

		void addBranches() {
		   m_tchain->SetBranchStatus("*", false);
		   m_tchain->SetBranchAddress("RunNumber", &RunNumber);
		   m_tchain->SetBranchAddress("lbn", &lbn);
		   m_tchain->SetBranchAddress("EventNumber", &EventNumber);
		   m_tchain->SetBranchAddress("averageIntPerXing", &averageIntPerXing);
		   
		   m_tchain->SetBranchAddress("trk_pt",		&trk_pt);
		   m_tchain->SetBranchAddress("trk_eta",	&trk_eta);
		   m_tchain->SetBranchAddress("trk_phi_wrtPV",	&trk_phi);
		   m_tchain->SetBranchAddress("trk_d0_wrtPV",	&trk_d0);
		   m_tchain->SetBranchAddress("trk_z0_wrtPV",	&trk_z0);
		   m_tchain->SetBranchAddress("trk_nPixHits",	&trk_nPix);
		   m_tchain->SetBranchAddress("trk_nSCTHits",	&trk_SCT);
		   m_tchain->SetBranchAddress("trk_nTRTHits",	&trk_TRT);
		   m_tchain->SetBranchAddress("trk_theta_wrtPV",	&trk_theta_wrtPV);
		   m_tchain->SetBranchAddress("trk_eta_atCalo2ndLayer",	&trk_eta_atCalo2ndLayer);
		   m_tchain->SetBranchAddress("trk_phi_atCalo2ndLayer",	&trk_phi_atCalo2ndLayer);
		   m_tchain->SetBranchAddress("trk_qoverp_wrtPV",	&trk_qoverp_wrtPV);
		   
		   m_tchain->SetBranchAddress("cl_lc_n",	&cl_lc_n);
		   m_tchain->SetBranchAddress("cl_lc_pt",	&cl_lc_pt);
		   m_tchain->SetBranchAddress("cl_lc_eta",	&cl_lc_eta);
		   m_tchain->SetBranchAddress("cl_lc_phi",	&cl_lc_phi);
		   
		   m_tchain->SetBranchAddress("mu_staco_n",	&mu_staco_n);
		   m_tchain->SetBranchAddress("mu_staco_charge",	&mu_staco_charge);
		   m_tchain->SetBranchAddress("mu_staco_pt",	&mu_staco_pt);
		   m_tchain->SetBranchAddress("mu_staco_eta",	&mu_staco_eta);
		   m_tchain->SetBranchAddress("mu_staco_phi",	&mu_staco_phi);
		   m_tchain->SetBranchAddress("mu_staco_ptcone20",	&mu_staco_ptcone20);
		
		   m_tchain->SetBranchAddress("jet_AntiKt4LCTopo_n",	&jet_AntiKt4LCTopo_n);
		   m_tchain->SetBranchAddress("jet_AntiKt4LCTopo_pt",	&jet_AntiKt4LCTopo_pt);
		   m_tchain->SetBranchAddress("jet_AntiKt4LCTopo_eta",	&jet_AntiKt4LCTopo_eta);
		   m_tchain->SetBranchAddress("jet_AntiKt4LCTopo_phi",	&jet_AntiKt4LCTopo_phi);
		   m_tchain->SetBranchAddress("el_medium",	&el_medium);

		   m_tchain->SetBranchAddress("vxp_n",	&vxp_n);
		   m_tchain->SetBranchAddress("vxp_trk_n",	&vxp_trk_n);

		}

	public:
		TChain *m_tchain;
		int m_actEventNumber;
		int m_NumberOfEvents;

		/// Event Information
		UInt_t			RunNumber;
		UInt_t			lbn;
		UInt_t			EventNumber;
		Float_t			averageIntPerXing;
		
		std::vector<float>		*trk_pt;
		std::vector<float>		*trk_eta;
		std::vector<float>		*trk_phi;
		std::vector<float>		*trk_d0;
		std::vector<float>		*trk_z0;
		std::vector<int>		*trk_nPix;
		std::vector<int>		*trk_SCT;
		std::vector<int>		*trk_TRT;
		std::vector<float>		*trk_theta_wrtPV;
		std::vector<float> 		*trk_eta_atCalo2ndLayer;
 		std::vector<float> 		*trk_phi_atCalo2ndLayer;
		std::vector<float>   	*trk_qoverp_wrtPV;
 		
		Int_t					cl_lc_n;
		std::vector<float>		*cl_lc_pt;
		std::vector<float>		*cl_lc_eta;
		std::vector<float>		*cl_lc_phi;
		
		Int_t					mu_staco_n;
		std::vector<float>		*mu_staco_charge;
		std::vector<float>		*mu_staco_pt;
		std::vector<float>		*mu_staco_eta;
		std::vector<float>		*mu_staco_phi;
		std::vector<float>		*mu_staco_ptcone20;

		Int_t           		jet_AntiKt4LCTopo_n;
		std::vector<float>   		*jet_AntiKt4LCTopo_pt;
		std::vector<float>   		*jet_AntiKt4LCTopo_eta;
		std::vector<float>		*jet_AntiKt4LCTopo_phi;
		std::vector<int>     		*el_medium;

		Int_t   		        vxp_n;
		std::vector<int>    		*vxp_trk_n;
};
