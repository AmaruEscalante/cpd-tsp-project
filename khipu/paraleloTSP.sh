#!/bin/bash
#SBATCH -J tsp-par-20
#SBATCH -N 1
#SBATCH --tasks-per-node=8
#SBATCH --mem=1GB
#SBATCH --output=tsp-par-20.log

# To compile
module load gcc/5.5.0
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp-20 -DSIZE=20
# module unload gcc/5.5.0

# module load gcc/5.5.0
./par-dfs-v2-tsp-20 ../tests/matrices/matrix_20.txt.bk
module unload gcc/5.5.0