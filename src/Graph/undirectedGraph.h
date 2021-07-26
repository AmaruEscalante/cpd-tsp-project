#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "graph.h"

using namespace std;

template <typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE> {
   public:
    UnDirectedGraph() { this->type = 0; }

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
            // v1->edges.sort(compare_nocase);

            // Se añade a la lista de aristas del grafo
            this->graphedges.push_front(e);

            // Se añade un nuevo edge al vertices con id2
            Edge<TV, TE>* e2 = new Edge<TV, TE>();
            e2->weight = w;
            e2->vertexes[0] = v2;
            e2->vertexes[1] = v1;
            v2->edges.push_back(e2);
            // v2->edges.sort(compare_nocase);
            return true;
        } else {
            // cout << "Ya existe el Edge" << endl;
            return false;
        }
    }

    bool deleteVertex(int id) {
        if (findById(id)) {
            Vertex<TV, TE>* vertex2remove = this->vertexes.at(id);
            // cout << "Data: " << vertex2remove->data << endl;

            /* Por cada arista del vertex(id) hay que eliminar la union del otro vertex */
            Edge<TV, TE>* edge2remove = new Edge<TV, TE>();
            for (auto edge : vertex2remove->edges) {
                // cout << "Vertex->: " << edge->vertexes[1]->data << endl;
                // Se elimina el sentido contrario de la arista
                for (auto EdgeOfVertex : edge->vertexes[1]->edges) {
                    if (EdgeOfVertex->vertexes[1] == vertex2remove) {
                        // cout << "Vertex1 of edge->: " << EdgeOfVertex->vertexes[1]->data << endl;
                        edge2remove = EdgeOfVertex;
                    }
                }
                // se elimina el edge en la lista para kruskal
                this->graphedges.remove(edge);
                this->graphedges.remove(edge2remove);

                // se elemina el edge en la propia lista de edges del vertice
                edge->vertexes[1]->edges.remove(edge2remove);
            }

            /* Se elimina el Vertex en la lista*/
            this->vertexes.erase(id);
            return true;
        } else {
            cout << "Can not delete vertex " << id << endl;
            return false;
        }
    }

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

            // delete end -> start
            edge2remove = nullptr;
            for (auto edge : vertex2remove_2->edges) {
                if (edge->vertexes[1] == vertex2remove_1) {
                    edge2remove = edge;
                }
            }
            vertex2remove_2->edges.remove(edge2remove);
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
            // cout << this->graphedges.size() << " " << this->vertexes.size() << endl;
            float a = 2 * this->graphedges.size();
            float b = this->vertexes.size() * (this->vertexes.size() - 1);
            // cout << a << " " << b << endl;
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
    bool isConnected() {  // Need to fix
        // cout << this->total_sets << endl;
        if (this->total_sets == -1) {
            cout << "Kruskal not executed" << endl;
            return false;
        } else {
            return this->total_sets <= 1;
        }
    };

    bool isStronglyConnected() {
        throw "This is a undirected graph";
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
                 (edges_->vertexes[1]->data == v2->data)) ||
                ((edges_->vertexes[1]->data == v1->data) &&
                 (edges_->vertexes[0]->data == v2->data))) {
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
                 (edges_->vertexes[1]->data == v2->data)) ||
                ((edges_->vertexes[1]->data == v1->data) &&
                 (edges_->vertexes[0]->data == v2->data))) {
                return edges_->weight;
            }
            // cout << edges_->vertexes[0]->data << " " << edges_->vertexes[1]->data << endl;
        }
        return -1.5;
    };

    /* Funcion para mostrar cada vértice del arbol con sus respectivas aristas */
    void displaybyID() {
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
};

#endif