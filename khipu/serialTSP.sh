#!/bin/bash
#SBATCH -J serial-TSP
#SBATCH -N 4
#SBATCH --tasks-per-node=8
#SBATCH --mem=1GB
#SBATCH --output=tsp-serial.log

# To compile
module load gcc/5.5.0

# 4 elementos
g++ -std=c++17 ../norecursivo/serial/ser-tsp-bb.cpp -o ser-tsp-bb -DSIZE=4
./ser-tsp-bb ../tests/matrices/geekforgeeks_4.txt

# 5 elementos
g++ -std=c++17 ../norecursivo/serial/ser-tsp-bb.cpp -o ser-tsp-bb -DSIZE=5
./ser-tsp-bb ../tests/matrices/video_5.txt

# 6 elementos
g++ -std=c++17 ../norecursivo/serial/ser-tsp-bb.cpp -o ser-tsp-bb -DSIZE=6
./ser-tsp-bb ../tests/matrices/test_6.txt

# 10 elementos
g++ -std=c++17 ../norecursivo/serial/ser-tsp-bb.cpp -o ser-tsp-bb -DSIZE=10
./ser-tsp-bb ../tests/matrices/matrix_10.txt

# 12 elementos
g++ -std=c++17 ../norecursivo/serial/ser-tsp-bb.cpp -o ser-tsp-bb -DSIZE=12
./ser-tsp-bb ../tests/matrices/matrix_12.txt

# 13 elementos
g++ -std=c++17 ../norecursivo/serial/ser-tsp-bb.cpp -o ser-tsp-bb -DSIZE=13
./ser-tsp-bb ../tests/matrices/matrix_13.txt

# 14 elementos
g++ -std=c++17 ../norecursivo/serial/ser-tsp-bb.cpp -o ser-tsp-bb -DSIZE=14
./ser-tsp-bb ../tests/matrices/matrix_14.txt

# 15 elementos
g++ -std=c++17 ../norecursivo/serial/ser-tsp-bb.cpp -o ser-tsp-bb -DSIZE=15
./ser-tsp-bb ../tests/matrices/matrix_15.txt

# 16 elementos
g++ -std=c++17 ../norecursivo/serial/ser-tsp-bb.cpp -o ser-tsp-bb -DSIZE=16
./ser-tsp-bb ../tests/matrices/matrix_16.txt

# 17 elementos
g++ -std=c++17 ../norecursivo/serial/ser-tsp-bb.cpp -o ser-tsp-bb -DSIZE=17
./ser-tsp-bb ../tests/matrices/matrix_17.txt

# 20 elementos
g++ -std=c++17 ../norecursivo/serial/ser-tsp-bb.cpp -o ser-tsp-bb -DSIZE=20
./ser-tsp-bb ../tests/matrices/matrix_20.txt.bk

module unload gcc/5.5.0
