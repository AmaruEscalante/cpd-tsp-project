# How to compile

- MAC: g++ --std=c++17 -Xpreprocessor -fopenmp tsp-node-par.cpp -lomp -DSIZE=10
- LINUX: g++ -std=c++17 ../norecursivo/paralelo/tsp-node-par.cpp -fopenmp -lpthread -o tsp-node-par -DSIZE=4

# How to run
- ./a.out ../../tests/matrices/matrix_10.txt 4
- first arg: path to the file with the adjency matrix
- second arg: number of threads