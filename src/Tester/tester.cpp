#include "tester.h"

void Tester::testTSP(){
    /* Graph from geek for geeks
        * https://www.geeksforgeeks.org/traveling-salesman-problem-using-branch-and-bound-2/
        */
    UnDirectedGraph<char, int> graph;
    cout << " ------- Test Travel Salesman Problem unDirected ------- " << endl;
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

    cout << "\nTravel()\n";
    TRAVELPROBLEM<char, int> TRAVELPROBLEM(graph, '0');
    TRAVELPROBLEM.apply();
    cout << endl;
}

void Tester::testTSP_Parser1(){
    /* Graph from geek for geeks, but as a JSON file
        * https://www.geeksforgeeks.org/traveling-salesman-problem-using-branch-and-bound-2/
        */
    cout << " ------- Test Travel Salesman Problem with Parser unDirected Graph ------- " << endl;
    cout << "Reading ejemplo1.json\n";

    DistritParser<string, int> districtsparse(
        "/Users/jamesatachagua/Desktop/Proyectos/"
        "graph-project-electrogatos/src/Parser/Data/ejemplo1.json");
    cout << endl;

    UnDirectedGraph<string, int> districts;
    districtsparse.uGraphMake(districts);

    cout << "Display unDirected Graph\n";
    districts.display();

    cout << "\nTravel()\n";
    TRAVELPROBLEM<string, int> TRAVELPROBLEM(districts, "0");
    TRAVELPROBLEM.apply();
    cout << endl;
}

void Tester::testTSP_Parser2(){
    /* Graph from youtube, but as a JSON file
        * https://www.youtube.com/watch?v=1FEP_sNb62k
        */
    cout << " ------- Test Travel Salesman Problem with Parser Directed Graph ------- " << endl;
    cout << "Reading ejemplo2.json\n";

    DistritParser<string, int> districtsparse(
        "/Users/jamesatachagua/Desktop/Proyectos/"
        "graph-project-electrogatos/src/Parser/Data/ejemplo2.json");
    cout << endl;

    DirectedGraph<string, int> districts_d;
    districtsparse.dGraphMake(districts_d);

    cout << "Display unDirected Graph\n";
    districts_d.display();

    cout << "\nTravel()\n";
    TRAVELPROBLEM<string, int> TRAVELPROBLEM(districts_d, "1");
    TRAVELPROBLEM.apply();
    cout << endl;
}