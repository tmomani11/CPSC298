/// @file hello_cin.cpp
/// @brief program that outputs what the user enters
/// @author momani@chapman.edu
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string strMessage;
    cout << "Please type a single word message" << endl;
    cin >> strMessage;
    cout << "Message: " << strMessage << endl;
    return 0;
}
