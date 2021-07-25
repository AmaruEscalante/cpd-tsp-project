// Peter Pacheco - An Introduction to Parallel Programming
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
#include <climits>
#include <chrono>
#include <cmath>
#include <iomanip>

#include "../../tests/readfiles.h"

// `N` is the total number of total nodes on the graph or cities on the map
#ifdef SIZE
#undef N
#define N SIZE
#else
#define N 10
#endif

using namespace std;

int n;
int costMatrix[N][N];
vector<int> best;
int best_cost = INT_MAX;

//
bool feasible(vector<int> &tour, int nbr)
{
    // Feasible if city has already been visited
    // or it can lead to a least-cost tour
    // iterator of tour
    bool lower_cost;

    if (find(tour.begin(), tour.end(), nbr) != tour.end())
    {
        return false;
    }

    // Calculate the cost of the tour so far
    int cost = 0;
    for (int i = 0; i < tour.size() - 1; i++)
    {
        cost += costMatrix[tour[i]][tour[i + 1]];
    }

    int cost_to_nbr = costMatrix[tour[tour.size() - 1]][nbr];
    // If the cost is less than the best cost,
    // then the tour is feasible
    lower_cost = (cost + cost_to_nbr < best_cost) ? true : false;

    return lower_cost;
}

bool best_tour(vector<int> &tour)
{
    // Calculate the cost of the tour so far and check if it is better than the best cost
    int cost = 0;
    for (int i = 0; i < tour.size() - 1; i++)
    {
        cost += costMatrix[tour[i]][tour[i + 1]];
    }

    // Add cost from last node to root node
    cost += costMatrix[tour[tour.size() - 1]][0];

    if (cost < best_cost)
    {
        best_cost = cost;
        return true;
    }
    else
        return false;
}

void add_city(vector<int> &tour, int city)
{
    //    if (find(tour.begin(), tour.end(), city) != tour.end())
    //    {
    //        return;
    //    }
    //    else{
    tour.push_back(city);
    //    }
}

int main(int argc, char *argv[])
{
    /* Read Files and Set variables */
    int result_to_compare[N + 1];
    int result_cost_to_compare;
    read_matrix_and_result_from_file(argv[1], &n, &result_cost_to_compare, costMatrix, result_to_compare);

    /* Create stack */
    stack<int> stack;
    vector<int> curr_tour;
    int city;

    auto start = std::chrono::high_resolution_clock::now();
    // Initialize tree (best tour)
    for (city = n - 1; city >= 1; city--)
    {
        stack.push(city);
    }
    curr_tour.push_back(0);
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
            add_city(curr_tour, city);
            // If tour is complete, check if it's the best tour
            if (curr_tour.size() == n)
            {
                if (best_tour(curr_tour))
                {
                    best = curr_tour;
                }
                curr_tour.pop_back();
            }
            else
            {
                stack.push(N);
                // Add cities to stack
                for (int nbr = n - 1; nbr >= 1; nbr--)
                {
                    if (feasible(curr_tour, nbr))
                    {
                        stack.push(nbr);
                    }
                }
            }
        }
    }
    auto stop = std::chrono::high_resolution_clock::now();

    int result_tsp[N + 1]; // use to set the result vecto to array

    // Print best tour
    std::cout << "Best tour is: " << endl;
    for (int i = 0; i < n; i++) {
        std::cout << best[i] << " ";
        result_tsp[i] = best[i];
    }
    std::cout << best[0] << " ";
    result_tsp[N] = best[0];
    std::cout << std::endl;
    std::cout << "Best tour cost is: " << best_cost << std::endl;

    // Print time taken
    auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    print_time(time);

    // Test if the result is correct
    test(result_tsp, result_to_compare, best_cost, result_cost_to_compare);

    return 0;
}