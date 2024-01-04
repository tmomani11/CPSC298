
#include <iostream>
#include <cmath>

    int main() {
        // Constants
        double f_R = 16.35;  // Reference frequency in Hz
        double dTwelfthRootOfTwo = 1.059463094359;  // Twelfth root of 2
        double speedOfSound = 34500;

        // Display reference frequency
        std::cout << "Reference frequency: " << f_R << " Hz\n";
        std::cout << "Speed of sound " << 345 << " m/s \n";

        // Note C0
        int nu = 0, k = 0;
        double frequency = f_R * std::pow(2, nu) * std::pow(dTwelfthRootOfTwo, k);
        double wavelength = speedOfSound / frequency ;
        std::cout << "Note:  C0;"  << " nu: " << nu << "; k: " << k << "  ;Frequency: " <<
        frequency  << "Hz; " << "Wavelength: " << wavelength << "cm " << std::endl;

        // Note C#0
        int nu1 = 0, k1 = 1;
        double frequency1 = f_R * std::pow(2, nu1) * std::pow(dTwelfthRootOfTwo, k1);
        double wavelength1 = speedOfSound / frequency1 ;
        std::cout << "Note: C#0;"  << " nu: " << nu1 << "; k: " << k1 << "  ;Frequency: " <<
        frequency1  << "Hz; " << "Wavelength: " << wavelength1 << "cm " << std::endl;

        // Note D0
        int nu2 = 0, k2 = 2;
        double frequency2 = f_R * std::pow(2, nu2) * std::pow(dTwelfthRootOfTwo, k2);
        double wavelength2 = speedOfSound / frequency2 ;
        std::cout << "Note:  D0;"  << " nu: " << nu2 << "; k: " << k2 << "  ;Frequency: " <<
        frequency2  << "Hz; " << "Wavelength: " << wavelength2 << "cm " << std::endl;

        // Note C4
        int nu4 = 4, k4 = 0;
        double frequency4 = f_R * std::pow(2, nu4) * std::pow(dTwelfthRootOfTwo, k4);
        double wavelength4 = speedOfSound / frequency4 ;
        std::cout << "Note:  C4;"  << " nu: " << nu4 << "; k: " << k4 << "  ;Frequency: " <<
        frequency4  << "Hz; " << "Wavelength: " << wavelength4 << "cm " << std::endl;

        // Note D#7
        int nu5 = 7, k5 = 3;
        double frequency5 = f_R * std::pow(2, nu5) * std::pow(dTwelfthRootOfTwo, k5);
        double wavelength5 = speedOfSound / frequency5 ;
        std::cout << "Note: D#7;"  << " nu: " << nu5 << "; k: " << k5 << "  ;Frequency: " <<
        frequency5  << "Hz; " << "Wavelength: " << wavelength5 << "cm " << std::endl;

        // Note C8
        int nu6 = 8, k6 = 0;
        double frequency6 = f_R * std::pow(2, nu6) * std::pow(dTwelfthRootOfTwo, k6);
        double wavelength6 = speedOfSound / frequency6 ;
        std::cout << "Note:  C8;"  << " nu: " << nu6 << "; k: " << k6 << "  ;Frequency: " <<
        frequency6  << "Hz; " << "Wavelength: " << wavelength6 << "cm " << std::endl;

        return 0;
    }


