class Hists{
	public:
		Hists() {
			initHists();
			
		}
		///Initialize the Histograms
		void initHists() {
			minb_mapHist1D["NumClwoTracks"] = new TH1F("Number of Clusters without Tracks","",100,0,100);
			minb_mapHist1D["PtRcluster"] = new TH1F("Pt R Clusters","",100,0,2000);
			minb_mapHist1D["PtRtrack"] = new TH1F("Pt R Tracks","",100,400,2000);
			minb_mapHist1D["ClusterwoTrack"] = new TH1F("Pt Cluster without Track","",100,0,8000);
			minb_mapHist1D["EtaClusterwoTrack"] = new TH1F("Eta Cluster without Track","",15,-4,4);
			///2D Histograms
			//Association Histograms
			//minb_mapHist2D["PhiEtaNoA"] = new TH2F("Phi vs Eta no Association","",100,-2.5,2.5,100,-3.5,3.5);
			//minb_mapHist2D["PhiEtaA"] = new TH2F("Phi vs Eta with Association","",100,-2.5,2.5,100,-3.5,3.5);
			//minb_mapHist2D["PhiEtaPrim"] = new TH2F("Phi vs Eta with Primary Association","",100,-2.5,2.5,100,-3.5,3.5);
			//minb_mapHist2D["PhiEtaPile"] = new TH2F("Phi vs Eta with Pile Up Association","",100,-2.5,2.5,100,-3.5,3.5);
			
			
		}
		void FillNumClwoTrack(int num){
			minb_mapHist1D["NumClwoTracks"]->Fill(num);
		}
		void FillRTrack(double pt){
			minb_mapHist1D["PtRtrack"]->Fill(pt);
		}
		void FillRCluster(double pt){
			minb_mapHist1D["PtRcluster"]->Fill(pt);
		}
		void FillClusternoTrack(double pt,double eta){	
			minb_mapHist1D["ClusterwoTrack"]->Fill(pt);
			minb_mapHist1D["EtaClusterwoTrack"]->Fill(eta);
		}
			 
		///Write the Histogramms to file
		void WriteFile(TFile *fileO){
			fileO->Write();
			fileO->Close();
		}
		
	private:
		map<string, TH1*>		minb_mapHist1D;
		map<string, TH2*>		minb_mapHist2D;
		
};
