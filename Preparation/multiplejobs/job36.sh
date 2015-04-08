#!/bin/bash
#BSUB -L /bin/bash
#BSUB -o /home/lmittnac/HadronicRecoil/Preparation/output/out36.out
#BSUB -e /home/lmittnac/HadronicRecoil/Preparation/output/errout36.out
#BSUB -q atlaslong
#BSUB -app Reserve3G
#BSUB -n 3
#BSUB -J prep36

source /cluster/cern/root_v5.34.03_x86_64/bin/thisroot.sh

make
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/fe/e3/NTUP_COMMON.01311307._000260.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000260.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/d5/33/NTUP_COMMON.01311309._001588.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001588.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/79/04/NTUP_COMMON.01311308._000652.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000652.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/15/77/NTUP_COMMON.01311307._000213.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000213.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/b3/74/NTUP_COMMON.01311309._001621.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001621.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/54/90/NTUP_COMMON.01311307._000007.root.2 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000007.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/c8/2b/NTUP_COMMON.01311309._001901.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001901.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/0a/f5/NTUP_COMMON.01311309._001578.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001578.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/db/4f/NTUP_COMMON.01311308._001023.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._001023.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/9c/c5/NTUP_COMMON.01311308._001184.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._001184.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/ad/86/NTUP_COMMON.01311308._000635.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000635.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/12/d5/NTUP_COMMON.01311307._000402.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000402.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/b3/e7/NTUP_COMMON.01311309._001402.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001402.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/2b/d3/NTUP_COMMON.01311309._001882.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001882.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/5e/b0/NTUP_COMMON.01311308._000919.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000919.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/57/04/NTUP_COMMON.01311307._000082.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000082.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/a9/24/NTUP_COMMON.01311309._001900.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001900.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/f0/ee/NTUP_COMMON.01311308._001047.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._001047.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/27/a9/NTUP_COMMON.01311309._001241.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001241.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/f9/e0/NTUP_COMMON.01311307._000367.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000367.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/8c/d1/NTUP_COMMON.01311308._001130.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._001130.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/26/ca/NTUP_COMMON.01311307._000153.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000153.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/27/74/NTUP_COMMON.01311308._000629.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000629.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/f2/46/NTUP_COMMON.01311308._001043.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._001043.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/9c/ce/NTUP_COMMON.01311307._000021.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000021.root
