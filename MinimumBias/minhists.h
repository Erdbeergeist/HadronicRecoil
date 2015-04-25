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
			minb_mapHist1D["NoVPTZg20"] = new TH1F("Number of Vertices ptZ g 20","",100,-100,100);
			minb_mapHist1D["NIntPTZg20"] = new TH1F("Average Number of Interactions ptZ g 20","",100,-100,100);
			minb_mapHist1D["NoVPTZs5"] = new TH1F("Number of Vertices ptZ s 5","",100,-100,100);
			minb_mapHist1D["NIntPTZs5"] = new TH1F("Average Number of Interactions ptZ s 5","",100,-100,100);
			minb_mapHist1D["NoVPTZs2"] = new TH1F("Number of Vertices ptZ s 2","",100,-100,100);
			minb_mapHist1D["NIntPTZs2"] = new TH1F("Average Number of Interactions ptZ s 2","",100,-100,100);
			
			///Sum Track PT Histograms
			minb_mapHist1D["SumTPt"] = new TH1F("Sum of Track PT","",100,0,1000);
			minb_mapHist1D["SumTPtZPTg20"] = new TH1F("Sum of Track PT ptZ g 20","",100,0,1000);
			minb_mapHist1D["SumTPtZPTs5"] = new TH1F("Sum of Track PT ptZ s 5","",100,0,1000);
			minb_mapHist1D["SumTPtZPTs2"] = new TH1F("Sum of Track PT ptZ s 2","",100,0,1000);
			
			///Sum Primary Track PT Histograms
			minb_mapHist1D["SumTPrimPt"] = new TH1F("Sum of Primary Track PT","",100,0,1000);
			minb_mapHist1D["SumTPrimPtZPTg20"] = new TH1F("Sum of Primary Track PT ptZ g 20","",100,0,1000);
			minb_mapHist1D["SumTPrimPtZPTs5"] = new TH1F("Sum of Primary Track PT ptZ s 5","",100,0,1000);
			minb_mapHist1D["SumTPrimPtZPTs2"] = new TH1F("Sum of Primary Track PT ptZ s 2","",100,0,1000);
			
			///Sum Pile Up Track PT Histograms
			minb_mapHist1D["SumTPilePt"] = new TH1F("Sum of Pile Up Track PT","",100,0,1000);
			minb_mapHist1D["SumTPilePtZPTg20"] = new TH1F("Sum of Pile Up Track PT ptZ g 20","",100,0,1000);
			minb_mapHist1D["SumTPilePtZPTs5"] = new TH1F("Sum of Pile Up Track PT ptZ s 5","",100,0,1000);
			minb_mapHist1D["SumTPilePtZPTs2"] = new TH1F("Sum of Pile Up Track PT ptZ s 2","",100,0,1000);
			
			///Cluster PT Histograms
			minb_mapHist1D["noPrimA"] = new TH1F("PT without Primary Association","",100,0,100);
			minb_mapHist1D["withPrimA"] = new TH1F("PT with Primary Association","",100,0,100);
			
			///2D Histograms
			//Association Histograms
			minb_mapHist2D["PhiEtaNoA"] = new TH2F("Phi vs Eta no Association","",100,-2.5,2.5,100,-3.5,3.5);
			minb_mapHist2D["PhiEtaA"] = new TH2F("Phi vs Eta with Association","",100,-2.5,2.5,100,-3.5,3.5);
			minb_mapHist2D["PhiEtaPrim"] = new TH2F("Phi vs Eta with Primary Association","",100,-2.5,2.5,100,-3.5,3.5);
			minb_mapHist2D["PhiEtaPile"] = new TH2F("Phi vs Eta with Pile Up Association","",100,-2.5,2.5,100,-3.5,3.5);
			
			//Angle vs PT Histograms
			minb_mapHist2D["EtavsPt"] = new TH2F("Eta vs Pt","",100,0,100,100,-2.5,2.5);
			minb_mapHist2D["EtavsPrimPt"] = new TH2F("Eta vs Pt with Primary Association","",100,0,100,100,-2.5,2.5);
			minb_mapHist2D["EtavsPtnoAsso"] = new TH2F("Eta vs Pt without Association","",100,0,100,100,-2.5,2.5);
			minb_mapHist2D["EtavsPilePt"] = new TH2F("Eta vs Phi with Pileup Association","",100,0,100,100,-2.5,2.5);
			
		}
		///Fill the Historgrams
		void FillHists(int NumberOfVertices,int aNumberOfInter,vector<double> sumtpt,int cond=0) {
			///depending on the condition (cond) fill the correct Histograms
			///			cond = 0 --- no Condition for ZPT
			///			cond = 1 --- ZPT > 20 GeV
			///			cond = 2 --- ZPT < 5 GeV
			///			cond = 3 --- ZPT < 2 GeV
			switch (cond){
				case 0:
					minb_mapHist1D["NoV"]->Fill(NumberOfVertices);
					minb_mapHist1D["NInt"]->Fill(aNumberOfInter);
					minb_mapHist1D["SumTPt"]->Fill(sumtpt[2]);
					minb_mapHist1D["SumTPrimPt"]->Fill(sumtpt[1]);
					minb_mapHist1D["SumTPilePt"]->Fill(sumtpt[0]);
					break;
				case 1:
					minb_mapHist1D["NoVPTZg20"]->Fill(NumberOfVertices);
					minb_mapHist1D["NIntPTZg20"]->Fill(aNumberOfInter);
					minb_mapHist1D["SumTPtZPTg20"]->Fill(sumtpt[2]);
					minb_mapHist1D["SumTPrimPtZPTg20"]->Fill(sumtpt[1]);
					minb_mapHist1D["SumTPilePtZPTg20"]->Fill(sumtpt[0]);
					break;
				case 2:
					minb_mapHist1D["NoVPTZs5"]->Fill(NumberOfVertices);
					minb_mapHist1D["NIntPTZs5"]->Fill(aNumberOfInter);
					minb_mapHist1D["SumTPtZPTs5"]->Fill(sumtpt[2]);
					minb_mapHist1D["SumTPrimPtZPTs5"]->Fill(sumtpt[1]);
					minb_mapHist1D["SumTPilePtZPTs5"]->Fill(sumtpt[0]);
					break;
				case 3:
					minb_mapHist1D["NoVPTZs2"]->Fill(NumberOfVertices);
					minb_mapHist1D["NIntPTZs2"]->Fill(aNumberOfInter);
					minb_mapHist1D["SumTPtZPTs2"]->Fill(sumtpt[2]);
					break;
			}		
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
		///FIll the 2D Angle Histograms
		void Fill2DHists(double veceta, double vecphi, double vecpt, int cond=0) {
			///depending on the condition (cond) fill the correct Histograms
			///			cond = 0 --- no association
			///			cond = 1 --- with either prim. or pileup assiciated
			///			cond = 2 --- with primary only
			///			cond = 3 --- with pileup only 
			switch (cond){
				case 0:
					minb_mapHist2D["PhiEtaNoA"]->Fill(veceta,vecphi);
					minb_mapHist2D["EtavsPtnoAsso"]->Fill(vecpt,veceta);
					break;
				case 1:
					minb_mapHist2D["PhiEtaA"]->Fill(veceta,vecphi);
					minb_mapHist2D["EtavsPt"]->Fill(vecpt,veceta);
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
			
		void WriteFile(TFile *fileO){
			fileO->Write();
			fileO->Close();
		}
	private:
		map<string, TH1*>		minb_mapHist1D;
		map<string, TH2*>		minb_mapHist2D;
};
