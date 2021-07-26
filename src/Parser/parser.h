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

struct Distrit {
    string id;
    string name;
    string city;
    string country;
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
class AirportParser : JsonParser {
   public:
    AirportParser(string jsonPath) : JsonParser(jsonPath){};
    unordered_map<int, Airport> airports;

    void uGraphMake(UnDirectedGraph<TV, TE>& tempGraph) {
        // Create Vertexes
        for (auto& element : data) {
            Airport a;
            a.id = element["Airport ID"];
            int id_int = stoi(a.id);
            string lat = element["Latitude"];
            string lng = element["Longitude"];
            a.city = element["City"];
            a.country = element["Country"];
            a.name = element["Name"];
            a.latitude = stod(lat);
            a.longitude = stod(lng);

            tempGraph.insertVertex(id_int, a.id);
            this->airports[id_int] = a;
        }
        // Create Edges
        for (auto& element : data) {
            string id_origen = element["Airport ID"];
            Airport origen = this->airports.at(stoi(id_origen));

            for (auto dest : element["destinations"]) {
                string id_dest = dest;
                try {
                    Airport destination = this->airports.at(stoi(id_dest));
                    double de = calculateDistanceAirports(&origen, &destination);
                    TE dde = de; // convert to TE
                    tempGraph.createEdge(stoi(id_origen), stoi(id_dest), dde);
                } catch (const out_of_range& e) {
                    cerr << "Exception at " << e.what() << endl;
                    cerr << "  Destination not found!!!" << endl;
                }
            }
        }
    };

    void dGraphMake(DirectedGraph<TV, TE>& tempGraph) {
        // Create Vertexes
        for (auto& element : data) {
            Airport a;
            a.id = element["Airport ID"];
            int id_int = stoi(a.id);
            string lat = element["Latitude"];
            string lng = element["Longitude"];
            a.city = element["City"];
            a.country = element["Country"];
            a.name = element["Name"];
            a.latitude = stod(lat);
            a.longitude = stod(lng);

            tempGraph.insertVertex(id_int, a.id);  // For simplicity
            this->airports[id_int] = a;
        }

        // Create Edges
        for (auto& element : data) {
            string id_origen = element["Airport ID"];
            Airport origen = this->airports.at(stoi(id_origen));

            for (auto dest : element["destinations"]) {
                string id_dest = dest;
                try {
                    Airport destination = this->airports.at(stoi(id_dest));
                    double de = calculateDistanceAirports(&origen, &destination);
                    tempGraph.createEdge(stoi(id_origen), stoi(id_dest), de);
                } catch (const out_of_range& e) {
                    cerr << "Exception at " << e.what() << endl;
                    cerr << "  Destination not found!!!" << endl;
                }
            }
        }
    };

   private:
    double calculateDistanceAirports(Airport* origin, Airport* destination) {
        return sqrt(pow((destination->longitude - origin->longitude), 2.0) +
                    pow((destination->latitude - origin->latitude), 2.0));
    }
};

template <typename TV, typename TE>
class DistritParser : JsonParser {
   public:
    DistritParser(string jsonPath) : JsonParser(jsonPath){};
    unordered_map<int, Distrit> distrits;

    void uGraphMake(UnDirectedGraph<TV, TE>& tempGraph) {
        // Create Vertexes
        for (auto& element : data) {
            Distrit a;
            a.id = element["Airport ID"];
            int id_int = stoi(a.id);
            a.city = element["City"];
            a.country = element["Country"];
            a.name = element["Name"];


            tempGraph.insertVertex(id_int, a.id);
            this->distrits[id_int] = a;
        }
        // Create Edges
        for (auto& element : data) {
            string id_origen = element["Airport ID"];
            Distrit origen = this->distrits.at(stoi(id_origen));

            for (auto& [key, value] : element["destinations"].items()) {
                try {
                    Distrit destination = this->distrits.at(stoi(key));
                    string id_dest = key;
                    TE de = 0;
                    // std::cout << id_origen << " " << key << " : " << value << "\n";
                    tempGraph.createEdge(stoi(id_origen), stoi(id_dest), value);
                } catch (const out_of_range& e) {
                    cerr << "Exception at " << e.what() << endl;
                    cerr << "  Destination not found!!!" << endl;
                }
            }
        }
    };

    void dGraphMake(DirectedGraph<TV, TE>& tempGraph) {
        // Create Vertexes
        for (auto& element : data) {
            Distrit a;
            a.id = element["Airport ID"];
            int id_int = stoi(a.id);
            a.city = element["City"];
            a.country = element["Country"];
            a.name = element["Name"];


            tempGraph.insertVertex(id_int, a.id);
            this->distrits[id_int] = a;
        }

        // Create Edges
        for (auto& element : data) {
            string id_origen = element["Airport ID"];
            Distrit origen = this->distrits.at(stoi(id_origen));

            for (auto& [key, value] : element["destinations"].items()) {
                try {
                    Distrit destination = this->distrits.at(stoi(key));
                    string id_dest = key;
                    TE de = 0;
                    // std::cout << id_origen << " " << key << " : " << value << "\n";
                    tempGraph.createEdge(stoi(id_origen), stoi(id_dest), value);
                } catch (const out_of_range& e) {
                    cerr << "Exception at " << e.what() << endl;
                    cerr << "  Destination not found!!!" << endl;
                }
            }
        }
    };

};


class CityParser : JsonParser {
   public:
    CityParser(string jsonPath) : JsonParser(jsonPath){};
};

#endif  // PARSER_H