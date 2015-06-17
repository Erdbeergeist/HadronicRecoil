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
			
			minb_mapHist1D["PtRcluster05"] = new TH1F("Pt R Clusters 05","",100,0,2000);
			minb_mapHist1D["PtRtrack05"] = new TH1F("Pt R Tracks 05","",100,400,2000);
			minb_mapHist1D["PtRcluster10"] = new TH1F("Pt R Clusters 10","",100,0,2000);
			minb_mapHist1D["PtRtrack10"] = new TH1F("Pt R Tracks 10","",100,400,2000);
			minb_mapHist1D["PtRcluster15"] = new TH1F("Pt R Clusters 15","",100,0,2000);
			minb_mapHist1D["PtRtrack15"] = new TH1F("Pt R Tracks 15","",100,400,2000);
			minb_mapHist1D["PtRcluster20"] = new TH1F("Pt R Clusters 20","",100,0,2000);
			minb_mapHist1D["PtRtrack20"] = new TH1F("Pt R Tracks 20","",100,400,2000);
			minb_mapHist1D["PtRcluster25"] = new TH1F("Pt R Clusters 25","",100,0,2000);
			minb_mapHist1D["PtRtrack25"] = new TH1F("Pt R Tracks 25","",100,400,2000);
			minb_mapHist1D["PtRcluster30"] = new TH1F("Pt R Clusters 30","",100,0,2000);
			minb_mapHist1D["PtRtrack30"] = new TH1F("Pt R Tracks 30","",100,400,2000);
			minb_mapHist1D["PtRcluster40"] = new TH1F("Pt R Clusters 40","",100,0,2000);
			minb_mapHist1D["PtRtrack40"] = new TH1F("Pt R Tracks 40","",100,400,2000);
			
			//Sum of PT in delta R without the cluster itself
			minb_mapHist1D["PtRclusterwS05"] = new TH1F("Pt R Clusters wS 05","",100,0,2000);
			minb_mapHist1D["PtRclusterwS10"] = new TH1F("Pt R Clusters wS 10","",100,0,2000);
			minb_mapHist1D["PtRclusterwS15"] = new TH1F("Pt R Clusters wS 15","",100,0,2000);
			minb_mapHist1D["PtRclusterwS20"] = new TH1F("Pt R Clusters wS 20","",100,0,2000);
			minb_mapHist1D["PtRclusterwS25"] = new TH1F("Pt R Clusters wS 25","",100,0,2000);
			minb_mapHist1D["PtRclusterwS30"] = new TH1F("Pt R Clusters wS 30","",100,0,2000);
			minb_mapHist1D["PtRclusterwS40"] = new TH1F("Pt R Clusters wS 40","",100,0,2000);
			
			//Sum of PT in delta R for diffrent #Vertices
			minb_mapHist1D["PtRclusterNV10"] = new TH1F("Pt R Clusters #NVert 10","",100,0,2000);
			minb_mapHist1D["PtRclusterNV15"] = new TH1F("Pt R Clusters #NVert 15","",100,0,2000);
			minb_mapHist1D["PtRclusterNV20"] = new TH1F("Pt R Clusters #NVert 20","",100,0,2000);
			minb_mapHist1D["PtRclusterNV25"] = new TH1F("Pt R Clusters #NVert 25","",100,0,2000);
			minb_mapHist1D["PtRclusterNV35"] = new TH1F("Pt R Clusters #NVert 35","",100,0,2000);
			
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
		void FillRTrack(double pt,double eta){
			minb_mapHist1D["PtRtrack"]->Fill(pt);
			if(fabs(eta)<0.5) minb_mapHist1D["PtRtrack05"]->Fill(pt);
			else if (fabs(eta)<1) minb_mapHist1D["PtRtrack10"]->Fill(pt);
			else if (fabs(eta)<1.5) minb_mapHist1D["PtRtrack15"]->Fill(pt);
			else if (fabs(eta)<2) minb_mapHist1D["PtRtrack20"]->Fill(pt);
			else if (fabs(eta)<2.5)	minb_mapHist1D["PtRtrack25"]->Fill(pt);
			else if (fabs(eta)<3) minb_mapHist1D["PtRtrack30"]->Fill(pt);
			else if (fabs(eta)<4) minb_mapHist1D["PtRtrack40"]->Fill(pt);
			
			
		}
		void FillRCluster(double pt,double eta){
			minb_mapHist1D["PtRcluster"]->Fill(pt);
			if(fabs(eta)<0.5) minb_mapHist1D["PtRcluster05"]->Fill(pt);
			else if (fabs(eta)<1) minb_mapHist1D["PtRcluster10"]->Fill(pt);
			else if (fabs(eta)<1.5) minb_mapHist1D["PtRcluster15"]->Fill(pt);
			else if (fabs(eta)<2) minb_mapHist1D["PtRcluster20"]->Fill(pt);
			else if (fabs(eta)<2.5)	minb_mapHist1D["PtRcluster25"]->Fill(pt);
			else if (fabs(eta)<3) minb_mapHist1D["PtRcluster30"]->Fill(pt);
			else if (fabs(eta)<4) minb_mapHist1D["PtRcluster40"]->Fill(pt);
			
		}
		
		void FillRClusterVert(double pt,int numvert){
			minb_mapHist1D["PtRcluster"]->Fill(pt);
			if(numvert<10) minb_mapHist1D["PtRclusterNV10"]->Fill(pt);
			else if (numvert<15) minb_mapHist1D["PtRclusterNV15"]->Fill(pt);
			else if (numvert<20) minb_mapHist1D["PtRclusterNV20"]->Fill(pt);
			else if (numvert<25) minb_mapHist1D["PtRclusterNV25"]->Fill(pt);
			else if (numvert<35) minb_mapHist1D["PtRclusterNV35"]->Fill(pt);
			
		}
		
		void FillRwSCluster(double pt,double eta){
			minb_mapHist1D["PtRcluster"]->Fill(pt);
			if(fabs(eta)<0.5) minb_mapHist1D["PtRclusterwS05"]->Fill(pt);
			else if (fabs(eta)<1) minb_mapHist1D["PtRclusterwS10"]->Fill(pt);
			else if (fabs(eta)<1.5) minb_mapHist1D["PtRclusterwS15"]->Fill(pt);
			else if (fabs(eta)<2) minb_mapHist1D["PtRclusterwS20"]->Fill(pt);
			else if (fabs(eta)<2.5)	minb_mapHist1D["PtRclusterwS25"]->Fill(pt);
			else if (fabs(eta)<3) minb_mapHist1D["PtRclusterwS30"]->Fill(pt);
			else if (fabs(eta)<4) minb_mapHist1D["PtRclusterwS40"]->Fill(pt);
			
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
