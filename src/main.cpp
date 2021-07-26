#include <iostream>

#include "Tester/tester.h"

using namespace std;

int main(int argc, char* argv[]) {
    cout << "================================================" << endl;
    cout << "MENU TSP TESTER" << endl;
    cout << "================================================" << endl;

    Tester::testTSP();
    Tester::testTSP_Parser1();
    Tester::testTSP_Parser2();

    return EXIT_SUCCESS;
}
