#ifndef TESTER_H
#define TESTER_H

#include <assert.h>

#include <iostream>
#include <stdexcept>
#include <vector>

#include "../Graph/directedGraph.h"
#include "../Graph/undirectedGraph.h"
#include "../Parser/parser.h"
#include "../Graph/Algoritmos/travel.h"

using namespace std;

#define ASSERT(condition, message)                                                       \
    do {                                                                                 \
        if (!(condition)) {                                                              \
            std::cerr << "Assertion `" #condition "` failed in " << __FILE__ << " line " \
                      << __LINE__ << ": " << message << std::endl;                       \
            std::terminate();                                                            \
        }                                                                                \
    } while (false)

class Tester {
   public:
    static void testTSP();
    static void testTSP_Parser1();
    static void testTSP_Parser2();
};

#endif