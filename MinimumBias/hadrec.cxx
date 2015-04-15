/// Hardronic Recoil Computation using a pre prepared ROOT file by Stephan Tilch
/// Lukas Mittnacht March 2015

#include <stdlib.h> 
#include "./EWCommonIncludes.h"
#include <cmath>

using namespace std;
using namespace std;
using std::vector;
//using namespace std::chrono;

#include "./hadrec_functions.h"
#include "./setbranches.h"
#include "./hists.h"

void fileceatefolders(TFile *fileO){
	///Create Folder Structure in fileO
	fileO->mkdir("Everything");
	fileO->mkdir("PrimVert");
	fileO->mkdir("PrimVertScaled");
	//fileO->mkdir("PrimVertScaledImp");
	fileO->mkdir("PrimVertPtScaled");
	//fileO->mkdir("PrimVertPtScaledImp");
	//fileO->mkdir("PileUp");
}

int main(int argc, char *argv[]) {
	if (argc < 3){ ///Check Parameters
		cout<<"Please specify Input and Output Files as Parameters.\n";
		return 1;
	}	
	cout<<argv[1]<<endl;
	///Declare useful variables and assgin standard values
	int totalEvents=0,totalZ=0,ZMmin=50,ZMmax=116;
	bool isZ=false;
	
	///If given values set ZMmin and ZMmax
	if (argc == 4){
		ZMmin = atoi(argv[3]);
		ZMmax = atoi(argv[4]);
		cout<<"ZMmin set to: " <<ZMmin<<"\t ZMmax set to: "<<ZMmax<<" \n";
	}	
	
	string infile = argv[1]; ///Declare I/O Files
	const char* outfile = argv[2];
			
	TFile *fileI = new TFile(infile.c_str(),"READ"); /// Open Input ROOT File
	if (fileI->IsOpen())	cout<<"File "<<infile<<" opened successfully.\n";
	
	TFile *fileO = new TFile(outfile,"RECREATE"); /// Create Output File
	if (fileO->IsOpen())	cout<<"File "<<outfile<<" created successfully.\n";
	
	fileI->ls(); ///List fileI contents 
	
	TTree *tree = (TTree*) fileI->Get("MainzCaloCells"); /// Create TTree from file1
	///Set Branch Addresses 
	setbranches(tree);
	///create Folder Structure in Outputfile
	fileceatefolders(fileO);
	
	/// Check all Events
	totalEvents = tree->GetEntries();
	cout<<"A total of: "<< totalEvents<<" Events have been found. \n";
	
	///Initialize the Histograms	
	fileO->cd("Everything");
	makeHists hists;
	fileO->cd();
	fileO->cd("PrimVert");
	makeHists hists2;
	fileO->cd();
	fileO->cd("PrimVertScaled");
	makeHists hists3;
	//fileO->cd();
	//fileO->cd("PrimVertScaledImp");
	//makeHists hists7;
	fileO->cd();
	fileO->cd("PrimVertPtScaled");
	makeHists hists4;
	//fileO->cd();
	//fileO->cd("PrimVertPtScaledImp");
	//makeHists hists5;
	/*fileO->cd();
	fileO->cd("PileUp");
	makeHists hists6;*/
	for (int i=0;i<totalEvents;i++)	{
		
		tree->GetEntry(i);
		
		TLorentzVector recoZ;
		
		isZ = Zcheck(mu_charge,mu_pt,mu_eta,mu_phi,recoZ,ZMmin,ZMmax);
		
		if (isZ == true) {
			///Initialize the Vectors and assign the values
			TVector3 mu1,mu2,Zvec;
			mu1.SetPtEtaPhi(mu_pt->at(0),mu_eta->at(0),mu_phi->at(0));
			mu2.SetPtEtaPhi(mu_pt->at(1),mu_eta->at(1),mu_phi->at(1));
			Zvec.SetPtEtaPhi(recoZ.Pt(),recoZ.Eta(),recoZ.Phi());
			///Incerase totalZ, calculate the HadronicRecoil and fill the Histograms
			totalZ++;

			TVector3 HadronicRecoil = calcHadronicRecoil(vecCellsPt,vecCellsEta,vecCellsPhi,mu1,mu2,0.1);
			TVector3 HadronicRecoil2 = calcHadronicRecoilPrimVert(vecCellsPt,vecCellsEta,vecCellsPhi,mu1,mu2,countPVvec,countSVvec,0.1);
			TVector3 HadronicRecoil3 = calcHadronicRecoilPrimVertScaled(vecCellsPt,vecCellsEta,vecCellsPhi,mu1,mu2,countPVvec,countSVvec,0.1);
			TVector3 HadronicRecoil4 = calcHadronicRecoilPrimVertPtScaled(vecCellsPt,vecCellsEta,vecCellsPhi,mu1,mu2,countPVvec,SumPtPVvec,countSVvec,SumPtSVvec,0.1);
			
			//TVector3 HadronicRecoil5 = calcHadronicRecoilPrimVertPtScaledImp(vecCellsPt,vecCellsEta,vecCellsPhi,mu1,mu2,countPVvec,SumPtPVvec,countSVvec,SumPtSVvec);
			//TVector3 HadronicRecoil6 = calcHadronicRecoilPileUp(vecCellsPt,vecCellsEta,vecCellsPhi,mu1,mu2,countPVvec,countSVvec);
			//TVector3 HadronicRecoil7 = calcHadronicRecoilPrimVertScaledImp(vecCellsPt,vecCellsEta,vecCellsPhi,mu1,mu2,countPVvec,countSVvec);
			hists.FillHists(HadronicRecoil,Zvec);
			hists2.FillHists(HadronicRecoil2,Zvec);
			hists3.FillHists(HadronicRecoil3,Zvec);
			hists4.FillHists(HadronicRecoil4,Zvec);
			//hists5.FillHists(HadronicRecoil5,Zvec);
			//hists6.FillHists(HadronicRecoil6,Zvec);
			//hists7.FillHists(HadronicRecoil7,Zvec);
			hists.Fill2DHists(HadronicRecoil,Zvec,NumberOfVertices);
			hists2.Fill2DHists(HadronicRecoil2,Zvec,NumberOfVertices);
			hists3.Fill2DHists(HadronicRecoil3,Zvec,NumberOfVertices);
			hists4.Fill2DHists(HadronicRecoil4,Zvec,NumberOfVertices);
			//hists5.Fill2DHists(HadronicRecoil5,Zvec,NumberOfVertices);
			//hists6.Fill2DHists(HadronicRecoil6,Zvec,NumberOfVertices);
			//hists7.Fill2DHists(HadronicRecoil7,Zvec,NumberOfVertices);
			//cout<<PSnA(vecCellsPt,vecCellsEta,vecCellsPhi,mu1,mu2,countPVvec,countSVvec);
			//PTsum(vecCellsPt,vecCellsEta,vecCellsPhi,mu1,mu2,countPVvec,SumPtPVvec,countSVvec,SumPtSVvec);
		}	
		
	}
	/*fileO->cd();
	fileO->cd("PrimVertScaledImp");
	hists7.meanHists();
	hists7.Fill2DHistsresc(); 
	hists7.meanHists(0,"resc U_par+ptZ _ ptZ 2","Rescaled Bias vs ptZ");
	//hists7.rescale();
	fileO->cd();
	fileO->cd("PrimVertPtScaledImp");
	hists5.meanHists();
	hists5.Fill2DHistsresc();
	hists5.meanHists(0,"resc U_par+ptZ _ ptZ 2","Rescaled Bias vs ptZ");*/
	fileO->cd();
	fileO->cd("PrimVertPtScaled");
	hists4.meanHists();
	hists4.resHists();
	hists4.meanHists(0,"U_par+ptZ 2","Bias vs NV");
	hists4.resHists(0,"U_par+ptZ 2","Res vs NV");
	hists4.Fill2DHistsresc(); 
	hists4.meanHists(0,"resc U_par+ptZ _ ptZ 2","Rescaled Bias vs ptZ");
	hists4.resHists(0,"resc U_par+ptZ _ ptZ 2","Rescaled Res vs ptZ");
	hists4.meanHists(0,"resc U_par+ptZ 2","Rescaled Bias vs NV");
	hists4.resHists(0,"resc U_par+ptZ 2","Rescaled Res vs NV");
	fileO->cd();
	fileO->cd("PrimVertScaled");
	hists3.meanHists();
	hists3.resHists();
	hists3.meanHists(0,"U_par+ptZ 2","Bias vs NV");
	hists3.resHists(0,"U_par+ptZ 2","Res vs NV");
	hists3.Fill2DHistsresc();
	hists3.meanHists(0,"resc U_par+ptZ _ ptZ 2","Rescaled Bias vs ptZ");
	hists3.resHists(0,"resc U_par+ptZ _ ptZ 2","Rescaled Res vs ptZ");
	hists3.meanHists(0,"resc U_par+ptZ 2","Rescaled Bias vs NV");
	hists3.resHists(0,"resc U_par+ptZ 2","Rescaled Res vs NV");
	fileO->cd();
	fileO->cd("PrimVert");
	hists2.meanHists();
	hists2.resHists();
	hists2.meanHists(0,"U_par+ptZ 2","Bias vs NV");
	hists2.resHists(0,"U_par+ptZ 2","Res vs NV");
	hists2.Fill2DHistsresc();
	hists2.meanHists(0,"resc U_par+ptZ _ ptZ 2","Rescaled Bias vs ptZ");
	hists2.resHists(0,"resc U_par+ptZ _ ptZ 2","Rescaled Res vs ptZ");
	hists2.meanHists(0,"resc U_par+ptZ 2","Rescaled Bias vs NV");
	hists2.resHists(0,"resc U_par+ptZ 2","Rescaled Res vs NV");
	fileO->cd();
	fileO->cd("Everything");
	hists.meanHists();
	hists.resHists();
	hists.meanHists(0,"U_par+ptZ 2","Bias vs NV");
	hists.resHists(0,"U_par+ptZ 2","Res vs NV");
	hists.Fill2DHistsresc();
	hists.meanHists(0,"resc U_par+ptZ _ ptZ 2","Rescaled Bias vs ptZ");
	hists.resHists(0,"resc U_par+ptZ _ ptZ 2","Rescaled Res vs ptZ");
	hists.meanHists(0,"resc U_par+ptZ 2","Rescaled Bias vs NV");
	hists.resHists(0,"resc U_par+ptZ 2","Rescaled Res vs NV");
	cout<<"A total of: "<<totalZ<<" Z's were itentified"<<endl;
	///Write to fileO
	hists.WriteFile(fileO);
	fileI->Close();




	return 0;
	
}	
