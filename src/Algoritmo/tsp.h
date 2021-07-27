#ifndef TSP_H
#define TSP_H

// `N` is the total number of total nodes on the graph or cities on the map
#ifdef SIZE
#undef N
#define N SIZE
#else
#define N 1024
#endif

extern int costMatrix[N][N];
extern int n;
extern int result_path[N];

int tsp();

#endif  // TSP_H