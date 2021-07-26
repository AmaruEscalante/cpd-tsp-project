# Grafos para realizar testes del TSP

Esta carpeta de test es para probar el algoritmo de TSP con la estrucutra de datos desarrollada y para probar el JSON parser implementado.

# Archivo tester.cpp

Contiene las siguientes funciones para realizar distintos tests:

## Test de un grafo no dirigido conexo mediante la creación del grafo manualmente.

Para estos casos se utilizó el grafo de la siguiente página: https://www.geeksforgeeks.org/traveling-salesman-problem-using-branch-and-bound-2/

1. testTSP(): contruye el grafo de forma hardcodeada. 

- El resultado esperado es:

```
 ------- Test Travel Salesman Problem unDirected ------- 
3: 0(20), 1(25), 2(30), 
2: 0(15), 3(30), 1(35), 
1: 0(10), 3(25), 2(35), 
0: 1(10), 3(20), 2(15), 

Travel()
80
0 1 3 2 0
```

2. testTSP_Parser1(): contruye el grafo a partir del archivo ejemplo1.json. El resultado esperado es:

```
 ------- Test Travel Salesman Problem with Parser unDirected Graph ------- 
Reading ejemplo1.json

Display unDirected Graph
3: 0(20), 1(25), 2(30), 
2: 0(15), 1(35), 3(30), 
1: 0(10), 2(35), 3(25), 
0: 1(10), 2(15), 3(20), 

Travel()
80
0 1 3 2 0
```

## Test de un grafo dirigido conexo mediante la lectura de un archivo json

Para estes casos se utilizó el grafo del siguiente video: https://www.youtube.com/watch?v=1FEP_sNb62k

1. testTSP_Parser2(): contruye el grafo a partir del archivo ejemplo2.json. El resultado esperado es:

```
 ------- Test Travel Salesman Problem with Parser Directed Graph ------- 
Reading ejemplo2.json

Display unDirected Graph
5: 1(16), 2(4), 3(7), 4(16), 
4: 1(19), 2(6), 3(18), 5(3), 
3: 1(3), 2(5), 4(2), 5(4), 
2: 1(15), 3(16), 4(4), 5(2), 
1: 2(20), 3(30), 4(10), 5(11), 

Travel()
28
1 4 2 5 3 1
```

Todos los archivos JSON pueden ser encontrados en la carpeta Parser/Data.