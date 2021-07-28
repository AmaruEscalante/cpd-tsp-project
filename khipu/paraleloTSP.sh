#!/bin/bash
#SBATCH -J tsp-par
#SBATCH -N 4 # poner mas porque se va a ejecutar mas veces
#SBATCH --tasks-per-node=8 # Cantidad de CPUs
#SBATCH --mem=1GB
#SBATCH --output=tsp-par.log

# To compile
module load gcc/5.5.0

# 4 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-tsp-bb.cpp -fopenmp -lpthread -o par-tsp-bb -DSIZE=4
./par-tsp-bb ../tests/matrices/geekforgeeks_4.txt

# 5 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-tsp-bb.cpp -fopenmp -lpthread -o par-tsp-bb -DSIZE=5
./par-tsp-bb ../tests/matrices/video_5.txt

# 6 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-tsp-bb.cpp -fopenmp -lpthread -o par-tsp-bb -DSIZE=6
./par-tsp-bb ../tests/matrices/test_6.txt

# 10 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-tsp-bb.cpp -fopenmp -lpthread -o par-tsp-bb -DSIZE=10
./par-tsp-bb ../tests/matrices/matrix_10.txt

# 12 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-tsp-bb.cpp -fopenmp -lpthread -o par-tsp-bb -DSIZE=12
./par-tsp-bb ../tests/matrices/matrix_12.txt

# 13 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-tsp-bb.cpp -fopenmp -lpthread -o par-tsp-bb -DSIZE=13
./par-tsp-bb ../tests/matrices/matrix_13.txt

# 14 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-tsp-bb.cpp -fopenmp -lpthread -o par-tsp-bb -DSIZE=14
./par-tsp-bb ../tests/matrices/matrix_14.txt

# 15 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-tsp-bb.cpp -fopenmp -lpthread -o par-tsp-bb -DSIZE=15
./par-tsp-bb ../tests/matrices/matrix_15.txt

# 16 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-tsp-bb.cpp -fopenmp -lpthread -o par-tsp-bb -DSIZE=16
./par-tsp-bb ../tests/matrices/matrix_16.txt

# 17 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-tsp-bb.cpp -fopenmp -lpthread -o par-tsp-bb -DSIZE=17
./par-tsp-bb ../tests/matrices/matrix_17.txt

# 20 elementos
g++ -std=c++17 ../norecursivo/paralelo/par-tsp-bb.cpp -fopenmp -lpthread -o par-tsp-bb -DSIZE=20
./par-tsp-bb ../tests/matrices/matrix_20.txt.bk

module unload gcc/5.5.0