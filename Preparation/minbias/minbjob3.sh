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

mkdir /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312129_00
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312129_00/NTUP_COMMON.01312129._000419.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312129_00/NTUP_COMMON.01312129._000419.root
mkdir /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312130_00
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312130_00/NTUP_COMMON.01312130._002255.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312130_00/NTUP_COMMON.01312130._002255.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312130_00/NTUP_COMMON.01312130._004081.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312130_00/NTUP_COMMON.01312130._004081.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312130_00/NTUP_COMMON.01312130._004941.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312130_00/NTUP_COMMON.01312130._004941.root
mkdir /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312133_00
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312133_00/NTUP_COMMON.01312133._015873.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312133_00/NTUP_COMMON.01312133._015873.root
mkdir /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312136_00
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312136_00/NTUP_COMMON.01312136._026761.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312136_00/NTUP_COMMON.01312136._026761.root
mkdir /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312137_00
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312137_00/NTUP_COMMON.01312137._030572.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312137_00/NTUP_COMMON.01312137._030572.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312137_00/NTUP_COMMON.01312137._031548.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312137_00/NTUP_COMMON.01312137._031548.root
mkdir /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312138_00
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312138_00/NTUP_COMMON.01312138._037998.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312138_00/NTUP_COMMON.01312138._037998.root
mkdir /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312139_00
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312139_00/NTUP_COMMON.01312139._038281.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312139_00/NTUP_COMMON.01312139._038281.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /etapfs05/atlashpc/lintai/LocalData/NTUP_COMMON/MiniBias/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312139_00/NTUP_COMMON.01312139._039394.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/mc12_8TeV.119997.Pythia8_A2MSTW2008LO_minbias_ND.merge.NTUP_COMMON.e1119_s1479_s1470_r3843_r3549_p1562_tid01312139_00/NTUP_COMMON.01312139._039394.root