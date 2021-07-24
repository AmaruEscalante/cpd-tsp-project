//
// Travelling Salesman Problem (TSP) with depth-first search first iterative version.
//
// for (city = n − 1; city >= 1; city −− )
//     Push(stack, city);
// while (!Empty(stack))
// {
//     city = Pop(stack);
//     if (city == NO CITY) // End of child list, back up
//         Remove last city(curr tour);
//     else
//     {
//         Add city(curr tour, city);
//         if (City count(curr tour) == n)
//         {
//             if (Best tour(curr tour))
//                 Update best tour(curr tour);
//             Remove last city(curr tour);
//         }
//         else
//         {
//             Push(stack, NO CITY);
//             for (nbr = n − 1; nbr >= 1; nbr −− )
//                 if (Feasible(curr tour, nbr))
//                     Push(stack, nbr);
//         }
//     }
//     /∗ if Feasible ∗/
// }
// /∗ while !Empty ∗/

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

int main()
{
    vector<int> best;
    stack<int> stack;
    vector<int> curr_tour;
    int n;
    int costMatrix[N][N];
    int city;

    // Input adjacency matrix
    std::cin >> n;                 // Receive number of cities
    for (size_t i = 0; i < n; i++) // Initialize adjacency matrix
        for (size_t j = 0; j < n; j++)
            std::cin >> costMatrix[i][j];

    // Initialize tree (best tour)
    for (city = n - 1; city >= 1; city--)
    {
        stack.push(city);
    }

    while (!stack.empty())
    {
        // Print city
        city = stack.top();
        // Remove city from stack
        stack.pop();
        // If city is the last one, back up
        if (city == N)
        {
            curr_tour.pop_back();
        }
        else
        {
            // Add city to tour
            curr_tour.push_back(city);
            // If tour is complete, check if it's the best tour
            if (curr_tour.size() == n)
            {
                if (best.size() == 0 || costMatrix[curr_tour[0]][curr_tour[n - 1]] < costMatrix[best[0]][best[n - 1]])
                {
                    best = curr_tour;
                }
            }
            else
            {
                stack.push(N);
                // Add cities to stack
                for (int nbr = n - 1; nbr >= 1; nbr--)
                {
                    if (costMatrix[curr_tour[nbr - 1]][curr_tour[nbr]] < costMatrix[curr_tour[nbr]][curr_tour[nbr - 1]])
                    {
                        stack.push(nbr);
                    }
                }
            }
        }
    }

    // Print best tour
    for (int i = 0; i < n; i++)
    {
        std::cout << best[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}