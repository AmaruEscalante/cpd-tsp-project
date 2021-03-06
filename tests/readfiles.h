#ifndef READFILES_H
#define READFILES_H

/*
 *   Este archivo contiene funciones utilitarias para 
 *   realizar los tests de algoritmo TSP Branch and Bound.
*/

#include <iostream>
#include <cmath>
#include <chrono>
#include <iomanip>

/* Definición del tamaño de la matriz */
#ifdef SIZE
#undef N
    #define N SIZE
#else
    #define N 10
#endif

using namespace std;

/* 
 * Función para leer un archivo de texto, y setear las matrices corresponientes.
 * @param filename: nombre del archivo a leer.
 * @param n: tamaño de la matriz.
 * @param cost: costo final del mejor camino.
 * @param costM[][N]: matriz de costos.
 * @param result[N-1]: vector para almacenar el mejor resultado.
 */
void read_matrix_and_result_from_file(const char *filename, int *n, int *cost, int costM[][N], int result[N-1]){
    cout << "Reading file: " << filename << endl;
    freopen(filename, "r", stdin);

    // Input adjacency matrix
    std::cin >> *n;                 // Receive number of cities
    for (size_t i = 0; i < *n; i++) // Initialize adjacency matrix
        for (size_t j = 0; j < *n; j++)
            std::cin >> costM[i][j];
    
    cout << "Number of elements in matrix is: " << *n << endl;

    cout << "Result to compare is: " << endl;
    for (int i = 0; i < *n + 1; i++)
    {
        std::cin >> result[i];
        cout << result[i] << " ";
    }
    cout << endl;

    std::cin >> *cost;
    cout << "Cost to compare is: " << *cost << endl;
    cout << "----------------------------------------- " << endl;
}

/* 
 * Función para monstrar el tiempo de ejecución en segundos y nanosegundos.
 * @param time: tiempo total.
 * @param par: deferenciar en caso sea un tiempo paralelo.
 */
void print_time(double time, bool par = false){
    cout << "----------------------------------------- " << endl;
    if (par) {
        std::cout << std::fixed << std::setprecision(0);
        cout << "Time taken is: " << time * pow(10, 9) << " nano seconds" << endl;
        std::cout << std::fixed << std::setprecision(9);
        cout << "Time taken is: " << time << " seconds" << endl;
    } else {
        std::cout << std::fixed << std::setprecision(0);
        cout << "Time taken is: " << time << " nano seconds" << endl;
        std::cout << std::fixed << std::setprecision(9);
        cout << "Time taken is: " << time * pow(10, -9) << " seconds" << endl;
    }
    
    cout << "----------------------------------------- " << endl;
}

/*
 * Funcion que verifica si el mejor camino encontrado y el costo final es igual al esperado.
 */
void test(int result[], int result_to_compare[], int cost, int cost_to_compare){
    cout << "Result of tests are: " << endl;

    bool success = false;
    for (int i = 0; i < N + 1; i++)
    {
        if (result[i] == result_to_compare[i])
        {
            success = true;
        }
        else
        {
            success = false;
            break;
        }
    }
    std::cout << "1. Test Path: " << std::boolalpha << success << std::endl;

    success = false;
    if (cost == cost_to_compare)
    {
        success = true;
    }
    std::cout << "2. Test Cost: " << std::boolalpha << success << std::endl;
}

#endif