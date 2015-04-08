#!/bin/bash
#BSUB -L /bin/bash
#BSUB -o /home/lmittnac/HadronicRecoil/Preparation/output/out76.out
#BSUB -e /home/lmittnac/HadronicRecoil/Preparation/output/errout76.out
#BSUB -q atlaslong
#BSUB -app Reserve3G
#BSUB -n 3
#BSUB -J prep76

source /cluster/cern/root_v5.34.03_x86_64/bin/thisroot.sh

make
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/20/d4/NTUP_COMMON.01311308._000781.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000781.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/9d/63/NTUP_COMMON.01311308._000706.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000706.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/97/af/NTUP_COMMON.01311308._000743.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000743.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/f4/06/NTUP_COMMON.01311309._001312.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001312.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/7f/98/NTUP_COMMON.01311308._000665.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000665.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/63/c2/NTUP_COMMON.01311308._000858.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000858.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/c0/e8/NTUP_COMMON.01311309._001705.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001705.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/74/bd/NTUP_COMMON.01311309._001603.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001603.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/ba/6b/NTUP_COMMON.01311307._000416.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000416.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/26/2f/NTUP_COMMON.01311308._000610.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000610.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/8c/d8/NTUP_COMMON.01311308._000667.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000667.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/0e/50/NTUP_COMMON.01311309._001476.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001476.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/ff/6e/NTUP_COMMON.01311309._001399.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001399.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/1f/cd/NTUP_COMMON.01311308._001041.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._001041.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/82/04/NTUP_COMMON.01311307._000261.root.2 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000261.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/cd/13/NTUP_COMMON.01311308._000953.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000953.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/5b/7a/NTUP_COMMON.01311309._001925.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001925.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/66/0a/NTUP_COMMON.01311309._001936.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001936.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/3e/be/NTUP_COMMON.01311308._000717.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000717.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/bb/3f/NTUP_COMMON.01311307._000294.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000294.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/a7/d5/NTUP_COMMON.01311307._000028.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000028.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/11/b9/NTUP_COMMON.01311309._001637.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001637.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/9e/97/NTUP_COMMON.01311309._001320.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001320.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/54/96/NTUP_COMMON.01311307._000523.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000523.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/1c/bd/NTUP_COMMON.01311309._001217.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001217.root
