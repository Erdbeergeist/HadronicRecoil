///Class to handle making the Plots and saving them to File 
class makeHists{
	public:
		makeHists() {
			initHists();
		}
		///Initialize the Histograms
		void initHists() {
			
			///1D Historgrams
			hadrec_mapHist1D["U_x"] = new TH1F("Ux","",100,-100,100);
			hadrec_mapHist1D["U_y"] = new TH1F("Uy","",100,-100,100);
			hadrec_mapHist1D["U_par"] = new TH1F("Upar","",100,-100,100);
			hadrec_mapHist1D["U_orth"] = new TH1F("Uorth","",100,-100,100);
			hadrec_mapHist1D["U_par+ptZ"] = new TH1F("Upar + ptZ","",100,-100,100);
			///2D Histograms
			hadrec_mapHist2D["U_par+ptZ 2"] = new TH2F("Upar + ptZ 2","",100,0,100,100,-100,100);
			hadrec_mapHist2D["U_par+ptZ _ ptZ 2"] = new TH2F("Upar + ptZ _ ptZ 2","",100,0,100,100,-100,100);
			hadrec_mapHist2D["resc U_par+ptZ _ ptZ 2"] = new TH2F("resc Upar + ptZ _ ptZ 2","",100,0,100,100,-100,100);
			hadrec_mapHist2D["resc U_par+ptZ 2"] = new TH2F("resc Upar + ptZ 2","",100,0,100,100,-100,100);

		}
		///Fill the Historgrams
		void FillHists(TVector3 HadronicRecoil, TVector3 Zvec) {
			double dphi = HadronicRecoil.DeltaPhi(Zvec)-M_PI;
			hadrec_mapHist1D["U_x"]->Fill(HadronicRecoil.Pt()/1000 *sin(HadronicRecoil.Phi()));
			hadrec_mapHist1D["U_y"]->Fill(HadronicRecoil.Pt()/1000 *cos(HadronicRecoil.Phi()));
			hadrec_mapHist1D["U_par"]->Fill(HadronicRecoil.Pt()/1000 * cos(dphi));
			hadrec_mapHist1D["U_orth"]->Fill(HadronicRecoil.Pt()/1000 * sin(dphi));
			hadrec_mapHist1D["U_par+ptZ"]->Fill(HadronicRecoil.Pt()/1000 * cos(dphi)-Zvec.Pt()/1000);
			pair <double, double> data (Zvec.Pt()/1000,HadronicRecoil.Pt()/1000 * cos(dphi));
			rdata.push_back(data);
			NVert.push_back(NumberOfVertices);
			}
		
		///Fill 2D Historgrams
		void Fill2DHists(TVector3 HadronicRecoil, TVector3 Zvec, int NumberOfVertices) {
			double dphi = HadronicRecoil.DeltaPhi(Zvec)-M_PI;
			hadrec_mapHist2D["U_par+ptZ 2"]->Fill(NumberOfVertices,HadronicRecoil.Pt()/1000 * cos(dphi)-Zvec.Pt()/1000);
			hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->Fill(Zvec.Pt()/1000,HadronicRecoil.Pt()/1000 * cos(dphi)-Zvec.Pt()/1000);
		}
		
		void Fill2DHistsresc() {
			int h=0;
			getscalefac();
			for (int i=0;i<NVert.size();i++){
				for (int j=0;j<scalefac.size();j++){///find the right scaling factor for ZPT
					if (rdata[i].first<=(j+1)*xbwidth) {
						h=j;
						//cout<<Zptm[h]<<"\t"<<rdata[i].first<<endl;
						break;
					}
				}
				hadrec_mapHist2D["resc U_par+ptZ _ ptZ 2"]->Fill(rdata[i].first,scalefac[h]*(rdata[i].second) - rdata[i].first);
				hadrec_mapHist2D["resc U_par+ptZ 2"]->Fill(NVert[i],scalefac[h]*(rdata[i].second) - rdata[i].first);
			}
		}
		
		///Make bias and mean Plots
		void meanHists(int method =0,string histname="U_par+ptZ _ ptZ 2",char const *name ="Bias vs ptZ") {
			
			if (method == 0){
				int nx,ny;
				double cutter=0;///Minimum amount of content in Bins necessary in Bins for the Program to actually do the Fit
				
				nx = hadrec_mapHist2D[histname]->GetXaxis()->GetNbins();
				ny = hadrec_mapHist2D[histname]->GetYaxis()->GetNbins();
				
				///Create a Histogram for the resolution sigma against the NumberOfVertices
				TF1 *ygaus = new TF1("ygaus","gaus");
				TH1F *temp = new TH1F("tmp","tmp",ny,hadrec_mapHist2D[histname]->GetXaxis()->GetXmin(),hadrec_mapHist2D[histname]->GetXaxis()->GetXmax());
				TH1F *res = new TH1F(name,name,ny,hadrec_mapHist2D[histname]->GetXaxis()->GetXmin(),hadrec_mapHist2D[histname]->GetXaxis()->GetXmax());
				///For each silce of hist create a temporary Historgram and Fit it with a gaussian
				///Sigma is then used to create the Resolution Histogram
				for (int x=1;x<=nx;x++){
					for (int y=1;y<=ny;y++){
						temp->SetBinContent(y,hadrec_mapHist2D[histname]->GetBinContent(x,y));
						cutter+=hadrec_mapHist2D[histname]->GetBinContent(x,y);
					}
					if (abs(cutter)>0){ ///dont try to fit empty Histograms
						temp->Fit(ygaus,"Q");
						double mean = ygaus->GetParameter(1);
						res->SetBinContent(x, mean);///Set the bins of the new Histogram
						res->SetBinError(x, ygaus->GetParError(1));
												
					}	
				cutter =0;
				}
				delete(temp);
			}
			else if(method ==1){
				hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->FitSlicesY();
				TH1D *hist_1 = (TH1D*)gDirectory->Get("Upar + ptZ _ ptZ 2_1");
				hist_1->GetYaxis()->SetRange(-30,30);
			}
				
		}
		
		void tryit(){
			int ny = hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->GetYaxis()->GetNbins();
			TH1F *temp = new TH1F("tmp","tmp",ny,hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->GetXaxis()->GetXmin(),hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->GetXaxis()->GetXmax());
			TH1D *tempP = new TH1D("tmpP","tmpP",ny,hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->GetXaxis()->GetXmin(),hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->GetXaxis()->GetXmax());

			
			for (int y =0;y<ny;y++) {
				temp->SetBinContent(y,hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->GetBinContent(1,y));
			}
			tempP = hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->ProjectionY("",1,1);
		
		}
				
		///Make bias and mean Plots
		void resHists(int method =0,string histname="U_par+ptZ _ ptZ 2",char const *name ="Resolution vs ptZ") {
			
			if (method == 0){
				int nx,ny;
				double cutter=0;///Minimum amount of content in Bins necessary in Bins for the Program to actually do the Fit
				
				nx = hadrec_mapHist2D[histname]->GetXaxis()->GetNbins();
				ny = hadrec_mapHist2D[histname]->GetYaxis()->GetNbins();
				
				///Create a Histogram for the resolution sigma against the NumberOfVertices
				TF1 *ygaus = new TF1("ygaus","gaus");
				TH1F *temp = new TH1F("tmp","tmp",ny,hadrec_mapHist2D[histname]->GetXaxis()->GetXmin(),hadrec_mapHist2D[histname]->GetXaxis()->GetXmax());
				TH1F *res = new TH1F(name,name,ny,hadrec_mapHist2D[histname]->GetXaxis()->GetXmin(),hadrec_mapHist2D[histname]->GetXaxis()->GetXmax());
				///For each silce of hist create a temporary Historgram and Fit it with a gaussian
				///Sigma is then used to create the Resolution Histogram
				for (int x=1;x<=nx;x++){
					for (int y=1;y<=ny;y++){
						temp->SetBinContent(y,hadrec_mapHist2D[histname]->GetBinContent(x,y));
						cutter+=hadrec_mapHist2D[histname]->GetBinContent(x,y);
					}
					if (abs(cutter)>0){ ///dont try to fit empty Histograms
						temp->Fit(ygaus,"Q");
						double mean = ygaus->GetParameter(2);
						res->SetBinContent(x, mean);///Set the bins of the new Histogram
						res->SetBinError(x, ygaus->GetParError(2));
												
					}	
				cutter =0;
				}
				delete(temp);
			}

		}
		void WriteFile(TFile *fileO){
			fileO->Write();
			fileO->Close();
		}

	private:
		map<string, TH1*>		hadrec_mapHist1D;
		map<string, TH2*>		hadrec_mapHist2D;
		vector<pair <double,double> > rdata;
		double xbwidth;
		pair <int,int> nxny;
		vector<double> UparptZ;
		vector<double> Zptm;
		vector<double> scalefac;
		vector<int> NVert;
		
		void getscalefac(){
			int nx,ny;
			char const *name ="temp";	
			nx = hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->GetXaxis()->GetNbins();
			ny = hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->GetYaxis()->GetNbins();
			nxny.first=nx;
			nxny.second=ny;
			xbwidth=(hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->GetXaxis()->GetXmax()/hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->GetXaxis()->GetNbins());
			TF1 *ygaus = new TF1("ygaus","gaus");
			//TH1F *temp = new TH1F("tmp","tmp",ny,hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->GetXaxis()->GetXmin(),hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->GetXaxis()->GetXmax());
			double help=0;
			///For each silce of hist create a temporary Historgram and Fit it with a gaussian
			for (int x=1;x<=nx;x++){
				for (int y=1;y<=ny;y++){
					//temp->SetBinContent(y,hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->GetBinContent(x,y));
					help+=hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->GetBinContent(x,y);
				}
				//temp->Fit(ygaus,"Q");
				//double mean = ygaus->GetParameter(1);
				double mean = hadrec_mapHist2D["U_par+ptZ _ ptZ 2"]->ProjectionY("",x,x)->GetMean();
				UparptZ.push_back(mean);
				//cout<<mean<<endl;
				Zptm.push_back(x*xbwidth-xbwidth/2);
				scalefac.push_back(1/((UparptZ[x-1]/Zptm[x-1])+1));	
				//cout<<help/ny<<"\t"<<mean<<endl;
										
			
			}
		}
		
};		
