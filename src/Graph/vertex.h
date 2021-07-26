#ifndef VERTEX_H
#define VERTEX_H

#include <list>
#include <string>

#include "edge.h"

using namespace std;

template <typename TV, typename TE>
struct Edge;

template <typename TV, typename TE>
struct Vertex {
    TV data;
    double lat, lng;
    list<Edge<TV, TE>*> edges;

    friend ostream& operator<<(ostream& o, const Vertex<TV, TE>* objeto) {
        if (objeto == nullptr) {
            o << "Vertex not found!!!";
            return o;
        } else {
            o << objeto->data << ": ";
            for (auto ver : objeto->edges) {
                o << ver->vertexes[1]->data << "(" << ver->weight << ")"
                  << ", ";
            }
            return o;
        }
    }
};

#endif  // VERTEX_H

