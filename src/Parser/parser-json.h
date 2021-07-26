#ifndef PARSER_H
#define PARSER_H

#include <math.h>
#include <stdlib.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
// #include <nlohmann/json.hpp>
#include "json.hpp"
#include "../Algoritmo/tsp.h"
using namespace std;
using json = nlohmann::json;

struct District {
    string id;
    string name;
    // string city;
    // string country;
    double duration;
    double distance;
};

class JsonParser {
   protected:
    string jsonPath;
    json data;

   public:
    JsonParser(string jsonPath) {  // readJSON()
        ifstream file(jsonPath);
        data = json::parse(file);
    }
};

template <typename TV, typename TE>
class DistrictParser : JsonParser {
   public:
    DistrictParser(string jsonPath) : JsonParser(jsonPath){

        unordered_map<int, District> districts_origin;
        unordered_map<int, District> districts_destination;

        /* Get row of matrix */
        int id_origin = 0;
        for (auto& [key, value] : data["origin_addresses"].items()) {
            District a;
            a.name = value;
            districts_origin[id_origin] = a;
            id_origin++;
        }

        /* Get column of matrix */
        int id_destination = id_origin;
        for (auto& [key, value] : data["destination_addresses"].items()) {
            District a;
            a.name = value;
            districts_destination[id_destination] = a;
            id_destination++;
        }

        n = id_origin; /* Set size to execute TSP */
        
        id_origin = 0;
        for (auto& element_rows : data["rows"]) {
            id_destination = 0;
            for (auto& values : element_rows["elements"]) {
                // cout << values << endl;
                // cout << id_origin << " " << id_destination << " " << values["distance"]["value"] << endl;
                costMatrix[id_origin][id_destination] = values["distance"]["value"];
                id_destination++;
            }
            id_origin++;
        }

        /* Print matrix to check correct parser */
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << costMatrix[i][j] << " ";
            }
            cout << endl;
        }        
    };

    void execute_TSP() {
        /* Execute TSP */
        tsp();
    }

};


#endif  // PARSER_H