/// @file main.cpp
/// @brief Program that C++ class that simulates the Ultimate Machine
/// @author momani@chapman.edu
#include <iostream>

class CUltimateMachine {

public:
    CUltimateMachine() : m_bState(false) {
        std::cout << "CUltimateMachine constructor (ctor) called" << std::endl;
    }

    ~CUltimateMachine() {
        std::cout << "CUltimateMachine destructor (dtor) called" << std::endl;
    }

    void displayState() {
       switch(m_bState){
           case true:
               std::cout << "Ultimate Machine is ON" << std::endl;
               break;
            case false:
               std::cout << "Ultimate Machine is OFF" << std::endl;
               break;
       }
    }

    void turnOn() {
        m_bState = true;
        displayState();
        m_bState = false;
    }
private:
    bool m_bState; // true for On, false for Off

};

int main() {
    std::cout << "The Ultimate Machine Simulation" << std::endl;

    CUltimateMachine ultimate;  //declare an instance of the class
    ultimate.displayState();   //display its state
    ultimate.turnOn();         // Turn on the Ultimate machine

    return 0;
}
