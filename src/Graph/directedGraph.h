#ifndef NONDIRECTEDGRAPH_H
#define NONDIRECTEDGRAPH_H

#include "graph.h"
using namespace std;

template <typename TV, typename TE>
class DirectedGraph : public Graph<TV, TE> {
   public:
    DirectedGraph() { this->type = 1; }

   private:
    /* Función para realizar la comparación al momento de ordenar el array graphedges */
    static bool compare_nocase(const Edge<TV, TE>* first, const Edge<TV, TE>* second) {
        return first->weight < second->weight;
    }

   public:
    bool insertVertex(int id, TV vertex) {
        // this->vertexes.insert(make_pair(id, vertex));
        if (!findById(id)) {
            Vertex<TV, TE>* v = new Vertex<TV, TE>();
            v->data = vertex;
            this->vertexes[id] = v;
            return true;
        } else {
            // cout << "Ya existe el vertice" << endl;
            return false;
        }
    }

    bool insertVertex(int id, TV vertex, double lat, double lng) {
        // this->vertexes.insert(make_pair(id, vertex));
        if (!findById(id)) {
            Vertex<TV, TE>* v = new Vertex<TV, TE>();
            v->data = vertex;
            v->lat = lat;
            v->lng = lng;
            this->vertexes[id] = v;
            return true;
        } else {
            // cout << "Ya existe el vertice" << endl;
            return false;
        }
    }

    /* Direccion solo id1 -> id2 */
    bool createEdge(int id1, int id2, TE w) {
        // Se obtienen los vertices de la lista vertexes
        Vertex<TV, TE>* v1 = this->vertexes.at(id1);
        Vertex<TV, TE>* v2 = this->vertexes.at(id2);

        if (!searchEdge(id1, id2)) {
            // Se añade un nuevo edge al vertices con id1
            Edge<TV, TE>* e = new Edge<TV, TE>();
            e->weight = w;
            e->vertexes[0] = v1;
            e->vertexes[1] = v2;
            v1->edges.push_back(e);

            // Se añade a la lista de aristas del grafo
            this->graphedges.push_front(e);

            return true;
        } else {
            cout << "Ya existe el Edge" << endl;
            return false;
        }
    }

    bool deleteVertex(int id) {
        if (findById(id)) {
            Vertex<TV, TE>* vertex2remove = this->vertexes.at(id);
            // cout << "Data: " << vertex2remove->data << endl;

            for (auto edge : vertex2remove->edges) {
                this->graphedges.remove(edge);
            }

            // Create a copy of graphedges to delete edges
            list<Edge<TV, TE>*> graphedges_copy;
            graphedges_copy = this->graphedges;
            // Find edges that end = vertex2remove, and delete
            // in graphedges and in edges list of this vertex
            for (auto edge : graphedges_copy) {
                // cout << edge->vertexes[0]->data << " -> " << edge->vertexes[1]->data << endl;
                if (edge->vertexes[1] == vertex2remove) {
                    // cout << edge->vertexes[0]->data << " -> " << edge->vertexes[1]->data << endl;
                    edge->vertexes[0]->edges.remove(edge);
                    this->graphedges.remove(edge);
                }
            }

            /* Crear el destructor de Vertex */
            this->vertexes.erase(id);

            return true;
        } else {
            cout << "Can not delete vertex " << id << endl;
            return false;
        }
    }

    // Se supone que solo existe la dirección start -> end
    bool deleteEdge(int start, int end) {
        if (searchEdge(start, end)) {
            Vertex<TV, TE>* vertex2remove_1 = this->vertexes.at(start);
            Vertex<TV, TE>* vertex2remove_2 = this->vertexes.at(end);

            Edge<TV, TE>* edge2remove = new Edge<TV, TE>();

            // delete start -> end
            for (auto edge : vertex2remove_1->edges) {
                if (edge->vertexes[1] == vertex2remove_2) {
                    edge2remove = edge;
                }
            }
            vertex2remove_1->edges.remove(edge2remove);
            // se elimina el edge en la lista para kruskal
            this->graphedges.remove(edge2remove);

            return true;
        } else {
            cout << "Can not delete edge " << start << "->" << end << endl;
            return false;
        }
    }

    float density() {
        if (empty()) {
            // throw "The graph is empty";
            return 0.0;
        } else {
            float a = this->graphedges.size();
            float b = this->vertexes.size() * (this->vertexes.size() - 1);
            return a / b;
        }
    }

    bool isDense(float threshold = 0.5) {
        if (density() >= threshold) {
            return true;
        } else {
            return false;
        }
    }

    // saber si el grafo es conexo, se puede usar disjoin set (si existen 2 DS es no conexo)
    bool isConnected() {
        throw "This is a directed graph";
        return false;
    };

    /* Revisar: https://www.geeksforgeeks.org/connectivity-in-a-directed-graph/ */
    bool isStronglyConnected() {
        // TODO
        return false;
    }

    bool empty() {
        // El grafo puede tener vertices, pero si no tiene aristas es vacio
        if (this->graphedges.empty()) {
            return true;
        } else {
            return false;
        }
    }

    // TODO
    void clear() {}

    Vertex<TV, TE>* displayVertex(int id) {
        try {
            Vertex<TV, TE>* v = this->vertexes.at(id);
            return v;
        } catch (const out_of_range& e) {
            // cout << "Vertex not found!!!" << endl;
            return nullptr;
        }
    };

    /* Funcion para determinar si existe el vértice en el árbol por id */
    bool findById(int id) {
        if (this->vertexes.find(id) == this->vertexes.end())
            return false;
        else
            return true;
    };

    /* Funcion para mostrar cada vértice del arbol con sus respectivas aristas */
    void display() {
        for (auto x : this->vertexes) {
            Vertex<TV, TE>* tmp = x.second;
            std::cout << tmp->data << ": ";
            for (auto ver : tmp->edges) {
                std::cout << ver->vertexes[1]->data << "(" << ver->weight << ")"
                          << ", ";
            }
            std::cout << std::endl;
        }
    };

    /* Extra functions */
    /* Funcion para determinar si existe el vértice en el árbol por el mismo vértice */
    int findByVertex(Vertex<TV, TE>* v) {
        typename unordered_map<int, Vertex<TV, TE>*>::iterator itr;
        for (itr = this->vertexes.begin(); itr != this->vertexes.end(); itr++) {
            if (itr->second == v) return itr->first;
        }
        cout << "no" << endl;
        return -1;
    }

    /* Funcion para determinar si existe el vértice en el árbol por el mismo vértice */
    Vertex<TV, TE>* findByData(TV data) {
        typename unordered_map<int, Vertex<TV, TE>*>::iterator itr;
        for (itr = this->vertexes.begin(); itr != this->vertexes.end(); itr++) {
            if (itr->second->data == data) return itr->second;
        }
        return nullptr;
    }

    bool searchEdge(int id1, int id2) {
        // Se obtienen los vertices de la lista vertexes
        Vertex<TV, TE>* v1 = this->vertexes.at(id1);
        Vertex<TV, TE>* v2 = this->vertexes.at(id2);
        // cout << "Finding..."<< endl;
        for (auto edges_ : this->graphedges) {
            if (((edges_->vertexes[0]->data == v1->data) &&
                 (edges_->vertexes[1]->data == v2->data))) {
                return true;
            }
            // cout << edges_->vertexes[0]->data << " " << edges_->vertexes[1]->data << endl;
        }
        return false;
    };

    TE getweigthEdge(int id1, int id2) {
        // Se obtienen los vertices de la lista vertexes
        Vertex<TV, TE>* v1 = this->vertexes.at(id1);
        Vertex<TV, TE>* v2 = this->vertexes.at(id2);
        // cout << "Finding..."<< endl;
        for (auto edges_ : this->graphedges) {
            if (((edges_->vertexes[0]->data == v1->data) &&
                 (edges_->vertexes[1]->data == v2->data))) {
                return edges_->weight;
            }
            // cout << edges_->vertexes[0]->data << " " << edges_->vertexes[1]->data << endl;
        }
        return -1.5;
    };
};

#endif