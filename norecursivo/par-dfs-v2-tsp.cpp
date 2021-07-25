//
// Travelling Salesman Problem (TSP) with depth-first search second iterative version using OpenMP.
//
// Partition tree(my rank, my stack);
// while (!Empty(my stack))
// {
//     curr tour = Pop(my stack);
//     if (City count(curr tour) == n)
//     {
//         if (Best tour(curr tour))
//             Update best tour(curr tour);
//     }
//     else
//     {
//         for (city = n − 1; city >= 1; city −− )
//             if (Feasible(curr tour, city))
//             {
//                 Add city(curr tour, city);
//                 Push copy(my stack, curr tour);
//                 Remove last city(curr tour)
//             }
//     }
//     Free tour(curr tour);
// }

// Push copy function
// void Push copy(my stack t stack, tour t tour)
// {
//     int loc = stack − > list sz;

//     tour t tmp = Alloc tour();
//     Copy tour(tour, tmp);
//     stack − > list[loc] = tmp;
//     stack − > list sz++;
//     /∗ Push ∗/
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <chrono>
#include <omp.h>

// `N` is the total number of total nodes on the graph or cities on the map
#ifdef SIZE
#undef N
#define N SIZE
#else
#define N 10
#endif

using namespace std;

struct tour_t;

int n;
int costMatrix[N][N];
tour_t *best_tour;

// tour data structure that stores
// - array storing the cities visited
// - the number of cities
// - the total distance of the tour
struct tour_t
{
    vector<int> cities;
    int cost;
};

tour_t *newTour(vector<int> &cities, int cost)
{
    tour_t *node = new tour_t;
    node->cities = cities;
    node->cost = cost;
    return node;
}

void add_city(tour_t *&tour, int city)
{
    // Add city to the tour
    tour->cost += costMatrix[tour->cities.back()][city];
    tour->cities.push_back(city);
}

void remove_city(tour_t *&tour, int city)
{
    // Remove last city from tour
    tour->cities.pop_back();
    tour->cost -= costMatrix[tour->cities.back()][city];
}

void push_copy(stack<tour_t *> &stack, tour_t *&tour)
{
    tour_t *tmp = newTour(tour->cities, tour->cost);
    stack.push(tmp);
}

bool is_best_tour(tour_t *&tour)
{
    // Add cost from last node to root node
    int last_mile_cost;
    last_mile_cost = tour->cost + costMatrix[tour->cities.back()][tour->cities.front()];

    if (last_mile_cost < best_tour->cost)
    {
        return true;
    }
    else
        return false;
}

void update_best_tour(tour_t *&tour)
{
    // Sum the cost back to the root node
    best_tour->cities = tour->cities;
    best_tour->cost = tour->cost + costMatrix[tour->cities.back()][tour->cities.front()];
}

bool feasible(tour_t *&tour, int nbr)
{
    bool lower_cost;
    int current_tour_cost;

    // Feasible if city has already been visited
    if (find(tour->cities.begin(), tour->cities.end(), nbr) != tour->cities.end())
    {
        return false;
    }
    // or it can lead to a least-cost tour
    current_tour_cost = tour->cost + costMatrix[tour->cities.back()][nbr];
    // Check if the new tour is better than the best current one
    lower_cost = (current_tour_cost < best_tour->cost);

    return lower_cost;
}

int main()
{
    stack<tour_t *> root_stack;
    stack<tour_t *> my_stack;

    // Initialize threads
    omp_set_num_threads(4);

    // Input adjacency matrix
    std::cin >> n;                 // Receive number of cities
    for (size_t i = 0; i < n; i++) // Initialize adjacency matrix
        for (size_t j = 0; j < n; j++)
            std::cin >> costMatrix[i][j];

    // Initialize best tour
    vector<int> best_tour_root;
    best_tour = newTour(best_tour_root, INT_MAX);

    // Initialize first tour
    vector<int> root_cities;
    root_cities.push_back(0);
    tour_t *root_tour = newTour(root_cities, 0);
    //root_stack.push(root);

    // Initialize thread-local best tour
#pragma omp parallel private(my_stack)
    {
#pragma omp for
        for (int i = 1; i < N; i++)
        {
            tour_t *local_tour = newTour(root_cities, 0);
            add_city(local_tour, i);
            my_stack.push(local_tour);
        }
        // Main loop
        while (!my_stack.empty())
        {
            tour_t *curr_tour = my_stack.top();
            my_stack.pop();
            if (curr_tour->cities.size() == n)
            {
                if (is_best_tour(curr_tour))
                {
#pragma omp critical
                    {
                        if (is_best_tour(curr_tour))
                        {
                            update_best_tour(curr_tour);
                        }
                    }
                }
            }
            else
            {
                for (int nbr = n - 1; nbr >= 1; nbr--)
                {
                    if (feasible(curr_tour, nbr))
                    {
                        add_city(curr_tour, nbr);
                        push_copy(my_stack, curr_tour);
                        remove_city(curr_tour, nbr);
                    }
                }
            }
            delete curr_tour;
        }
    }
    // Output best tour
    std::cout << best_tour->cost << std::endl;
    for (size_t i = 0; i < best_tour->cities.size(); i++)
        std::cout << best_tour->cities[i] << " ";
    std::cout << std::endl;

    return 0;
}