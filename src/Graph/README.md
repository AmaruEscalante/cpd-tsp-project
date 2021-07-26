
## Estructura de datos Graph

-   El grafo es dinámico (inserciones. eliminaciones, búsquedas, ...)
-   Se debe implementar los dos tipos de grafos: dirigidos y no-dirigidos.
-   No se consideran loops ni multi-arista.

### Metodos del grafo:

```cpp
bool insertVertex(string id, V data); // Creates a new vertex in the graph with some data and an ID

bool createEdge(string start, string end, E data); // Creates a new edge in the graph with some data

bool deleteVertex(string id); // Deletes a vertex in the graph

bool deleteEdge(string start, string end); // Deletes an edge in the graph, it is not possible to search by the edge value, since it can be repeated

E &operator()(string start, string end); // Gets the value of the edge from the start and end vertexes

float density() const; // Calculates the density of the graph

bool isDense(float threshold = 0.5) const; // Calculates the density of the graph, and determine if it is dense dependening on a threshold value

bool isConnected(); // Detect if the graph is connected

bool isStronglyConnected() throw(); // Detect if the graph is strongly connected (only for directed graphs)

bool empty(); // If the graph is empty

void clear(); // Clears the graph
```

### Creating graphs:

1. Crear un grafo no dirigido.

```cpp
UnDirectedGraph<char, int> graph;

graph.insertVertex(0, '0');
graph.insertVertex(1, '1');
graph.insertVertex(2, '2');
graph.insertVertex(3, '3');

graph.createEdge(0, 1, 10);
graph.createEdge(0, 3, 20);
graph.createEdge(0, 2, 15);
graph.createEdge(1, 3, 25);
graph.createEdge(3, 2, 30);
graph.createEdge(1, 2, 35);
graph.display();
```

1. Crear un grafo dirigido.

```
DirectedGraph<char, int> graph;

graph.insertVertex(0, '0');
graph.insertVertex(1, '1');
graph.insertVertex(2, '2');
graph.insertVertex(3, '3');

graph.createEdge(0, 1, 10);
graph.createEdge(1, 0, 10);
graph.createEdge(0, 3, 20);
graph.createEdge(3, 0, 20);
graph.createEdge(0, 2, 15);
graph.createEdge(2, 0, 15);
graph.createEdge(1, 3, 25);
graph.createEdge(3, 1, 25);
graph.createEdge(3, 2, 30);
graph.createEdge(2, 3, 30);
graph.createEdge(1, 2, 35);
graph.createEdge(2, 1, 35);
graph.display();
```

## Estructura de datos Vertex

- Cada vertice tiene un id y una lista de aristas.
- La estructura implementa se encuentra en `src/Graph/vertex.h`.


## Estructura de datos Edge

- Cada edge tiene un array de dos elementos correpsondiente a cada vertice.
- Cada edge posee el peso de la arista.
- La estructura implementa se encuentra en `src/Graph/edge.h`.
