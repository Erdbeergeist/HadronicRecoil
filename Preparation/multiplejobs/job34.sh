#!/bin/bash
#BSUB -L /bin/bash
#BSUB -o /home/lmittnac/HadronicRecoil/Preparation/output/out34.out
#BSUB -e /home/lmittnac/HadronicRecoil/Preparation/output/errout34.out
#BSUB -q atlaslong
#BSUB -app Reserve3G
#BSUB -n 3
#BSUB -J prep34

source /cluster/cern/root_v5.34.03_x86_64/bin/thisroot.sh

make
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/05/6d/NTUP_COMMON.01311309._001766.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001766.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/06/1f/NTUP_COMMON.01311308._000987.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000987.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/74/07/NTUP_COMMON.01311309._001854.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001854.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/ab/76/NTUP_COMMON.01311309._001855.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001855.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/5c/27/NTUP_COMMON.01311308._000774.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000774.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/12/b5/NTUP_COMMON.01311307._000415.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000415.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/96/39/NTUP_COMMON.01311307._000477.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000477.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/e4/2e/NTUP_COMMON.01311308._001033.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._001033.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/07/b7/NTUP_COMMON.01311308._000615.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000615.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/5a/e3/NTUP_COMMON.01311308._001063.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._001063.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/db/76/NTUP_COMMON.01311308._000672.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000672.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/e1/7d/NTUP_COMMON.01311309._001807.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001807.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/be/b6/NTUP_COMMON.01311309._001975.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001975.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/47/78/NTUP_COMMON.01311307._000548.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000548.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/78/cc/NTUP_COMMON.01311309._001415.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001415.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/b6/19/NTUP_COMMON.01311307._000478.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000478.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/fc/92/NTUP_COMMON.01311309._001852.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001852.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/9c/71/NTUP_COMMON.01311308._001014.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._001014.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/84/2c/NTUP_COMMON.01311307._000324.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000324.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/f9/6b/NTUP_COMMON.01311309._001694.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001694.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/62/a0/NTUP_COMMON.01311309._001341.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001341.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/20/aa/NTUP_COMMON.01311308._001142.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._001142.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/a7/c6/NTUP_COMMON.01311308._000753.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000753.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/43/59/NTUP_COMMON.01311307._000531.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000531.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/a5/ad/NTUP_COMMON.01311309._001337.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001337.root
