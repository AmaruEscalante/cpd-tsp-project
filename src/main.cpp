#include <iostream>

#include "Parser/parser-json.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "================================================" << endl;
    cout << "MENU TSP TESTER" << endl;
    cout << "================================================" << endl;

    DistrictParser<string, int> districtsparse(
        "maps_api_google.json");
    cout << endl;

    cout << "================================================" << endl;
    cout << "Ejecución TSP secuencial" << endl;
    cout << "================================================" << endl;
    districtsparse.execute_TSP_secuencial();
    cout << endl;
    
    cout << "================================================" << endl;
    cout << "Ejecución TSP Paralelo" << endl;
    cout << "================================================" << endl;
    districtsparse.execute_TSP_paralelo();

    return EXIT_SUCCESS;
}
