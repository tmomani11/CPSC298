/// @file leibnitz_pi_converge.cpp
/// @brief Program that calculates the value of pi using Leibnitz formula for pi
/// @author momani@chapman.edu
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
int main(){

    int n;
    double piApproximation = 0.0;

    for(n=2;n<= 1048576;n *=2 ){
        for (int k = 0; k <= n; ++k) {
            piApproximation += 4 * pow(-1, k) / (2.0 * k + 1);
        }
        cout << "PI: " << setprecision(15) <<piApproximation << "; n: " << setw(7) << n << endl;
        piApproximation = 0;

    }
return 0;
}


