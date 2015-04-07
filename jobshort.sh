#!/bin/bash
#BSUB -L /bin/bash
#BSUB -o /home/lmittnac/HadronicRecoil/outputshort/out.out
#BSUB -e /home/lmittnac/HadronicRecoil/outputshort/errout.out
#BSUB -q atlasshort
#BSUB -app Reserve3G
#BSUB -n 3
#BSUB -J analysis


source /cluster/cern/root_v5.34.03_x86_64/bin/thisroot.sh

make

/home/lmittnac/HadronicRecoil/hadrec /etapfs02/atlashpc/stilch/Preparation/Results_merged.root /home/lmittnac/HadronicRecoil/outputshort/out.root
