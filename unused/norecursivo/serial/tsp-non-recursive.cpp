// C++ program to solve Traveling Salesman Problem
// using Branch and Bound.
// Geek for Geeks
// #include <bits/stdc++.h>
#include <iostream>
// #include <omp.h>
#include <stack>
// include library that has floor function
#include <cmath>
#include <unistd.h>

using namespace std;
const int N = 4;

// final_path[] stores the final solution ie, the
// path of the salesman.
int final_path[N + 1];

// visited[] keeps track of the already visited nodes
// in a particular path
bool visited[N];

// Stores the final minimum weight of shortest tour.
int final_res = INT_MAX;

// Function to copy temporary solution to
// the final solution
void copyToFinal(stack<int> s)
{
    int temp;
    int i = 0;
    while (!s.empty())
    {
        temp = s.top();
        s.pop();
        final_path[i] = temp;
        i++;
    }
}

// Function to find the minimum edge cost
// having an end at the vertex i
int firstMin(int adj[N][N], int i)
{
    int min = INT_MAX;
    for (int k = 0; k < N; k++)
        if (adj[i][k] < min && i != k)
            min = adj[i][k];
    return min;
}

// function to find the second minimum edge cost
// having an end at the vertex i
int secondMin(int adj[N][N], int i)
{
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < N; j++)
    {
        if (i == j)
            continue;

        if (adj[i][j] <= first)
        {
            second = first;
            first = adj[i][j];
        }
        else if (adj[i][j] <= second &&
                 adj[i][j] != first)
            second = adj[i][j];
    }
    return second;
}

// function that takes as arguments:
// curr_bound -> lower bound of the root node
// curr_weight-> stores the weight of the path so far
// level-> current level while moving in the search
//		 space tree
// curr_path[] -> where the solution is being stored which
//			 would later be copied to final_path[]

// This function sets up final_path[]
void TSP(int adj[N][N])
{
    // Initialize curr_path as a stack structure
    // and push the first vertex in the path
    stack<int> curr_path;

    // Calculate initial lower bound for the root node
    // using the formula 1/2 * (sum of first min +
    // second min) for all edges.
    // Also initialize the curr_path and visited array
    int curr_bound = 0;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; i++)
        curr_bound += (firstMin(adj, i) + secondMin(adj, i));

    // Rounding off the lower bound to an integer value
    curr_bound = (int)floor(curr_bound / 2);

    // We start at vertex 1 so the first vertex
    // in curr_path[] is 0
    int curr_weight = 0;
    int level = 1;
    visited[0] = true;
    curr_path.push(0);
    // Call to TSPRec for curr_weight equal to
    // 0 and level
    // While curr_path is not empty
    int top_prev = 0;
    int temp_prev_wg = 0;
    int temp = 0;
    bool yamarque = true;
    
    while (!curr_path.empty())
    {
        int s = curr_path.top();

        cout << "\n\rInit Current top: " << s << " Current level: " << level << endl;
        curr_path.pop();
        
        usleep(1000000);

        // base case is when we have reached level N which
        // means we have covered all the nodes once
        if (level == N) // Level == N
        {
            printf("End of tree...\n");
            // check if there is an edge from last vertex in
            // path back to the first vertex in path
            if (adj[s][0] != 0)
            {
                printf("  Last node %d has connection to O\n", s);
                // curr_res has the total weight of the
                // solution we got
                int curr_res = curr_weight + adj[s][0];
                printf("  Curr Res: %d\n", curr_res);

                // Update final result and final path if
                // current result is better.
                if (curr_res < final_res)
                {
                    printf("Update path\n");
                    // Copy the current path to final_path
                    copyToFinal(curr_path);
                    final_res = curr_res;
                }                
            }

            // Else we have to prune the node by resetting
            // all changes to curr_weight and curr_bound

            curr_weight -= adj[s][temp_prev_wg];
            curr_bound = temp;
            printf("   Prev Curr weight: %d. - Prev Curr bound: %d\n", curr_weight, curr_bound);

            // Also reset the visited array
            visited[s] = false; // ver la forma de regresar, porq aqui lo marca como no visitado, entonces va a volvr entrar en el for
            // yamarque = false;
            // for loop to printf visited array
            printf("Visited Array: ");
            for (int i = 0; i < N; i++)
                printf("%d ", visited[i]);
            printf("\n");

            level--;
        }

        // for any other level iterate for all vertices to
        // build the search space tree recursively
        for (int i = 0; i < N; i++)
        {
            // Consider next vertex if it is not same (diagonal
            // entry in adjacency matrix and not visited
            // already)

            if (adj[s][i] != 0 && visited[i] == false)
            {
                temp = curr_bound;
                printf("\n\rInit bound: %d\n", temp);

                cout << "  For Current top: " << s << " to "<< i <<" . Current level: " << level << endl;

                curr_weight += adj[s][i]; // Add weight of edge
                temp_prev_wg = s;

                printf("   Curr weight: %d\n", curr_weight);

                // // Print all values in current path,
                // for (int j = 0; j < level; j++)
                //     printf("%d ", curr_path[j]);
                // Print omp task id

                // different computation of curr_bound for
                // level 2 from the other levels
                if (level == 1)
                    curr_bound -= ((firstMin(adj, s) + firstMin(adj, i)) /  2);
                else
                    curr_bound -= ((secondMin(adj, s) + firstMin(adj, i)) / 2);
                printf("   Actual bound: %d\n", curr_bound);

                // curr_bound + curr_weight is the actual lower bound
                // for the node that we have arrived on
                // If current lower bound < final_res, we need to explore
                // the node further
                if (curr_bound + curr_weight < final_res)
                {
                    curr_path.push(i);
                    visited[i] = true;
                }
                level++;
                s = curr_path.top();
            }
        }
    
    }
}

// Driver code
int main()
{
    // Initialize OMP environment
    // omp_set_num_threads(2);
    //Adjacency matrix for the given graph
    int adj[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    TSP(adj);

    printf("Minimum cost : %d\n", final_res);
    printf("Path Taken : ");
    for (int i = 0; i <= N; i++)
        printf("%d ", final_path[i]);

    return 0;
}
