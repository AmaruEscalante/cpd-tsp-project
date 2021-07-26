#!/bin/bash
#SBATCH -J tsp-6
#SBATCH -N 1
#SBATCH --tasks-per-node=8
#SBATCH --mem=1GB
#SBATCH --output=tsp-6.log

# To compile
# module load gcc/5.5.0
# g++ -std=c++17 ../norecursivo/serial/tsp-dfs-v2.cpp -o tsp-dfs-v2-6 -DSIZE=6
# module unload gcc/5.5.0

module load gcc/5.5.0
./tsp-dfs-v2-6 ../tests/matrices/test_6.txt
module unload gcc/5.5.0