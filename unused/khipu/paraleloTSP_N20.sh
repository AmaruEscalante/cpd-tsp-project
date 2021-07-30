#!/bin/bash
#SBATCH -J tsp-par-N20
#SBATCH -N 1 # poner mas porque se va a ejecutar mas veces
#SBATCH --tasks-per-node=40 # Cantidad de CPUs
#SBATCH --mem-per-cpu=2GB
#SBATCH --output=tsp-par-m20-p2-p4-p8-p16-p20.log

# To compile
module load gcc/5.5.0

# 16 elementos
# Parallel processes
echo 'TSP con 2 Threads para matrix_20.txt'
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=20
./par-dfs-v2-tsp1 ../tests/matrices/matrix_20.txt.bk 2 &

echo 'TSP con 4 Threads para matrix_20.txt'
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=20
./par-dfs-v2-tsp2 ../tests/matrices/matrix_20.txt.bk 4 &

echo 'TSP con 8 Threads para matrix_20.txt'
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=20
./par-dfs-v2-tsp3 ../tests/matrices/matrix_20.txt.bk 8 &

echo 'TSP con 16 Threads para matrix_20.txt'
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=20
./par-dfs-v2-tsp4 ../tests/matrices/matrix_20.txt.bk 16 &&
# Last process runs alone
echo 'TSP con 20 Threads para matrix_20.txt'
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=20
./par-dfs-v2-tsp5 ../tests/matrices/matrix_20.txt.bk 20

wait

module unload gcc/5.5.0