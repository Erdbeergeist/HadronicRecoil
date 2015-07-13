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


int main(int argc, char *argv[]) {
	if (argc < 3){ ///Check Parameters
		cout<<"Please specify Input and Output Files as Parameters.\n";
		return 1;
	}	
	cout<<argv[1]<<endl;
	///Declare useful variables and assgin standard values
	int totalEvents=0,totalZ=0,ZMmin=50,ZMmax=116;
	bool isZ=false;
	
		
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
	
	
	/// Check all Events
	totalEvents = tree->GetEntries();
	cout<<"A total of: "<< totalEvents<<" Events have been found. \n";
	map<string, TH2*>		hadrec_mapHist2D;
	hadrec_mapHist2D["NvTest"] = new TH2F("NVTest","",40,0,40,100,400,2000);
	
	
	for (int i=0;i<totalEvents;i++)	{
		
		tree->GetEntry(i);
		/*TLorentzVector recoZ;
		
		isZ = Zcheck(mu_charge,mu_pt,mu_eta,mu_phi,recoZ,ZMmin,ZMmax);
		if (isZ==true){*/
		for (int j = 0; j<vecCellsPt->size();j++){
			
			if (countPVvec->at(j)>0&&countSVvec->at(j)<1){
				//cout<<"a\n";
				hadrec_mapHist2D["NvTest"]->Fill(NumberOfVertices,SumPtPVvec->at(j));
			}
		}
	}
//}
			
	fileO->Write();
	return 0;
	
}	
