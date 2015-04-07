#!/bin/bash
#BSUB -L /bin/bash
#BSUB -o /home/lmittnac/HadronicRecoil/Preparation/outputshort/out.out
#BSUB -e /home/lmittnac/HadronicRecoil/Preparation/outputshort/errout.out
#BSUB -q atlasshort
#BSUB -app Reserve3G
#BSUB -n 3
#BSUB -J Preparation

source /cluster/cern/root_v5.34.03_x86_64/bin/thisroot.sh

make
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000003.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000003.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000009.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000009.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000012.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000012.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000014.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000014.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000018.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000018.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000020.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000020.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000022.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000022.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000028.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000028.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000033.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000033.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000035.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000035.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000038.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000038.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000041.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000041.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000043.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000043.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000045.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000045.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000049.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000049.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000051.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000051.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000054.root.2
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000054.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000059.root.1
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000059.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000061.root.1
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000061.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000063.root.1
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000063.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000066.root.1
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000066.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000069.root.1
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000069.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000074.root.1
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000074.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000076.root.1
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000076.root
 
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/data12_8TeV.00206299.physics_Muons.merge.NTUP_COMMON.r4065_p1278_p1562_tid01316275_00/NTUP_COMMON.01316275._000078.root.1
 /home/lmittnac/HadronicRecoil/Preparation/outputshort/NTUP_COMMON.01316275._000078.root
 
