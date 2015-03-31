#!/bin/bash
#BSUB -L /bin/bash
#BSUB -o /home/lmittnac/HadRec/output/out.out
#BSUB -e /home/lmittnac/HadRec/output/errout.out
#BSUB -q atlaslong
#BSUB -app Reserve3G
#BSUB -n 3


source /cluster/cern/root_v5.34.03_x86_64/bin/thisroot.sh

make

/home/lmittnac/HadRec/hardrec /etapfs02/atlashpc/stilch/Preparation/Results_merged.root /home/lmittnac/HadRec/out.root
