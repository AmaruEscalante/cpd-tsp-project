# Folder Contains develop parallel and serial TSP BB

# How to compile

The -DSIZE flag define the matrix size.

## Serial

- MAC & Linux: g++ --std=c++17 <name_file_cpp> -DSIZE=10

## Parallel

- MAC: g++ --std=c++17 -Xpreprocessor -fopenmp <name_file_cpp> -lomp -DSIZE=10
- Linux: g++ -std=c++17 <name_file_cpp> -fopenmp -lpthread -o par-dfs-v2-tsp -DSIZE=4

# How to run

- <name_compiled_file> <file_with_matrix> <number_threads>

    - <file_with_matrix> : path to the file with the adjency matrix

    - <number_threads>: number of threads

- Example: - ./par-dfs-v2-tsp ../../tests/matrices/matrix_10.txt 4