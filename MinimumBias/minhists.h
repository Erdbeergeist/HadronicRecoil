class Hists{
	public:
		Hists() {
			initHists();
		}
		///Initialize the Histograms
		void initHists() {
			minb_mapHist1D["NoV"] = new TH1F("Number of Vertices","",100,-100,100);
			minb_mapHist1D["NInt"] = new TH1F("Average Number of Interactions","",100,-100,100);
			minb_mapHist1D["NoVPTZg20"] = new TH1F("Number of Vertices ptZ g 20","",100,-100,100);
			minb_mapHist1D["NIntPTZg20"] = new TH1F("Average Number of Interactions ptZ g 20","",100,-100,100);
			minb_mapHist1D["NoVPTZs5"] = new TH1F("Number of Vertices ptZ s 5","",100,-100,100);
			minb_mapHist1D["NIntPTZs5"] = new TH1F("Average Number of Interactions ptZ s 5","",100,-100,100);
			minb_mapHist1D["NoVPTZs2"] = new TH1F("Number of Vertices ptZ s 2","",100,-100,100);
			minb_mapHist1D["NIntPTZs2"] = new TH1F("Average Number of Interactions ptZ s 2","",100,-100,100);
		}
		///Fill the Historgrams
		void FillHists(int NumberOfVertices,int aNumberOfInter, TVector3 Zvec,int cond=0) {
			switch (cond){
				case 0:
					minb_mapHist1D["NoV"]->Fill(NumberOfVertices);
					minb_mapHist1D["NInt"]->Fill(aNumberOfInter);
					break;
				case 1:
					minb_mapHist1D["NoVPTZg20"]->Fill(NumberOfVertices);
					minb_mapHist1D["NIntPTZg20"]->Fill(aNumberOfInter);
					break;
				case 2:
					minb_mapHist1D["NoVPTZs5"]->Fill(NumberOfVertices);
					minb_mapHist1D["NIntPTZs5"]->Fill(aNumberOfInter);
					break;
				case 3:
					minb_mapHist1D["NoVPTZs2"]->Fill(NumberOfVertices);
					minb_mapHist1D["NIntPTZs2"]->Fill(aNumberOfInter);
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
