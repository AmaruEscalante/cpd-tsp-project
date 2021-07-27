#!/bin/bash
#SBATCH -J tsp-par-node
#SBATCH -N 4 # poner mas porque se va a ejecutar mas veces
#SBATCH --tasks-per-node=8 # Cantidad de CPUs
#SBATCH --mem=1GB
#SBATCH --output=tsp-par-20.log

# To compile
module load gcc/5.5.0

# 4 elementos
g++ -std=c++17 ../norecursivo/paralelo/tsp-node-par.cpp -fopenmp -lpthread -o tsp-node-par -DSIZE=4
./tsp-node-par ../tests/matrices/geekforgeeks_4.txt

# 5 elementos
g++ -std=c++17 ../norecursivo/paralelo/tsp-node-par.cpp -fopenmp -lpthread -o tsp-node-par -DSIZE=5
./tsp-node-par ../tests/matrices/video_5.txt

# 6 elementos
g++ -std=c++17 ../norecursivo/paralelo/tsp-node-par.cpp -fopenmp -lpthread -o tsp-node-par -DSIZE=6
./tsp-node-par ../tests/matrices/test_6.txt

# 10 elementos
g++ -std=c++17 ../norecursivo/paralelo/tsp-node-par.cpp -fopenmp -lpthread -o tsp-node-par -DSIZE=10
./tsp-node-par ../tests/matrices/matrix_10.txt

# 12 elementos
g++ -std=c++17 ../norecursivo/paralelo/tsp-node-par.cpp -fopenmp -lpthread -o tsp-node-par -DSIZE=12
./tsp-node-par ../tests/matrices/matrix_12.txt

# 13 elementos
g++ -std=c++17 ../norecursivo/paralelo/tsp-node-par.cpp -fopenmp -lpthread -o tsp-node-par -DSIZE=13
./tsp-node-par ../tests/matrices/matrix_13.txt

# 14 elementos
g++ -std=c++17 ../norecursivo/paralelo/tsp-node-par.cpp -fopenmp -lpthread -o tsp-node-par -DSIZE=14
./tsp-node-par ../tests/matrices/matrix_14.txt

# 15 elementos
g++ -std=c++17 ../norecursivo/paralelo/tsp-node-par.cpp -fopenmp -lpthread -o tsp-node-par -DSIZE=15
./tsp-node-par ../tests/matrices/matrix_15.txt

# 16 elementos
g++ -std=c++17 ../norecursivo/paralelo/tsp-node-par.cpp -fopenmp -lpthread -o tsp-node-par -DSIZE=16
./tsp-node-par ../tests/matrices/matrix_16.txt

# 17 elementos
g++ -std=c++17 ../norecursivo/paralelo/tsp-node-par.cpp -fopenmp -lpthread -o tsp-node-par -DSIZE=17
./tsp-node-par ../tests/matrices/matrix_17.txt

# 20 elementos
g++ -std=c++17 ../norecursivo/paralelo/tsp-node-par.cpp -fopenmp -lpthread -o tsp-node-par -DSIZE=20
./tsp-node-par ../tests/matrices/matrix_20.txt.bk

module unload gcc/5.5.0