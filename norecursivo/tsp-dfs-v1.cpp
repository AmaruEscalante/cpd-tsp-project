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
#include <climits>
#include <chrono>
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

int main()
{
    stack<int> stack;
    vector<int> curr_tour;
    int city;

    // Input adjacency matrix
    std::cin >> n;                 // Receive number of cities
    for (size_t i = 0; i < n; i++) // Initialize adjacency matrix
        for (size_t j = 0; j < n; j++)
            std::cin >> costMatrix[i][j];

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
    // Print best tour
    std::cout << "Final path is :";
    for (int i = 0; i < n; i++)
    {
        std::cout << best[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Cost: " << best_cost << std::endl;
    // Print time taken
    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << " ms" << std::endl;

    return 0;
}