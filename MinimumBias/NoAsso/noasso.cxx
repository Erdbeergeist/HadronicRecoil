/// Lukas Mittnacht March 2015

#include <stdlib.h> 
#include "./EWCommonIncludes.h"
#include <cmath>

using namespace std;
using std::vector;

#include "./setbranches.h"
#include "./hists.h"
#include "./noasso_functions.h"

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
	
	///List fileI contents 
	fileI->ls();
	
	/// Create TTree from file1
	TTree *tree = (TTree*) fileI->Get("MainzCaloCells"); 
	///Set Branch Addresses 
	setbranches(tree);
	
	/// Create Output File
	TFile *fileO = new TFile(outfile,"RECREATE"); 
	if (fileO->IsOpen())	cout<<"File "<<outfile<<" created successfully.\n";
	
	/// Check all Events
	totalEvents = tree->GetEntries();
	cout<<"A total of: "<< totalEvents<<" Events have been found. \n";
	
	Hists hist;
	int helper=0;
	///Event Loop
	if (Zfilt==false){
	for (int i=0;i<totalEvents;i++)	{
		
		tree->GetEntry(i);
		
		for (int j=0;j<vecCellsPt->size();j++){
			if (countPVvec->at(j) ==0 && countSVvec->at(j)==0)
				helper += 1;
				hist.FillClusternoTrack(vecCellsPt->at(j),vecCellsEta->at(j));
				for(int k =0;k<all_track_pt->size();k++){
					if(sqrt(pow(vecCellsEta->at(j)-all_track_eta->at(k),2)+pow(vecCellsPhi->at(j)-all_track_phi->at(k),2))<0.4) hist.FillRTrack(all_track_pt->at(k),all_track_eta->at(k));	
				}
				for(int k=0;k<vecCellsPt->size();k++){
					if(sqrt(pow(vecCellsEta->at(j)-vecCellsEta->at(k),2)+pow(vecCellsPhi->at(j)-vecCellsPhi->at(k),2))<0.4) hist.FillRCluster(vecCellsPt->at(k),vecCellsEta->at(k));	
				}	
		}	
		hist.FillNumClwoTrack(helper);
		helper =0;
	}
	}
	else {
		for (int i=0;i<totalEvents;i++)	{
		
		tree->GetEntry(i);
		TLorentzVector recoZ;
		if (isZ = Zcheck(mu_charge,mu_pt,mu_eta,mu_phi,recoZ,ZMmin,ZMmax,&hist)==true){
		for (int j=0;j<vecCellsPt->size();j++){
			if (countPVvec->at(j) ==0 && countSVvec->at(j)==0)
				helper += 1;
				hist.FillClusternoTrack(vecCellsPt->at(j),vecCellsEta->at(j));
				for(int k =0;k<all_track_pt->size();k++){
					if(sqrt(pow(vecCellsEta->at(j)-all_track_eta->at(k),2)+pow(vecCellsPhi->at(j)-all_track_phi->at(k),2))<0.4) hist.FillRTrack(all_track_pt->at(k),all_track_eta->at(k));	
				}
				for(int k=0;k<vecCellsPt->size();k++){
					if(sqrt(pow(vecCellsEta->at(j)-vecCellsEta->at(k),2)+pow(vecCellsPhi->at(j)-vecCellsPhi->at(k),2))<0.4) hist.FillRCluster(vecCellsPt->at(k),vecCellsEta->at(k));	
				}	
		}	
		hist.FillNumClwoTrack(helper);
		helper =0;
	}
	}
	
}
hist.WriteFile(fileO);
}
