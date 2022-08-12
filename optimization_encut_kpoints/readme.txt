This program implements optimization of 1 structure 
in POSCAR format file.

Optimization will perfomed by change 2 parameters:
encut and k-points(kp)

______________________________________________________

1. You should to create directory init
and put your POSCAR there.

Then, You have to prepare INCAR with string:
ENCUT = encut

And KPOINTS with strings:
Auto
kp

2. After that, run manyDIRs
./manyDIRs

______________________________________________________

The program creates several directories.
Each directories contain 4 files:
INCAR, POSCAR, POTCAR, KPOINTS.

There are differences in strings of files:
INCAR(encut) è KPOINTS(kp).

______________________________________________________

Script requires additional string for vasp run.
 



 