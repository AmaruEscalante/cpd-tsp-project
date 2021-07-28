#!/bin/bash
#SBATCH -J tsp-par-N20
#SBATCH -N 1 # poner mas porque se va a ejecutar mas veces
#SBATCH --tasks-per-node=32 # Cantidad de CPUs
#SBATCH --mem=20GB
#SBATCH --output=tsp-par-m20-p2-p4-p8-p16-p20.log

# To compile
module load gcc/5.5.0

# 16 elementos
# Parallel processes
echo 'TSP con 2 Threads para matrix_20.txt'
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=20
./par-dfs-v2-tsp ../tests/matrices/matrix_20.txt.bk 2 > process1.log &

echo 'TSP con 4 Threads para matrix_20.txt'
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=20
./par-dfs-v2-tsp ../tests/matrices/matrix_20.txt.bk 4 > process2.log &

echo 'TSP con 8 Threads para matrix_20.txt'
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=20
./par-dfs-v2-tsp ../tests/matrices/matrix_20.txt.bk 8 > process3.log &

echo 'TSP con 16 Threads para matrix_20.txt'
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=20
./par-dfs-v2-tsp ../tests/matrices/matrix_20.txt.bk 16 > process4.log &&
# Last process runs alone
echo 'TSP con 20 Threads para matrix_20.txt' &&
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=20
./par-dfs-v2-tsp ../tests/matrices/matrix_20.txt.bk 20 > process5.log

wait

module unload gcc/5.5.0