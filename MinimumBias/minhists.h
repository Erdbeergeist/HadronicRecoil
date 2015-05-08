class Hists{
	public:
		Hists() {
			initHists();
			
		}
		///Initialize the Histograms
		void initHists() {
			///Number of Vertices and Interactions Histograms
			minb_mapHist1D["NoV"] = new TH1F("Number of Vertices","",100,-100,100);
			minb_mapHist1D["NInt"] = new TH1F("Average Number of Interactions","",100,-100,100);
			minb_mapHist1D["NoVPTs20"] = new TH1F("Number of Vertices s 20","",100,-100,100);
			minb_mapHist1D["NoVPTs10"] = new TH1F("Number of Vertices s 10","",100,-100,100);
			minb_mapHist1D["NIntPTs20"] = new TH1F("Average Number of Interactions s 20","",100,-100,100);
			minb_mapHist1D["NIntPTs10"] = new TH1F("Average Number of Interactions s 10","",100,-100,100);
			minb_mapHist1D["NoVPTs5"] = new TH1F("Number of Vertices s 5","",100,-100,100);
			minb_mapHist1D["NIntPTs5"] = new TH1F("Average Number of Interactions s 5","",100,-100,100);
			minb_mapHist1D["NoVPTs2"] = new TH1F("Number of Vertices s 2","",100,-100,100);
			minb_mapHist1D["NIntPTs2"] = new TH1F("Average Number of Interactions s 2","",100,-100,100);
			
			///Sum Track PT Histograms
			minb_mapHist1D["SumTPt"] = new TH1F("Sum of Track PT","",100,0,1000);
			minb_mapHist1D["SumTPts20"] = new TH1F("Sum of Track PT s 20","",100,0,1000);
			minb_mapHist1D["SumTPts10"] = new TH1F("Sum of Track PT s 10","",100,0,1000);
			minb_mapHist1D["SumTPts5"] = new TH1F("Sum of Track PT s 5","",100,0,1000);
			minb_mapHist1D["SumTPts2"] = new TH1F("Sum of Track PT s 2","",100,0,1000);
			
			///Sum Primary Track PT Histograms
			minb_mapHist1D["SumTPrimPt"] = new TH1F("Sum of Primary Track PT","",100,0,1000);
			minb_mapHist1D["SumTPrimPts20"] = new TH1F("Sum of Primary Track PT s 20","",100,0,1000);
			minb_mapHist1D["SumTPrimPts10"] = new TH1F("Sum of Primary Track PT s 10","",100,0,1000);
			minb_mapHist1D["SumTPrimPts5"] = new TH1F("Sum of Primary Track PT s 5","",100,0,1000);
			minb_mapHist1D["SumTPrimPts2"] = new TH1F("Sum of Primary Track PT s 2","",100,0,1000);
			
			///Sum Pile Up Track PT Histograms
			minb_mapHist1D["SumTPilePt"] = new TH1F("Sum of Pile Up Track PT","",100,0,1000);
			minb_mapHist1D["SumTPilePts20"] = new TH1F("Sum of Pile Up Track PT s 20","",100,0,1000);
			minb_mapHist1D["SumTPilePts10"] = new TH1F("Sum of Pile Up Track PT s 10","",100,0,1000);
			minb_mapHist1D["SumTPilePts5"] = new TH1F("Sum of Pile Up Track PT s 5","",100,0,1000);
			minb_mapHist1D["SumTPilePts2"] = new TH1F("Sum of Pile Up Track PT s 2","",100,0,1000);
			
			///Cluster PT Histograms
			minb_mapHist1D["noPrimA"] = new TH1F("PT without Primary Association","",100,0,500);
			minb_mapHist1D["withPrimA"] = new TH1F("PT with Primary Association","",50,0,500);
			
			///Association Histograms
			minb_mapHist1D["EtanoAsso"] = new TH1F("Eta tracks without Association","",100,-2.5,2.5);
			
			///Hadronic Recoil Histograms
			minb_mapHist1D["HadEta"] = new TH1F("Hadronic Recoil Eta","",100,-2.5,2.5);
			minb_mapHist1D["HadPhi"] = new TH1F("Hadronic Recoil Phi","",100,-3.5,3.5);
		
			///Energy and PT Histograms
			minb_mapHist1D["EoPT"] = new TH1F("E over PT","",100,0,100);
			minb_mapHist1D["EmPT"] = new TH1F("E minus PT","",100,0,100);
			
			
			///Number of Muons, PTZ, M(Z)
			minb_mapHist1D["nmu"] = new TH1F("Number of Muons","",20,0,20);
			minb_mapHist1D["ptz"] = new TH1F("PT of Z","",100,0,100);
			minb_mapHist1D["mz"] = new TH1F("Mass of Z ","",100,0,110);
			
			///2D Histograms
			//Association Histograms
			minb_mapHist2D["PhiEtaNoA"] = new TH2F("Phi vs Eta no Association","",100,-2.5,2.5,100,-3.5,3.5);
			minb_mapHist2D["PhiEtaA"] = new TH2F("Phi vs Eta with Association","",100,-2.5,2.5,100,-3.5,3.5);
			minb_mapHist2D["PhiEtaPrim"] = new TH2F("Phi vs Eta with Primary Association","",100,-2.5,2.5,100,-3.5,3.5);
			minb_mapHist2D["PhiEtaPile"] = new TH2F("Phi vs Eta with Pile Up Association","",100,-2.5,2.5,100,-3.5,3.5);
			
			//Angle vs PT Histograms
			minb_mapHist2D["EtavsPt"] = new TH2F("Eta vs Pt","",100,0,100,100,-2.5,2.5);
			minb_mapHist2D["EtavsPrimPt"] = new TH2F("Eta vs Pt with Primary Association","",100,0,100,100,-2.5,2.5);
			minb_mapHist2D["EtavsPilePt"] = new TH2F("Eta vs Pt with Pileup Association","",100,0,100,100,-2.5,2.5);
			
			//#Vertices vs PT Histogrmas
			minb_mapHist2D["NVvsPt"] = new TH2F("Number of Vertices vs PT","",100,0,100,50,0,50);
			
			///#Various vs ZPT
			minb_mapHist2D["EtavZPT"] = new TH2F("Eta vs ZPT","",100,0,100,100,-2.5,2.5);
			minb_mapHist2D["NVvZPT"] = new TH2F("Number of Vertices vs ZPT","",100,0,100,30,0,30);
			minb_mapHist2D["PTTvZPT"] = new TH2F("Track PT vs ZPT","",100,0,100,100,0,100);
		}
		///Fill the Historgrams
		void FillHists(int NumberOfVertices,int aNumberOfInter,vector<double> sumtpt,int cond=0) {
			///depending on the condition (cond) fill the correct Histograms
			///			cond = 0 --- no Condition for Track (or Z) PT
			///			cond = 1 --- ZPT > 10 <20
			///			cond = 2 --- ZPT >5 <10
			///			cond = 3 --- ZPT >2 <5
			///			cond = 4 --- ZPT <2 
			
				switch (cond){
					case 0:
						minb_mapHist1D["NoV"]->Fill(NumberOfVertices);
						minb_mapHist1D["NInt"]->Fill(aNumberOfInter);
						minb_mapHist1D["SumTPt"]->Fill(sumtpt[2]);
						minb_mapHist1D["SumTPrimPt"]->Fill(sumtpt[0]);
						minb_mapHist1D["SumTPilePt"]->Fill(sumtpt[1]);
						break;
					case 1:
						minb_mapHist1D["NoVPTs20"]->Fill(NumberOfVertices);
						minb_mapHist1D["NIntPTs20"]->Fill(aNumberOfInter);
						minb_mapHist1D["SumTPts20"]->Fill(sumtpt[2]);
						minb_mapHist1D["SumTPrimPts20"]->Fill(sumtpt[0]);
						minb_mapHist1D["SumTPilePts20"]->Fill(sumtpt[1]);
						break;
					case 2:
						minb_mapHist1D["NoVPTs10"]->Fill(NumberOfVertices);
						minb_mapHist1D["NIntPTs10"]->Fill(aNumberOfInter);
						minb_mapHist1D["SumTPts10"]->Fill(sumtpt[2]);
						minb_mapHist1D["SumTPrimPts10"]->Fill(sumtpt[0]);
						minb_mapHist1D["SumTPilePts10"]->Fill(sumtpt[1]);
						break;	
					case 3:
						minb_mapHist1D["NoVPTs5"]->Fill(NumberOfVertices);
						minb_mapHist1D["NIntPTs5"]->Fill(aNumberOfInter);
						minb_mapHist1D["SumTPts5"]->Fill(sumtpt[2]);
						minb_mapHist1D["SumTPrimPts5"]->Fill(sumtpt[0]);
						minb_mapHist1D["SumTPilePts5"]->Fill(sumtpt[1]);
						break;
					case 4:
						minb_mapHist1D["NoVPTs2"]->Fill(NumberOfVertices);
						minb_mapHist1D["NIntPTs2"]->Fill(aNumberOfInter);
						minb_mapHist1D["SumTPts2"]->Fill(sumtpt[2]);
						minb_mapHist1D["SumTPrimPts2"]->Fill(sumtpt[0]);
						minb_mapHist1D["SumTPilePts2"]->Fill(sumtpt[1]);
						break;
				}
		}
			
		///Fill Number of Muons, PTZ, M(Z)
		void FillZHists(int nmu,double ptz,double mz,int cond){
			switch (cond){
				case 0:
					minb_mapHist1D["nmu"]->Fill(nmu);
					break;
				case 1:
					minb_mapHist1D["ptz"]->Fill(ptz);
					minb_mapHist1D["mz"]->Fill(mz);
					minb_mapHist1D["EoPT"]->Fill(sqrt(1+pow(mz,2)/pow(ptz,2)));
					minb_mapHist1D["EmPT"]->Fill(sqrt(pow(ptz,2)+pow(mz,2))-ptz);
					break;
			}
		} 	
		///Fill 2D Z Histograms
		void Fill2DZHists(TLorentzVector &recoZ,int NumberOfVertices,TVector3 hadrec){
			minb_mapHist2D["EtavZPT"]->Fill(recoZ.Pt()/1000,recoZ.Eta());
			minb_mapHist2D["NVvZPT"]->Fill(recoZ.Pt()/1000,NumberOfVertices);
			minb_mapHist2D["PTTvZPT"]->Fill(recoZ.Pt()/1000,hadrec.Pt()/1000);
		}
		
		///Fill the 1D Association Histograms
		void FillAssoHists(double vecPt,int cond = 0) {
			///depending on condition (cond) fill the correct Histograms
			///			cond = 0 --- default, Cluster has not recorded a primary Track
			///			cond = 1 --- Custer has recorded a Primary Track
			switch (cond){
				case 0:
					minb_mapHist1D["noPrimA"]->Fill(vecPt);
					break;
				case 1:
					minb_mapHist1D["withPrimA"]->Fill(vecPt);
					break;
			}	
		}
		///Fill the 2D Angle Histograms
		void Fill2DHists(double veceta, double vecphi, double vecpt, int cond=0,int NumberofVertices=0) {
			///depending on the condition (cond) fill the correct Histograms
			///			cond = 0 --- no association
			///			cond = 1 --- with either prim. or pileup assiciated
			///			cond = 2 --- with primary only
			///			cond = 3 --- with pileup only 
			switch (cond){
				case 0:
					minb_mapHist2D["PhiEtaNoA"]->Fill(veceta,vecphi);
					minb_mapHist1D["EtanoAsso"]->Fill(veceta);
					break;
				case 1:
					minb_mapHist2D["PhiEtaA"]->Fill(veceta,vecphi);
					minb_mapHist2D["EtavsPt"]->Fill(vecpt,veceta);
					minb_mapHist2D["NVvsPt"]->Fill(vecpt,NumberOfVertices);
					break;					
				case 2:
					minb_mapHist2D["PhiEtaPrim"]->Fill(veceta,vecphi);
					minb_mapHist2D["EtavsPrimPt"]->Fill(vecpt,veceta);
					break;
				case 3:
					minb_mapHist2D["PhiEtaPile"]->Fill(veceta,vecphi);
					minb_mapHist2D["EtavsPilePt"]->Fill(vecpt,veceta);
					break;
					
			}
		}
		///Fill the Hadronic Recoil Histograms
		void FillHadrecHists(TVector3 hadrec){
			minb_mapHist1D["HadPhi"]->Fill(hadrec.Phi());
			minb_mapHist1D["HadEta"]->Fill(hadrec.Eta());
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
