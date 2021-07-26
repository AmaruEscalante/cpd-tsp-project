#ifndef TRAVEL_H
#define TRAVEL_H

#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "../graph.h"
#include "../undirectedGraph.h"

using namespace std;

template <typename TV, typename TE>
class TRAVELPROBLEM {
   public:
    Graph<TV, TE>* Graph;
    Vertex<TV, TE>* v_init;

    struct tour_t
    {
        vector<Vertex<TV, TE>*> cities;
        TE cost;
    };

    tour_t *best_tour;

    TRAVELPROBLEM(::Graph<TV, TE>& Graph, TV init) {
        this->Graph = &Graph;
        if (this->Graph->type == 0) {
            this->v_init = this->Graph->findByData(init);
        } else if (this->Graph->type == 1) {
            this->v_init = this->Graph->findByData(init);
        } else {
            cout << "Error" << endl;
        }
    };

    tour_t *newTour(vector<Vertex<TV, TE>*> &cities, int cost)
    {
        tour_t *node = new tour_t;
        node->cities = cities;
        node->cost = cost;
        return node;
    }


    void add_city(tour_t *&tour, Vertex<TV, TE>* city)
    {
        // cout << "add city" << endl;
        // Add city to the tour
        int id1 = this->Graph->findByVertex(tour->cities.back());
        int id2 = this->Graph->findByVertex(city);
        tour->cost += this->Graph->getweigthEdge(id1, id2);
        tour->cities.push_back(city);
    }

    void remove_city(tour_t *&tour, Vertex<TV, TE>* city)
    {
        // cout << "remove city" << endl;
        // Remove last city from tour
        tour->cities.pop_back();
        int id1 = this->Graph->findByVertex(tour->cities.back());
        int id2 = this->Graph->findByVertex(city);
        int cost_edge = this->Graph->getweigthEdge(id1, id2);
        tour->cost -= cost_edge;
    }

    void push_copy(stack<tour_t *> &stack, tour_t *&tour)
    {
        tour_t *tmp = newTour(tour->cities, tour->cost);
        stack.push(tmp);
    }

    void update_best_tour(tour_t *&tour)
    {
        // cout << "update best tour" << endl;
        // Sum the cost back to the root node
        best_tour->cities = tour->cities;
        int id1 = this->Graph->findByVertex(tour->cities.back());
        int id2 = this->Graph->findByVertex(this->v_init);
        best_tour->cost = tour->cost + this->Graph->getweigthEdge(id1, id2);
    }

    bool feasible(tour_t *&tour, Vertex<TV, TE>* nbr)
    {
        bool lower_cost;
        TE current_tour_cost;

        // Feasible if city has already been visited
        if (find(tour->cities.begin(), tour->cities.end(), nbr) != tour->cities.end())
        {
            // cout << "  No visitado" << endl;
            return false;
        }
        // or it can lead to a least-cost tour
        int id1 = this->Graph->findByVertex(tour->cities.back());
        int id2 = this->Graph->findByVertex(nbr);
        TE cost_edge = this->Graph->getweigthEdge(id1, id2);
        current_tour_cost = tour->cost + cost_edge;
        // cout << "   cost: " << cost_edge << endl;
        // Check if the new tour is better than the best current one
        lower_cost = (current_tour_cost < best_tour->cost);

        return lower_cost;
    }
    

    bool is_best_tour(tour_t *&tour)
    {
        // cout << "is best tour" << endl;
        // Add cost from last node to root node
        TE last_mile_cost;
        // cout << "From: " << tour->cities.back()->data << " To: " << this->v_init->data << endl;
        int id1 = this->Graph->findByVertex(tour->cities.back());
        int id2 = this->Graph->findByVertex(this->v_init);
        last_mile_cost = tour->cost + this->Graph->getweigthEdge(id1, id2);

        if (last_mile_cost < best_tour->cost)
        {
            return true;
        }
        else
            return false;
    } 

    void apply() {
        
        stack<tour_t *> stack;

        // Initialize best tour
        vector<Vertex<TV, TE>*> best_tour_root;
        best_tour = newTour(best_tour_root, INT_MAX);

        // Initialize first tour
        vector<Vertex<TV, TE>*> root_cities;
        root_cities.push_back(this->v_init);
        tour_t *root = newTour(root_cities, 0); //cost = 0
    
        stack.push(root);

        // Main loop
        while (!stack.empty())
        {
            tour_t *curr_tour = stack.top();

            stack.pop();
            if (curr_tour->cities.size() == this->Graph->vertexes.size())
            {
                if (is_best_tour(curr_tour))
                {
                    update_best_tour(curr_tour);
                }
            }
            else
            {
                /* Iterate from first to last */
                // for (auto ver : curr_tour->cities.back()->edges) {
                //     cout << "  For Current top: " << curr_tour->cities.back()->data << " to "<< ver->vertexes[1]->data << endl;
                //     if (feasible(curr_tour, ver->vertexes[1]))
                //     {
                //         add_city(curr_tour, ver->vertexes[1]);
                //         push_copy(stack, curr_tour);
                //         remove_city(curr_tour, ver->vertexes[1]);
                //     }
                // }
                
                /* Iterate from last to first */
                for (auto ver = curr_tour->cities.back()->edges.crbegin(); ver != curr_tour->cities.back()->edges.crend(); ++ver) {
                    // cout << "  For Current top: " << curr_tour->cities.back()->data << " to "<< (*ver)->vertexes[1]->data << endl;
                    if (feasible(curr_tour, (*ver)->vertexes[1]))
                    {
                        add_city(curr_tour, (*ver)->vertexes[1]);
                        push_copy(stack, curr_tour);
                        remove_city(curr_tour, (*ver)->vertexes[1]);
                    }
                }
                
            }
            delete curr_tour;
        }

        // Output best tour
        std::cout << best_tour->cost << std::endl;
        for (size_t i = 0; i < best_tour->cities.size(); i++)
            std::cout << best_tour->cities[i]->data << " ";
        std::cout << this->v_init->data << std::endl;
    }
};

#endif
