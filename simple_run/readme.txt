#!/bin/bash   - ??? ?????? ???????? ????????????? bash
#SBATCH -p MOF   - ??? ?????? ???????, ????? ?????? ??????????? ?? ??????? ? ?????? MOF
#SBATCH -n 72   - ??? ?????? ??????? ? ?????????? ????????? (????), ??????? ??? ?????
#SBATCH -J st107   - ??? ???????? ??????, ??????? ?? ??????????? ????

srun vasp541-std.04 > out  - ??? ????? ?????????? VASP ? ????? out ??? ?????? ???????? ??????