#!/bin/bash
#SBATCH -J serial-TSP
#SBATCH -N 4
#SBATCH --tasks-per-node=8
#SBATCH --mem=1GB
#SBATCH --output=tsp-serial.log

# To compile
module load gcc/5.5.0

# 4 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-dfs-v2.cpp -o tsp-dfs-v2 -DSIZE=4
./tsp-dfs-v2 ../tests/matrices/geekforgeeks_4.txt

# 5 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-dfs-v2.cpp -o tsp-dfs-v2 -DSIZE=5
./tsp-dfs-v2 ../tests/matrices/video_5.txt

# 6 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-dfs-v2.cpp -o tsp-dfs-v2 -DSIZE=6
./tsp-dfs-v2 ../tests/matrices/test_6.txt

# 10 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-dfs-v2.cpp -o tsp-dfs-v2 -DSIZE=10
./tsp-dfs-v2 ../tests/matrices/matrix_10.txt

# 12 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-dfs-v2.cpp -o tsp-dfs-v2 -DSIZE=12
./tsp-dfs-v2 ../tests/matrices/matrix_12.txt

# 13 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-dfs-v2.cpp -o tsp-dfs-v2 -DSIZE=13
./tsp-dfs-v2 ../tests/matrices/matrix_13.txt

# 14 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-dfs-v2.cpp -o tsp-dfs-v2 -DSIZE=14
./tsp-dfs-v2 ../tests/matrices/matrix_14.txt

# 15 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-dfs-v2.cpp -o tsp-dfs-v2 -DSIZE=15
./tsp-dfs-v2 ../tests/matrices/matrix_15.txt

# 16 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-dfs-v2.cpp -o tsp-dfs-v2 -DSIZE=16
./tsp-dfs-v2 ../tests/matrices/matrix_16.txt

# 17 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-dfs-v2.cpp -o tsp-dfs-v2 -DSIZE=17
./tsp-dfs-v2 ../tests/matrices/matrix_17.txt

# 20 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-dfs-v2.cpp -o tsp-dfs-v2 -DSIZE=20
./tsp-dfs-v2 ../tests/matrices/matrix_20.txt.bk

module unload gcc/5.5.0
