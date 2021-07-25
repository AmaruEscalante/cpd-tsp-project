#ifndef TESTER_H
#define TESTER_H

#include <assert.h>

#include <iostream>
#include <stdexcept>
#include <vector>

#include "../Graph/directedGraph.h"
#include "../Graph/undirectedGraph.h"
#include "../Parser/parser.h"
#include "../Graph/Algoritmos/kruskal.h"
#include "../Graph/Algoritmos/prim.h"
#include "../Graph/Algoritmos/depthfs.h"
#include "../Graph/Algoritmos/breadthfs.h"
#include "../Graph/Algoritmos/dijkstra.h"
#include "../Graph/Algoritmos/floydwarshall.h"
#include "../Graph/Algoritmos/bellmanford.h"
#include "../Graph/Algoritmos/astar.h"

using namespace std;

#define ASSERT(condition, message)                                                       \
    do {                                                                                 \
        if (!(condition)) {                                                              \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ << " line " \
                      << __LINE__ << ": " << message << std::endl;                       \
            std::terminate();                                                            \
        }                                                                                \
    } while (false)

class Tester {
   private:
    static void testDeleteVertex();
    static void testDeleteEdge();
    static void testDensity();
    static void testConnected();
    static void testStronglyConnected();
    static void testKruskal();

    static void testDFS_Dir(){
        DirectedGraph<char, float> graph;
        cout << " ------- Test DFS Directed ------- " << endl;
        graph.insertVertex(1, '0');
        graph.insertVertex(2, '1');
        graph.insertVertex(3, '2');
        graph.insertVertex(4, '3');
        graph.createEdge(1, 3, 4);// 0-2
        graph.createEdge(3, 1, 4);// 2-0
        graph.createEdge(1, 2, 4);// 0-1
        graph.createEdge(2, 3, 4);// 1-2
        graph.createEdge(2, 4, 4);// 1-3
        graph.createEdge(3, 3, 4);// 3-3
        graph.display();

        cout << "\nexecDFS() --> Init: 2 \n";
        DFS<char, float> DFS(graph, '2');
        Graph<char, float>* dsf = new DirectedGraph<char, float>();
        dsf = DFS.apply();
        dsf->display();
        DFS.displayresult();
    };

    static void testBFS_Dir(){
        DirectedGraph<char, float> graph;
        cout << " ------- Test BFS Directed ------- " << endl;
        graph.insertVertex(1, '0');
        graph.insertVertex(2, '1');
        graph.insertVertex(3, '2');
        graph.insertVertex(4, '3');
        graph.createEdge(1, 3, 2);//0-2
        graph.createEdge(3, 1, 1);//2-0
        graph.createEdge(1, 2, 3);//0-1
        graph.createEdge(2, 3, 4);//1-2
        graph.createEdge(3, 4, 1);//2-3
        graph.createEdge(4, 4, 2);//3-3
        graph.display();

        cout << "\nexecBFS()\n";
        BFS<char, float> BFS(graph, '2');
        Graph<char, float>* bfs = new DirectedGraph<char, float>();
        bfs = BFS.apply();
        bfs->display();
        BFS.displayresult();
    };

    static void testDisjktra_Dir(){
        DirectedGraph<char, float> graph;
        cout << " ------- Test Disjktra Directed ------- " << endl;
        graph.insertVertex(1, 's');
        graph.insertVertex(2, 't');
        graph.insertVertex(3, 'y');
        graph.insertVertex(4, 'x');
        graph.insertVertex(5, 'z');
        graph.createEdge(1, 2, 6);//0-5
        graph.createEdge(1, 3, 4);//0-4
        graph.createEdge(2, 3, 2);//5-4
        graph.createEdge(3, 2, 1);//4-5
        graph.createEdge(5, 1, 7);//7-0
        graph.createEdge(3, 5, 3);//4-7
        graph.createEdge(3, 4, 9);//4-13
        graph.createEdge(2, 4, 3);//5-13
        graph.createEdge(4, 5, 4);//13-7
        graph.createEdge(5, 4, 5);//7-13

        cout << "\nexecDijkstra()\n";
        Dijkstra<char, float> Dijkstra(graph, 's');
        // Graph<char, float> *dijs = new DirectedGraph<char, float>();
        unordered_map<Vertex<char, float>*, float> rd = Dijkstra.apply();
        Dijkstra.displayresult();
    }

    static void testFloyWarshal_Dir(){
        DirectedGraph<char, float> graph;
        cout << " ------- Test Floy Warshal Directed ------- " << endl;
        graph.insertVertex(1, '1');
        graph.insertVertex(2, '2');
        graph.insertVertex(3, '3');
        graph.insertVertex(4, '4');
        graph.createEdge(2, 1, 4);   // 2 - 1 | 4
        graph.createEdge(1, 3, -2);  // 1 - 3 | -2
        graph.createEdge(2, 3, 3);   // 2 - 3 | 3
        graph.createEdge(4, 2, -1);  // 4 - 2 | -1
        graph.createEdge(3, 4, 2);   // 3 - 4 | 2

        cout << "\nexecFloydWarshall()\n";
        FloydWarshall<char, float> FloydWarshall(graph);
        Graph<char, float>* fsf = new DirectedGraph<char, float>();
        fsf = FloydWarshall.apply();
        FloydWarshall.displayresult();
    }

    static void testBellmanFord_Dir(){
        DirectedGraph<char, float> graph;
        cout << " ------- Test BellmanFord Directed ------- " << endl;
        graph.insertVertex(1, 'A');
        graph.insertVertex(2, 'B');
        graph.insertVertex(3, 'C');
        graph.insertVertex(4, 'D');
        graph.insertVertex(5, 'E');
        graph.createEdge(1, 2, -1);//A-B
        graph.createEdge(1, 3, 4);//A-C
        graph.createEdge(2, 3, 3);//B-C
        graph.createEdge(4, 3, 5);//D-C
        graph.createEdge(4, 2, 1);//D-B
        graph.createEdge(2, 4, 2);//B-D
        graph.createEdge(5, 4, -3);//E-D
        graph.createEdge(2, 5, 2);//B-E

        cout << "\nexecBellmanFord()\n";
        BellmanFord<char, float> BellmanFord(graph, 'A');
        // Graph<char, float> *bf = new DirectedGraph<char, float>();
        unordered_map<Vertex<char, float>*, float> rb = BellmanFord.apply();
        BellmanFord.displayresult();
    }

    static void testBFS_DFS_UnDir(){
        UnDirectedGraph<string, float> graph;
        cout << " ------- Test BFS - DFS unDirected ------- " << endl;
        graph.insertVertex(1, "A");
        graph.insertVertex(2, "B");
        graph.insertVertex(3, "C");
        graph.insertVertex(4, "D");
        graph.insertVertex(5, "E");
        graph.insertVertex(6, "F");
        graph.insertVertex(7, "G");
        graph.insertVertex(8, "H");
        graph.insertVertex(9, "I");
        graph.createEdge(1, 2, 6); //A-B
        graph.createEdge(1, 5, 6); //A-E
        graph.createEdge(1, 3, 6); //A-C
        graph.createEdge(2, 3, 6); //B-C
        graph.createEdge(2, 4, 6); //B-D
        graph.createEdge(4, 3, 6); //D-C
        graph.createEdge(3, 5, 6); //C-E
        graph.createEdge(3, 6, 6); //C-F
        graph.createEdge(5, 8, 6); //E-H
        graph.createEdge(5, 7, 6); //E-G
        graph.createEdge(7, 9, 6); //G-I
        graph.createEdge(8, 9, 6); //H-I
        graph.display();

        cout << "\nexecDFS()\n";
        DFS<string, float> DFS(graph, "A");
        Graph<string, float>* dsf = new UnDirectedGraph<string, float>();
        dsf = DFS.apply();
        dsf->display();
        DFS.displayresult();

        cout << "\nexecBFS()\n";
        BFS<string, float> BFS(graph, "A");
        Graph<string, float>* bfs = new UnDirectedGraph<string, float>();
        bfs = BFS.apply();
        bfs->display();
        BFS.displayresult();
    }

    static void testPrimKruskal_UnDir(){
        UnDirectedGraph<string, float> graph;
        cout << " ------- Test Prim and Kuskal unDirected ------- " << endl;
        graph.insertVertex(1, "0");
        graph.insertVertex(2, "1");
        graph.insertVertex(3, "2");
        graph.insertVertex(4, "3");
        graph.insertVertex(5, "4");
        graph.createEdge(1, 3, 6);  // 0 - 2 | 6
        graph.createEdge(1, 2, 1);  // 0 - 1 | 1
        graph.createEdge(3, 2, 4);  // 2 - 1 | 4
        graph.createEdge(3, 4, 1);  // 2 - 3 | 1
        graph.createEdge(2, 4, 3);  // 1 - 3 | 3
        graph.createEdge(2, 5, 1);  // 1 - 4 | 1
        graph.createEdge(4, 5, 1);  // 3 - 4 | 1
        graph.display();

        cout << "\nexecPrim() --> Init: 0 \n";
        Prim<string, float> Prim(graph, "0");
        UnDirectedGraph<string, float> mstp = Prim.apply();
        mstp.display();

        cout << "\nexecKruskal()\n";
        Kruskal<string, float> kruskal(graph);
        UnDirectedGraph<string, float> mstk = kruskal.apply();
        mstk.display();
    }

    static void testBFS_UnDir(){
        UnDirectedGraph<string, float> graph;
        cout << " ------- Test BFS unDirected ------- " << endl;
        graph.insertVertex(1, "A");
        graph.insertVertex(2, "B");
        graph.insertVertex(3, "C");
        graph.insertVertex(4, "D");
        graph.insertVertex(5, "E");
        graph.insertVertex(6, "F");
        graph.insertVertex(7, "Z");
        graph.createEdge(1, 3, 3);   // A-C
        graph.createEdge(1, 2, 4);   // A-B
        graph.createEdge(2, 6, 5);   // B-F
        graph.createEdge(2, 5, 12);  // B-E
        graph.createEdge(3, 4, 7);   // C-D
        graph.createEdge(3, 5, 10);  // C-E
        graph.createEdge(4, 5, 2);   // D-E
        graph.createEdge(5, 7, 5);   // E-Z
        graph.createEdge(6, 7, 16);  // F-Z
        graph.display();

        cout << "\nexecBFS()\n";
        BFS<string, float> BFS(graph, "A");
        Graph<string, float>* bfs = new UnDirectedGraph<string, float>();
        bfs = BFS.apply();
        bfs->display();
        BFS.displayresult();
    };

    static void testDijskstra_UnDir(){
        UnDirectedGraph<string, float> graph;
        cout << " ------- Test Dijskstra unDirected ------- " << endl;
        graph.insertVertex(1, "A");
        graph.insertVertex(2, "B");
        graph.insertVertex(3, "C");
        graph.insertVertex(4, "D");
        graph.insertVertex(5, "E");
        graph.insertVertex(6, "F");
        graph.insertVertex(7, "Z");
        graph.createEdge(1, 3, 3); //A-C
        graph.createEdge(1, 2, 4); //A-B
        graph.createEdge(2, 6, 5); //B-F
        graph.createEdge(2, 5, 12); //B-E
        graph.createEdge(3, 4, 7); //C-D
        graph.createEdge(3, 5, 10); //C-E
        graph.createEdge(4, 5, 2); //D-E
        graph.createEdge(5, 7, 5); //E-Z
        graph.createEdge(6, 7, 16); //F-Z  

        cout << "\nexecDijkstra()\n";
        Dijkstra<string, float> Dijkstra(graph, "A");
        // Graph<string, float> *dijs = new UnDirectedGraph<string, float>();
        unordered_map<Vertex<string, float>*, float> result = Dijkstra.apply();
        Dijkstra.displayresult();
    }

    static void testAstar_UnDir(){
        UnDirectedGraph<string, float> graph;
        cout << " ------- Test Astar unDirected ------- " << endl;
        graph.insertVertex(1, "A");
        graph.insertVertex(2, "B");
        graph.insertVertex(3, "C");
        graph.insertVertex(4, "D");
        graph.insertVertex(5, "E");
        graph.insertVertex(6, "F");
        graph.insertVertex(7, "Z");
        graph.createEdge(1, 3, 3); //A-C
        graph.createEdge(1, 2, 4); //A-B
        graph.createEdge(2, 6, 5); //B-F
        graph.createEdge(2, 5, 12); //B-E
        graph.createEdge(3, 4, 7); //C-D
        graph.createEdge(3, 5, 10); //C-E
        graph.createEdge(4, 5, 2); //D-E
        graph.createEdge(5, 7, 5); //E-Z
        graph.createEdge(6, 7, 16); //F-Z     

        cout << "\nexecAStar()\n";
        AStar<string, float> AStar(graph, "A", "Z");
        // Graph<char, float> *bf = new DirectedGraph<char, float>();
        unordered_map<Vertex<string, float>*, float> ra = AStar.apply();
        AStar.displayresult();
    }

   public:
    static void executeExamples();
    static void executeParser();
};

#endif