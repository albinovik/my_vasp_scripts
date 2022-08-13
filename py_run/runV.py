#!/usr/bin/python
#test program: run VASP from python
import subprocess
cmd = 'srun -n 24 -p part02 vasp541-std.04 > out &'
p = subprocess.Popen(cmd, shell=True)
print('TASK is in the order on claster!')
print('\ndone!')
