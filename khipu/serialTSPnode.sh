#!/bin/bash
#SBATCH -J serial-TSP-node
#SBATCH -N 4
#SBATCH --tasks-per-node=8
#SBATCH --mem=1GB
#SBATCH --output=tsp-serial-node.log

# To compile
module load gcc/5.5.0

# 4 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-node.cpp -o tsp-node -DSIZE=4
./tsp-node ../tests/matrices/geekforgeeks_4.txt

# 5 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-node.cpp -o tsp-node -DSIZE=5
./tsp-node ../tests/matrices/video_5.txt

# 6 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-node.cpp -o tsp-node -DSIZE=6
./tsp-node ../tests/matrices/test_6.txt

# 10 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-node.cpp -o tsp-node -DSIZE=10
./tsp-node ../tests/matrices/matrix_10.txt

# 12 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-node.cpp -o tsp-node -DSIZE=12
./tsp-node ../tests/matrices/matrix_12.txt

# 13 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-node.cpp -o tsp-node -DSIZE=13
./tsp-node ../tests/matrices/matrix_13.txt

# 14 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-node.cpp -o tsp-node -DSIZE=14
./tsp-node ../tests/matrices/matrix_14.txt

# 15 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-node.cpp -o tsp-node -DSIZE=15
./tsp-node ../tests/matrices/matrix_15.txt

# 16 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-node.cpp -o tsp-node -DSIZE=16
./tsp-node ../tests/matrices/matrix_16.txt

# 17 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-node.cpp -o tsp-node -DSIZE=17
./tsp-node ../tests/matrices/matrix_17.txt

# 20 elementos
g++ -std=c++17 ../norecursivo/serial/tsp-node.cpp -o tsp-node -DSIZE=20
./tsp-node ../tests/matrices/matrix_20.txt.bk

module unload gcc/5.5.0
