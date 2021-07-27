#!/bin/bash
#SBATCH -J tsp-par
#SBATCH -N 1 # poner mas porque se va a ejecutar mas veces
#SBATCH --tasks-per-node=8 # Cantidad de CPUs
#SBATCH --mem=1GB
#SBATCH --output=tsp-par-20.log

# To compile
module load gcc/5.5.0

# 4 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=4
./par-dfs-v2-tsp ../tests/matrices/geekforgeeks_4.txt

# 5 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=5
./par-dfs-v2-tsp ../tests/matrices/video_5.txt

# 6 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=6
./par-dfs-v2-tsp ../tests/matrices/test_6.txt

# 10 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=10
./par-dfs-v2-tsp ../tests/matrices/matrix_10.txt

# 12 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=12
./par-dfs-v2-tsp ../tests/matrices/matrix_12.txt

# 13 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=13
./par-dfs-v2-tsp ../tests/matrices/matrix_13.txt

# 14 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=14
./par-dfs-v2-tsp ../tests/matrices/matrix_14.txt

# 15 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=15
./par-dfs-v2-tsp ../tests/matrices/matrix_15.txt

# 16 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=16
./par-dfs-v2-tsp ../tests/matrices/matrix_16.txt

# 17 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=17
./par-dfs-v2-tsp ../tests/matrices/matrix_17.txt

# 20 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=20
./par-dfs-v2-tsp ../tests/matrices/matrix_20.txt.bk

module unload gcc/5.5.0