#ifndef EDGE_H
#define EDGE_H

#include "vertex.h"

template <typename TV, typename TE>
struct Vertex;

template <typename TV, typename TE>
struct Edge {
    Vertex<TV, TE>* vertexes[2];
    TE weight;
};

#endif

