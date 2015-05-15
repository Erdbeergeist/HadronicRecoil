infile = open("files.txt")
outfile = open("merge.sh","w")
outfile.write("#!/bin/bash\n"+"#BSUB -L /bin/bash\n\
#BSUB -o /home/lmittnac/HadronicRecoil/Preparation/output/out.out\n\
#BSUB -e /home/lmittnac/HadronicRecoil/Preparation/output/errout.out\n\
#BSUB -q atlaslong\n\
#BSUB -app Reserve3G\n\
#BSUB -n 3\n\
#BSUB -J prep\n\
source /cluster/cern/root_v5.34.03_x86_64/bin/thisroot.sh\n\
\n\
source /cluster/cern/root_v5.34.03_x86_64/bin/thisroot.sh\
/cluster/cern/root_v5.34.03_x86_64/bin/hadd /home/lmittnac/HadronicRecoil/Preparation/MCZmumumerged.root")

for line in infile:
	outfile.write(" "+line[:-1])
