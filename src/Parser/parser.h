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

struct City {
    int id;
    string name;
    double latitude;
    double longitude;
};

struct Airport {
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

class AirportParser : JsonParser {
   public:
    AirportParser(string jsonPath) : JsonParser(jsonPath){};

};


#endif  // PARSER_H