/// Lukas Mittnacht March 2015

#include <stdlib.h> 
#include "./EWCommonIncludes.h"
#include <cmath>

using namespace std;
using std::vector;

#include "./setbranches.h"
#include "./minhists.h"
#include "./Minbias_functions.h"

int main(int argc, char *argv[]) {
	if (argc < 3){ ///Check Parameters
		cout<<"Please specify Input and Output Files as Parameters.\n";
		return 1;
	}	
	///Declare neccessary Variables
	int totalEvents,ZMmin=0,ZMmax=1000000,totalZ=0;
	bool isZ = false;
	bool Zfilt = true;
	
	string infile = argv[1]; ///Declare I/O Files
	const char* outfile = argv[2];

	///If a 3rd Argument is given check if it is "0" and if it is do not 
	///filter for ZEvents (MinimumBias)
	if (argc == 4){
		string arg3 = argv[3];	
		if (arg3 == "0"){ 
			
			Zfilt = false;
		}
	}	
	/// Open Input ROOT File	
	TFile *fileI = new TFile(infile.c_str(),"READ"); 
	if (fileI->IsOpen())	cout<<"File "<<infile<<" opened successfully.\n";
	
	/// Create Output File
	TFile *fileO = new TFile(outfile,"RECREATE"); 
	if (fileO->IsOpen())	cout<<"File "<<outfile<<" created successfully.\n";
	
	///List fileI contents 
	fileI->ls();
	
	/// Create TTree from file1
	TTree *tree = (TTree*) fileI->Get("MainzCaloCells"); 
	///Set Branch Addresses 
	setbranches(tree);
	
	/// Check all Events
	totalEvents = tree->GetEntries();
	cout<<"A total of: "<< totalEvents<<" Events have been found. \n";
	
	Hists hist;
	
	///Event Loop
	for (int i=0;i<totalEvents;i++)	{
		
		tree->GetEntry(i);
		/// Wether or not to check ZEvents
		if (Zfilt == true){
			for (int cond=0;cond<4;cond++){
				TLorentzVector recoZ;
				///Check for ZEvents with the given Minimum & Maximum Mass
				switch (cond) {
					case 0:
						isZ = Zcheck(mu_charge,mu_pt,mu_eta,mu_phi,recoZ,ZMmin,ZMmax);
						break;
					case 1:
						isZ = Zcheck(mu_charge,mu_pt,mu_eta,mu_phi,recoZ,20,ZMmax);
						break;
					case 2:
						isZ = Zcheck(mu_charge,mu_pt,mu_eta,mu_phi,recoZ,ZMmin,5);
						break;
					case 3:
						isZ = Zcheck(mu_charge,mu_pt,mu_eta,mu_phi,recoZ,ZMmin,2);
						break;
				}		
			
				if (isZ == true) {
					///Initialize the Vectors and assign the values
					TVector3 mu1,mu2,Zvec;
					mu1.SetPtEtaPhi(mu_pt->at(0),mu_eta->at(0),mu_phi->at(0));
					mu2.SetPtEtaPhi(mu_pt->at(1),mu_eta->at(1),mu_phi->at(1));
					Zvec.SetPtEtaPhi(recoZ.Pt(),recoZ.Eta(),recoZ.Phi());
					
					///Incerase totalZ, calculate the HadronicRecoil and fill the Histograms
					
					vector<double> sumpt = sumtrackpt(prim_track_pt,pile_track_pt);
					hist.FillHists(NumberOfVertices,averageNumberOfInteractions,sumpt,cond);
					isZ = false;
				}
			}
			
		}
		///NO check for ZEvents, take every event (MinimumBias)
		else if (Zfilt == false) {
			vector<double> sumpt;
			sumpt = sumtrackpt(prim_track_pt,pile_track_pt);
			hist.FillHists(NumberOfVertices,averageNumberOfInteractions,sumpt,0);
		}
		///Check the Track Association and Fill the correct histograms
		checkassociation(&hist,countPVvec,countSVvec,vecCellsPt,vecCellsEta,vecCellsPhi);	
		
	}
	//cout<<"A total of: "<<totalZ<<" Z Events have been found\n";
	hist.WriteFile(fileO);
	
}
