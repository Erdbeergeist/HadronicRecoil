#!/bin/bash
#BSUB -L /bin/bash
#BSUB -o /home/lmittnac/HadronicRecoil/Preparation/output/out65.out
#BSUB -e /home/lmittnac/HadronicRecoil/Preparation/output/errout65.out
#BSUB -q atlaslong
#BSUB -app Reserve3G
#BSUB -n 3
#BSUB -J prep65

source /cluster/cern/root_v5.34.03_x86_64/bin/thisroot.sh

make
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/bc/9c/NTUP_COMMON.01311307._000342.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000342.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/e4/08/NTUP_COMMON.01311308._000797.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000797.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/82/54/NTUP_COMMON.01311307._000218.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000218.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/3e/6b/NTUP_COMMON.01311307._000124.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000124.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/88/d7/NTUP_COMMON.01311309._001876.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001876.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/21/51/NTUP_COMMON.01311309._001586.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001586.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/5a/dd/NTUP_COMMON.01311308._001016.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._001016.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/ed/9a/NTUP_COMMON.01311308._000801.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000801.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/12/5e/NTUP_COMMON.01311309._001651.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001651.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/18/21/NTUP_COMMON.01311308._000612.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000612.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/94/28/NTUP_COMMON.01311307._000119.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000119.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/1d/fc/NTUP_COMMON.01311309._001835.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001835.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/eb/ed/NTUP_COMMON.01311307._000283.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000283.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/91/c3/NTUP_COMMON.01311308._000614.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000614.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/54/7e/NTUP_COMMON.01311307._000470.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000470.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/d9/17/NTUP_COMMON.01311307._000122.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000122.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/e1/e1/NTUP_COMMON.01311307._000335.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000335.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/bc/4a/NTUP_COMMON.01311308._000608.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000608.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/f3/b3/NTUP_COMMON.01311308._001058.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._001058.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/b9/22/NTUP_COMMON.01311307._000534.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000534.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/c1/9d/NTUP_COMMON.01311309._001610.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001610.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/72/24/NTUP_COMMON.01311307._000137.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000137.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/8b/b9/NTUP_COMMON.01311309._001234.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001234.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/c6/9d/NTUP_COMMON.01311308._001101.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._001101.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/26/92/NTUP_COMMON.01311308._000673.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000673.root
