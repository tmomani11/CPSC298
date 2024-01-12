/// @file main.cpp
/// @brief Program that C++ class that simulates the Ultimate Machine
/// @author momani@chapman.edu
#include <iostream>

class CUltimateMachine {
private:
    bool m_bState; // true for On, false for Off

public:
    CUltimateMachine() : m_bState(false) {
        std::cout << "CUltimateMachine constructor (ctor) called" << std::endl;
    }

    ~CUltimateMachine() {
        std::cout << "CUltimateMachine destructor (dtor) called" << std::endl;
    }

    void displayState() {
        if (m_bState)
            std::cout << "Ultimate Machine is ON" << std::endl;
        else
            std::cout << "Ultimate Machine is OFF" << std::endl;
    }

    void turnOn() {
        m_bState = true;
        displayState();
        m_bState = false;
    }
};

int main() {
    std::cout << "The Ultimate Machine Simulation" << std::endl;

    CUltimateMachine ultimate;
    ultimate.displayState();
    ultimate.turnOn();

    return 0;
}