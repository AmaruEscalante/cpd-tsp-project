#include <iostream>

#include "Parser/parser-json.h"

using namespace std;

int main(int argc, char* argv[]) {
    cout << "================================================" << endl;
    cout << "MENU TSP TESTER" << endl;
    cout << "================================================" << endl;

    DistrictParser<string, int> districtsparse(
        "/Users/jamesatachagua/Desktop/Proyectos/"
        "cpd-tsp-project/src/Parser/Data/maps_api_google.json");
    cout << endl;

    districtsparse.execute_TSP();

    return EXIT_SUCCESS;
}
