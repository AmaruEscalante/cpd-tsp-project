
#include <iostream>
#include "utils.h"

using namespace std;

void print_time(double time, bool par){
    cout << "----------------------------------------- " << endl;
    if (par) {
        std::cout << std::fixed << std::setprecision(9);
        cout << "Time taken is: " << time * pow(10, -9) << " nano seconds" << endl;
        cout << "Time taken is: " << time << " seconds" << endl;
    } else {
        cout << "Time taken is: " << time << " nano seconds" << endl;
        std::cout << std::fixed << std::setprecision(9);
        cout << "Time taken is: " << time * pow(10, -9) << " seconds" << endl;
    }
    
    cout << "----------------------------------------- " << endl;
}
