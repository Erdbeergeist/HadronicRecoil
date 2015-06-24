class Hists{
	public:
		Hists() {
			initHists();
			
			
		}
		///Initialize the Histograms
		void initHists() {
			minb_mapHist1D["NumClwoTracks"] = new TH1F("Number of Clusters without Tracks","",100,0,100);
			minb_mapHist1D["ClusterwoTrack"] = new TH1F("Pt Cluster without Track","",100,0,8000);
			minb_mapHist1D["EtaClusterwoTrack"] = new TH1F("Eta Cluster without Track","",15,-4,4);
			minb_mapHist1D["PtRcluster"] = new TH1F("Pt R Clusters","",100,0,2000);
			minb_mapHist1D["PtRtrack"] = new TH1F("Pt R Tracks","",100,400,2000);
						
			minb_mapHist1D["Ptcluster"] = new TH1F("Pt  Clusters ","",100,0,2000);
			minb_mapHist1D["Ptcluster05"] = new TH1F("Pt  Clusters  05","",100,0,2000);
			minb_mapHist1D["Ptcluster10"] = new TH1F("Pt  Clusters  10","",100,0,2000);
			minb_mapHist1D["Ptcluster15"] = new TH1F("Pt  Clusters  15","",100,0,2000);
			minb_mapHist1D["Ptcluster20"] = new TH1F("Pt  Clusters  20","",100,0,2000);
			minb_mapHist1D["Ptcluster25"] = new TH1F("Pt  Clusters  25","",100,0,2000);
			minb_mapHist1D["Ptcluster30"] = new TH1F("Pt  Clusters  30","",100,0,2000);
			minb_mapHist1D["Ptcluster40"] = new TH1F("Pt  Clusters  40","",100,0,2000);
			
			minb_mapHist1D["PtclusterNV"] = new TH1F("Pt  Clusters #NV","",100,0,2000);
			minb_mapHist1D["PtclusterNV5"] = new TH1F("Pt  Clusters  #NV 5","",100,0,2000);
			minb_mapHist1D["PtclusterNV10"] = new TH1F("Pt  Clusters  #NV 10","",100,0,2000);
			minb_mapHist1D["PtclusterNV15"] = new TH1F("Pt  Clusters  #NV 15","",100,0,2000);
			minb_mapHist1D["PtclusterNV20"] = new TH1F("Pt  Clusters  #NV 20","",100,0,2000);
			minb_mapHist1D["PtclusterNV25"] = new TH1F("Pt  Clusters  #NV 25","",100,0,2000);
			minb_mapHist1D["PtclusterNV30"] = new TH1F("Pt  Clusters  #NV 30","",100,0,2000);
						
			minb_mapHist1D["PtRcluster05"] = new TH1F("Pt R Clusters 05","",100,0,2000);
			minb_mapHist1D["PtRcluster10"] = new TH1F("Pt R Clusters 10","",100,0,2000);
			minb_mapHist1D["PtRcluster15"] = new TH1F("Pt R Clusters 15","",100,0,2000);
			minb_mapHist1D["PtRcluster20"] = new TH1F("Pt R Clusters 20","",100,0,2000);
			minb_mapHist1D["PtRcluster25"] = new TH1F("Pt R Clusters 25","",100,0,2000);
			minb_mapHist1D["PtRcluster30"] = new TH1F("Pt R Clusters 30","",100,0,2000);
			minb_mapHist1D["PtRcluster40"] = new TH1F("Pt R Clusters 40","",100,0,2000);
			
			minb_mapHist1D["PtRtrack05"] = new TH1F("Pt R Tracks 05","",100,400,2000);
			minb_mapHist1D["PtRtrack10"] = new TH1F("Pt R Tracks 10","",100,400,2000);
			minb_mapHist1D["PtRtrack15"] = new TH1F("Pt R Tracks 15","",100,400,2000);
			minb_mapHist1D["PtRtrack20"] = new TH1F("Pt R Tracks 20","",100,400,2000);
			minb_mapHist1D["PtRtrack25"] = new TH1F("Pt R Tracks 25","",100,400,2000);
			minb_mapHist1D["PtRtrack30"] = new TH1F("Pt R Tracks 30","",100,400,2000);
			minb_mapHist1D["PtRtrack40"] = new TH1F("Pt R Tracks 40","",100,400,2000);
			
			minb_mapHist1D["PtRclusterPrim"] = new TH1F("Pt R Clusters Prim","",100,0,2000);
			minb_mapHist1D["PtRclusterPrim05"] = new TH1F("Pt R Clusters Prim 05","",100,0,2000);
			minb_mapHist1D["PtRclusterPrim10"] = new TH1F("Pt R Clusters Prim 10","",100,0,2000);
			minb_mapHist1D["PtRclusterPrim15"] = new TH1F("Pt R Clusters Prim 15","",100,0,2000);
			minb_mapHist1D["PtRclusterPrim20"] = new TH1F("Pt R Clusters Prim 20","",100,0,2000);
			minb_mapHist1D["PtRclusterPrim25"] = new TH1F("Pt R Clusters Prim 25","",100,0,2000);
			minb_mapHist1D["PtRclusterPrim30"] = new TH1F("Pt R Clusters Prim 30","",100,0,2000);
			minb_mapHist1D["PtRclusterPrim40"] = new TH1F("Pt R Clusters Prim 40","",100,0,2000);
			
			minb_mapHist1D["PtRclusterPile"] = new TH1F("Pt R Clusters Pile ","",100,0,2000);
			minb_mapHist1D["PtRclusterPile05"] = new TH1F("Pt R Clusters Pile 05","",100,0,2000);
			minb_mapHist1D["PtRclusterPile10"] = new TH1F("Pt R Clusters Pile 10","",100,0,2000);
			minb_mapHist1D["PtRclusterPile15"] = new TH1F("Pt R Clusters Pile 15","",100,0,2000);
			minb_mapHist1D["PtRclusterPile20"] = new TH1F("Pt R Clusters Pile 20","",100,0,2000);
			minb_mapHist1D["PtRclusterPile25"] = new TH1F("Pt R Clusters Pile 25","",100,0,2000);
			minb_mapHist1D["PtRclusterPile30"] = new TH1F("Pt R Clusters Pile 30","",100,0,2000);
			minb_mapHist1D["PtRclusterPile40"] = new TH1F("Pt R Clusters Pile 40","",100,0,2000);
			
			minb_mapHist1D["PtRclusterNV5"] = new TH1F("Pt R Clusters #NVert 5","",100,0,2000);
			minb_mapHist1D["PtRclusterNV10"] = new TH1F("Pt R Clusters #NVert 10","",100,0,2000);
			minb_mapHist1D["PtRclusterNV15"] = new TH1F("Pt R Clusters #NVert 15","",100,0,2000);
			minb_mapHist1D["PtRclusterNV20"] = new TH1F("Pt R Clusters #NVert 20","",100,0,2000);
			minb_mapHist1D["PtRclusterNV25"] = new TH1F("Pt R Clusters #NVert 25","",100,0,2000);
			minb_mapHist1D["PtRclusterNV30"] = new TH1F("Pt R Clusters #NVert 30","",100,0,2000);
			
			initialisenestedHistograms();
			
		}
		
		void initialisenestedHistograms(){
			array<double,6> EtaLimits = {5,10,15,20,25,40};
			array<int,6> NumberofVerticesLimits = {5,10,15,20,25,30};
			array<int,5> PTLimits = {500,600,800,1200,2000};
			
			for (int i=0;i<EtaLimits.size();i++){
				for (int j = 0;j<NumberofVerticesLimits.size();j++){
					for (int k=0;k<PTLimits.size();k++){
						char* name = GetNestedHistogramName(EtaLimits[i],NumberofVerticesLimits[j],PTLimits[k]);
						
						int lowerBound;
						if (k==0) lowerBound = 0;
						else lowerBound = PTLimits[k-1];
						
						minb_mapHist1D[name] = new TH1F(name,"",100,lowerBound,PTLimits[k]);
					}
				}
			}
			/////!!!!!GetNestedRHistogramName!!!!! Initialises the same as above but for Delta R Histograms
			for (int i=0;i<EtaLimits.size();i++){
				for (int j = 0;j<NumberofVerticesLimits.size();j++){
					for (int k=0;k<PTLimits.size();k++){
						char* name = GetNestedRHistogramName(EtaLimits[i],NumberofVerticesLimits[j],PTLimits[k]);
						int lowerBound;
						if (k==0) lowerBound = 0;
						else lowerBound = PTLimits[k-1];
						minb_mapHist1D[name] = new TH1F(name,"",100,lowerBound,PTLimits[k]);
					}
				}
			}
			
			
		}
		
		void FillNestedHistograms(double pt, double eta, int NumberofVertices){
			array<double,6> EtaLimits = {5,10,15,20,25,40};
			array<int,6> NumberofVerticesLimits = {5,10,15,20,25,30};
			array<int,5> PTLimits = {500,600,800,1200,2000};
			//cout<<"PT:"<<pt<<"\t ETA:"<<eta<<"\t NV:"<<NumberofVertices<<endl;
			for (int i=0;i<EtaLimits.size();i++){
				double help = EtaLimits[i]/10;
				//cout<<help<<endl;
				if(eta<EtaLimits[i]/10){
					for (int j=0;j<NumberofVerticesLimits.size();j++){
						if(NumberofVertices<NumberofVerticesLimits[j]){
							for (int k=0;k<PTLimits.size();k++){
								if(pt<PTLimits[k]){
									char* name = GetNestedHistogramName(EtaLimits[i],NumberofVerticesLimits[j],PTLimits[k]);
									//cout<<name<<endl;
									minb_mapHist1D[name]->Fill(pt);
									return;
								}	 
							}
						}	
					}	
				}
			}
		
		}
		
		////!!!same as above but for Delta R Histograms
		void FillNestedRHistograms(double pt, double eta, int NumberofVertices){
			array<double,6> EtaLimits = {5,10,15,20,25,40};
			array<int,6> NumberofVerticesLimits = {5,10,15,20,25,30};
			array<int,5> PTLimits = {500,600,800,1200,2000};
			//cout<<"PT:"<<pt<<"\t ETA:"<<eta<<"\t NV:"<<NumberofVertices<<endl;
			for (int i=0;i<EtaLimits.size();i++){
				if(eta<EtaLimits[i]/10){
					for (int j=0;j<NumberofVerticesLimits.size();j++){
						if(NumberofVertices<NumberofVerticesLimits[j]){
							for (int k=0;k<PTLimits.size();k++){
								if(pt<PTLimits[k]){
									char* name = GetNestedRHistogramName(EtaLimits[i],NumberofVerticesLimits[j],PTLimits[k]);
									//cout<<name<<endl;
									minb_mapHist1D[name]->Fill(pt);
									return;
								}	 
							}
						}	
					}	
				}
			}
		
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
		
		void FillCluster(double pt,double eta){
			minb_mapHist1D["Ptcluster"]->Fill(pt);
			
			if(fabs(eta)<0.5) minb_mapHist1D["Ptcluster05"]->Fill(pt);
			else if (fabs(eta)<1) minb_mapHist1D["Ptcluster10"]->Fill(pt);
			else if (fabs(eta)<1.5) minb_mapHist1D["Ptcluster15"]->Fill(pt);
			else if (fabs(eta)<2) minb_mapHist1D["Ptcluster20"]->Fill(pt);
			else if (fabs(eta)<2.5)	minb_mapHist1D["Ptcluster25"]->Fill(pt);
			else if (fabs(eta)<3) minb_mapHist1D["Ptcluster30"]->Fill(pt);
			else if (fabs(eta)<4) minb_mapHist1D["Ptcluster40"]->Fill(pt);
			
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
				
		void FillRClusterPrim(double pt,double eta){
			minb_mapHist1D["PtRclusterPrim"]->Fill(pt);
			if(fabs(eta)<0.5) minb_mapHist1D["PtRclusterPrim05"]->Fill(pt);
			else if (fabs(eta)<1) minb_mapHist1D["PtRclusterPrim10"]->Fill(pt);
			else if (fabs(eta)<1.5) minb_mapHist1D["PtRclusterPrim15"]->Fill(pt);
			else if (fabs(eta)<2) minb_mapHist1D["PtRclusterPrim20"]->Fill(pt);
			else if (fabs(eta)<2.5)	minb_mapHist1D["PtRclusterPrim25"]->Fill(pt);
			else if (fabs(eta)<3) minb_mapHist1D["PtRclusterPrim30"]->Fill(pt);
			else if (fabs(eta)<4) minb_mapHist1D["PtRclusterPrim40"]->Fill(pt);
		}
		
		void FillRClusterPile(double pt,double eta){
			minb_mapHist1D["PtRclusterPile"]->Fill(pt);
			if(fabs(eta)<0.5) minb_mapHist1D["PtRclusterPile05"]->Fill(pt);
			else if (fabs(eta)<1) minb_mapHist1D["PtRclusterPile10"]->Fill(pt);
			else if (fabs(eta)<1.5) minb_mapHist1D["PtRclusterPile15"]->Fill(pt);
			else if (fabs(eta)<2) minb_mapHist1D["PtRclusterPile20"]->Fill(pt);
			else if (fabs(eta)<2.5)	minb_mapHist1D["PtRclusterPile25"]->Fill(pt);
			else if (fabs(eta)<3) minb_mapHist1D["PtRclusterPile30"]->Fill(pt);
			else if (fabs(eta)<4) minb_mapHist1D["PtRclusterPile40"]->Fill(pt);
		}	
		
		void FillRClusterVert(double pt,int numvert){
			
			if(numvert<5) minb_mapHist1D["PtRclusterNV5"]->Fill(pt);
			else if(numvert<10) minb_mapHist1D["PtRclusterNV10"]->Fill(pt);
			else if (numvert<15) minb_mapHist1D["PtRclusterNV15"]->Fill(pt);
			else if (numvert<20) minb_mapHist1D["PtRclusterNV20"]->Fill(pt);
			else if (numvert<25) minb_mapHist1D["PtRclusterNV25"]->Fill(pt);
			else if (numvert<35) minb_mapHist1D["PtRclusterNV30"]->Fill(pt);
			
		}
		
		void FillClusterVert(double pt,int numvert){
		
			minb_mapHist1D["PtclusterNV"]->Fill(pt);
			if(numvert<5) minb_mapHist1D["PtclusterNV5"]->Fill(pt);
			else if(numvert<10) minb_mapHist1D["PtclusterNV10"]->Fill(pt);
			else if (numvert<15) minb_mapHist1D["PtclusterNV15"]->Fill(pt);
			else if (numvert<20) minb_mapHist1D["PtclusterNV20"]->Fill(pt);
			else if (numvert<25) minb_mapHist1D["PtclusterNV25"]->Fill(pt);
			else if (numvert<30) minb_mapHist1D["PtclusterNV30"]->Fill(pt);
			
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
		
		char* GetNestedRHistogramName(int EtaLimit,int NumberofVerticesLimit,int PTLimit){
			string temp = "SumPTREta"+to_string(static_cast<long long int>(EtaLimit))+"NV"+to_string(static_cast<long long int>(NumberofVerticesLimit))+"PT"+to_string(static_cast<long long int>(PTLimit));
			char* name = new char [temp.length()+1];
			strcpy(name,temp.c_str());
			return name;

		}
		
		char* GetNestedHistogramName(int EtaLimit,int NumberofVerticesLimit,int PTLimit){
			string temp = "SumPTEta"+to_string(static_cast<long long int>(EtaLimit))+"NV"+to_string(static_cast<long long int>(NumberofVerticesLimit))+"PT"+to_string(static_cast<long long int>(PTLimit));
			char* name = new char [temp.length()+1];
			strcpy(name,temp.c_str());
			return name;

		}
};

