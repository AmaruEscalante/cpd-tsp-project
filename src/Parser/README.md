## JSON file parser

- Se construye un grafo a partir de una archivo JSON.
- Se utilizó una libreria de internet la cual puede ser consultada en: https://github.com/nlohmann/json

## parser.h 

- Este archivo define la estructura de datos que se genera a partir del archivo JSON.
- Se implemento dos estructuras de datos las cuales son District y Airports.

1. Estructura District: contiene los siguientes elementos

```
struct Distrit {
    string id;
    string name;
    string city;
    string country;
};
```

Para el caso que se desee crear este estrucutra es necesario que el JSON posee una llave del siguiente tipo:

```
{
    "City": "Juliaca",
    "Name": "Juliaca",
    "Country": "Peru",
    "Airport ID": "1",
    "destinations": {
        "2": 20,
        "3": 30,
        "4": 10,
        "5": 11
    }
},
```

Los costos son definidos en la llave "destinations" donde se colocar el ID de otro District y su respectivo peso. Revisar los archivos ejemplo1.json y ejemplo2.json para ver el formato de este JSON.

2. Estructura Airport: contiene los siguientes elementos

```
struct Airport {
    string id;
    string name;
    string city;
    string country;
    double latitude;
    double longitude;
};
```

Para el caso que se desee crear este estrucutra es necesario que el JSON posee una llave del siguiente tipo:

```
{
    "City": "Ayacucho",
    "Name": "Coronel Fap Alfredo Mendivil Duarte",
    "Country": "Peru",
    "Longitude": "-74.204417",
    "Airport ID": "2786",
    "Latitude": "-13.154819",
    "destinations": [
        "2789"
    ]
},
```

Para definir los costos de cada camino se utilizan las llaves "Longitude" y "Latitude" para calcular la distancia euclidiana entre estes dos puntos. Revisar los archivos airports.json y pe.json para ver el formato de este JSON.
