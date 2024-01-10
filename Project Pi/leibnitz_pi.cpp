/// @file leibnitz_pi.cpp
/// @brief Program that calculates the value of pi using Leibnitz formula for pi
/// @author momani@chapman.edu
#include <iostream>
#include <iomanip>
#include <cfloat>
#include <ctgmath>

using namespace std;
int main() {
    int n;
    double piApproximation = 0.0;

    std::cout << "Enter the upper bound (n) for the Leibniz formula: ";
    std::cin >> n;

    for (int k = 0; k <= n; ++k) {
        piApproximation += 4 * pow(-1, k) / (2.0 * k + 1);
    }


    std::cout << "PI (approx): " << std::setprecision(15) <<piApproximation << "; n: " << std::setw(7) << n << std::endl;
  std::cout << "PI (actual): " << "3.141592653589793" << std::endl;


  std::cout << "Decimal digits of precision: " << DBL_DIG << std::endl;
  std::cout << "Number of base 2 mantissa digits of double precision floating point value: "
  << DBL_MANT_DIG << std::endl;
  std::cout << "Next representable number from 3.141592653589793: "
  << std::nextafter(3.141592653589793, 3.14) << std::endl;


    return 0;
}
