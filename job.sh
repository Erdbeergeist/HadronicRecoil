#!/bin/bash
#BSUB -L /bin/bash
#BSUB -o /home/lmittnac/HadronicRecoil/output/out.out
#BSUB -e /home/lmittnac/HadronicRecoil/output/errout.out
#BSUB -q atlaslong
#BSUB -app Reserve3G
#BSUB -n 3


source /cluster/cern/root_v5.34.03_x86_64/bin/thisroot.sh

make

/home/lmittnac/HadronicRecoil/hadrec /etapfs02/atlashpc/stilch/Preparation/Results_merged.root /home/lmittnac/HadronicRecoil/out.root
