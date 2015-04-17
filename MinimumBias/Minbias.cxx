/// Lukas Mittnacht March 2015

#include <stdlib.h> 
#include "./EWCommonIncludes.h"
#include <cmath>

using namespace std;
using std::vector;

#include "./setbranches.h"
#include "./Minbias_functions.h"
#include "./minhists.h"

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
	string arg3 = argv[3];
	
	///check for Z ?
	if (argc == 4){
		
		if (arg3 == "0"){ 
			
			Zfilt = false;
		}
	}	
			
	TFile *fileI = new TFile(infile.c_str(),"READ"); /// Open Input ROOT File
	if (fileI->IsOpen())	cout<<"File "<<infile<<" opened successfully.\n";
	
	TFile *fileO = new TFile(outfile,"RECREATE"); /// Create Output File
	if (fileO->IsOpen())	cout<<"File "<<outfile<<" created successfully.\n";
	
	fileI->ls(); ///List fileI contents 
	
	TTree *tree = (TTree*) fileI->Get("MainzCaloCells"); /// Create TTree from file1
	///Set Branch Addresses 
	setbranches(tree);
	
	/// Check all Events
	totalEvents = tree->GetEntries();
	cout<<"A total of: "<< totalEvents<<" Events have been found. \n";
	
	Hists hist;
	
	
	for (int i=0;i<totalEvents;i++)	{
		
		tree->GetEntry(i);
		if (Zfilt == true){
			for (int cond=0;cond<4;cond++){
				TLorentzVector recoZ;
			
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
					vector<double> sumpt;
					mu1.SetPtEtaPhi(mu_pt->at(0),mu_eta->at(0),mu_phi->at(0));
					mu2.SetPtEtaPhi(mu_pt->at(1),mu_eta->at(1),mu_phi->at(1));
					Zvec.SetPtEtaPhi(recoZ.Pt(),recoZ.Eta(),recoZ.Phi());
					///Incerase totalZ, calculate the HadronicRecoil and fill the Histograms
					//totalZ++;
					sumpt = sumtrackpt(prim_track_pt,pile_track_pt);
					hist.FillHists(NumberOfVertices,averageNumberOfInteractions,sumpt,cond);
					isZ = false;
				}
			}
			
		}
		else if (Zfilt == false) {
			
			//TLorentzVector recoZ;
				//TVector3 mu1,mu2,Zvec;
					vector<double> sumpt;
					//mu1.SetPtEtaPhi(mu_pt->at(0),mu_eta->at(0),mu_phi->at(0));
					//mu2.SetPtEtaPhi(mu_pt->at(1),mu_eta->at(1),mu_phi->at(1));
					//Zvec.SetPtEtaPhi(recoZ.Pt(),recoZ.Eta(),recoZ.Phi());
					///Incerase totalZ, calculate the HadronicRecoil and fill the Histograms
					//totalZ++;
					sumpt = sumtrackpt(prim_track_pt,pile_track_pt);
					hist.FillHists(NumberOfVertices,averageNumberOfInteractions,sumpt,0);
			}	
	}
	//cout<<"A total of: "<<totalZ<<" Z Events have been found\n";
	hist.WriteFile(fileO);
	
}
