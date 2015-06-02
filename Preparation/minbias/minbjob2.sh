#!/bin/bash
#BSUB -L /bin/bash
#BSUB -o /home/lmittnac/HadronicRecoil/Preparation/output/out.out
#BSUB -e /home/lmittnac/HadronicRecoil/Preparation/output/errout.out
#BSUB -q atlaslong
#BSUB -c 24:00
#BSUB -W 24:00 
#BSUB -app Reserve3G
#BSUB -n 3
#BSUB -J prep

source /cluster/cern/root_v5.34.03_x86_64/bin/thisroot.sh

make

mkdir /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00214160.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486600_00
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00214160.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486600_00/NTUP_COMMON.01486600._000209.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00214160.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486600_00/NTUP_COMMON.01486600._000209.root
