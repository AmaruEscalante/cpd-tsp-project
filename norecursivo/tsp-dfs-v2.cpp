//
// Travelling Salesman Problem (TSP) with depth-first search second iterative version.
//
// Push copy(stack, tour); // Tour that visits only the hometown
// while (!Empty(stack))
// {
//     curr tour = Pop(stack);
//     if (City count(curr tour) == n)
//     {
//         if (Best tour(curr tour))
//             Update best tour(curr tour);
//     }
//     else
//     {
//         for (nbr = n − 1; nbr >= 1; nbr −− )
//             if (Feasible(curr tour, nbr))
//             {
//                 Add city(curr tour, nbr);
//                 Push copy(stack, curr tour);
//                 Remove last city(curr tour);
//             }
//     }
//     Free tour(curr tour);
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

// `N` is the total number of total nodes on the graph or cities on the map
#ifdef SIZE
#undef N
#define N SIZE
#else
#define N 10
#endif

using namespace std;

// tour data structure that stores
// - array storing the cities visited
// - the number of cities
// - the total distance of the tour
struct tour_t
{
    int cities[N];
    int size;
    int distance;
};

int main()
{
    vector<int> best;
    stack<int> s;
    int n;
    int costMatrix[N][N];

    // Input adjacency matrix
    std::cin >> n;                 // Receive number of cities
    for (size_t i = 0; i < n; i++) // Initialize adjacency matrix
        for (size_t j = 0; j < n; j++)
            std::cin >> costMatrix[i][j];
}