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
    unordered_map<int, District> districts_origin;
    unordered_map<int, District> districts_destination;

    DistrictParser(string jsonPath) : JsonParser(jsonPath){

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

    void execute_TSP_secuencial() {
        /* Execute TSP */
        tsp();

        /* Print Result Path with Districts Names */
        cout << "Best tour by name is:" << endl;
        int i = 0;
        for (i = 0; i < n; i++) {
            cout << districts_origin.at(result_path[i]).name << " -> ";
        }
        cout << districts_origin.at(result_path[i]).name;
        cout << endl;
        cout << "-----------------------------------------" << endl;
    }

    void execute_TSP_paralelo() {
        /* Execute TSP */
        tsp_par();

        /* Print Result Path with Districts Names */
        cout << "Best tour by name is:" << endl;
        int i = 0;
        for (i = 0; i < n; i++) {
            cout << districts_origin.at(result_path[i]).name << " -> ";
        }
        cout << districts_origin.at(result_path[i]).name;
        cout << endl;
        cout << "-----------------------------------------" << endl;
    }

};


#endif  // PARSER_H