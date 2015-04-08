#!/bin/bash
#BSUB -L /bin/bash
#BSUB -o /home/lmittnac/HadronicRecoil/Preparation/output/out1.out
#BSUB -e /home/lmittnac/HadronicRecoil/Preparation/output/errout1.out
#BSUB -q atlaslong
#BSUB -app Reserve3G
#BSUB -n 3
#BSUB -J prep1

source /cluster/cern/root_v5.34.03_x86_64/bin/thisroot.sh

make
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/15/61/NTUP_COMMON.01311309._001347.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001347.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/54/ff/NTUP_COMMON.01311309._001768.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001768.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/24/c7/NTUP_COMMON.01311309._001646.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001646.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/be/e3/NTUP_COMMON.01311309._001449.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001449.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/0c/e6/NTUP_COMMON.01311308._000623.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000623.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/ad/9c/NTUP_COMMON.01311309._001895.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001895.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/26/64/NTUP_COMMON.01311309._001541.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001541.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/64/1c/NTUP_COMMON.01311308._001055.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._001055.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/78/79/NTUP_COMMON.01311309._001996.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001996.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/a6/19/NTUP_COMMON.01311309._001504.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001504.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/d8/65/NTUP_COMMON.01311307._000289.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000289.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/22/1b/NTUP_COMMON.01311309._001317.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001317.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/76/49/NTUP_COMMON.01311309._001911.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001911.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/33/de/NTUP_COMMON.01311309._001605.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001605.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/a2/63/NTUP_COMMON.01311309._001209.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001209.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/be/ed/NTUP_COMMON.01311309._001806.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001806.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/cb/ea/NTUP_COMMON.01311308._000607.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000607.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/71/52/NTUP_COMMON.01311309._001723.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001723.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/bc/24/NTUP_COMMON.01311309._001490.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001490.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/31/d0/NTUP_COMMON.01311309._001770.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001770.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/52/79/NTUP_COMMON.01311307._000221.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000221.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/7e/bf/NTUP_COMMON.01311307._000583.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311307._000583.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/0d/2c/NTUP_COMMON.01311308._000704.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._000704.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/34/cf/NTUP_COMMON.01311308._001114.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311308._001114.root
/home/lmittnac/HadronicRecoil/Preparation/Preparation /gpfs/fs3/atlas/atlaslocalgroupdisk/rucio/mc12_8TeV/b6/01/NTUP_COMMON.01311309._001543.root.1 /home/lmittnac/HadronicRecoil/Preparation/output/NTUP_COMMON.01311309._001543.root
