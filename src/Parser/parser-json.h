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

using namespace std;
using json = nlohmann::json;

struct District {
    string id;
    string name;
    string city;
    string country;
    double latitude;
    double longitude;
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
        int N = 4;
        int costMatrix[N][N];

        for (auto& element : data) {
            District a;
            a.id = element["Airport ID"];
            int id_int = stoi(a.id);
            a.city = element["City"];
            a.country = element["Country"];
            a.name = element["Name"];
            string lat = element["Latitude"];
            string lng = element["Longitude"];
            a.latitude = stod(lat);
            a.longitude = stod(lng);

            for (auto& [key, value] : element["destinations"].items()) {
                int id_dest = stoi(key);
                costMatrix[id_int][id_dest] = value;
            }
        }

        // for (auto& [key, value] : element["destinations"].items()) {
        //     int id_dest = stoi(key);
        //     costMatrix[id_int][N] = value;
        // }

        /* Print matrix to check correct parser */
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    costMatrix[i][j] = INT_MAX;
                }
                cout << costMatrix[i][j] << " ";
            }
            cout << endl;
        }
    };

};


#endif  // PARSER_H