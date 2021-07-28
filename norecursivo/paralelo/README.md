# How to compile

- MAC: g++ --std=c++17 -Xpreprocessor -fopenmp par-dfs-v2-tsp.cpp -lomp -DSIZE=10
- LINUX: g++ -std=c++17 ../norecursivo/paralelo/par-dfs-v2-tsp.cpp -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=4

# How to run
- ./par-dfs-v2-tsp ../../tests/matrices/matrix_10.txt 4
- first arg: path to the file with the adjency matrix
- second arg: number of threads