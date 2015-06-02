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
mkdir /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000001.root.2 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000001.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000004.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000004.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000015.root.2 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000015.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000016.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000016.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000021.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000021.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000043.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000043.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000045.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000045.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000046.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000046.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000054.root.2 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000054.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000055.root.2 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000055.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000062.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000062.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000071.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000071.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000072.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000072.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000084.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000084.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000085.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000085.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000097.root.2 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000097.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000106.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000106.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000115.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000115.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000116.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000116.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000119.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/data12_8TeV.00208485.physics_ZeroBiasOverlay.merge.NTUP_COMMON.r4065_p1278_p1680_tid01486498_00/NTUP_COMMON.01486498._000119.root


