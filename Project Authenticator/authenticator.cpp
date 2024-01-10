/// @file authenticator.cpp
/// @brief Program that calculates the value of pi using Leibnitz formula for pi
/// @author momani@chapman.edu
#include <iostream>
#include <string>

using namespace std;

const char k_cAuthenticatorCodeCharacter1 = 'E';
const char k_cAuthenticatorCodeCharacter2 = 'C';
const char k_cAuthenticatorCodeCharacter3 = 'A';
const int k_iValidCodeChecksum = 5;

int main() {
    char char1Input, char2Input, char3Input;
    string codeInput, codeAuthenticator;

    cout << "Enter the first character of the message code: " << endl;
    cin >> char1Input;
    codeInput += char1Input;

    cout << "Enter the second character of the message code: " << endl;
    cin >> char2Input;
    codeInput += char2Input;

    cout << "Enter the third character of the message code: " << endl;
    cin >> char3Input;
    codeInput += char3Input;
    cout << endl;
    int checksum = (int(char1Input) + int(char2Input) + int(char3Input)) % 7;
    codeAuthenticator += k_cAuthenticatorCodeCharacter1;
    codeAuthenticator += k_cAuthenticatorCodeCharacter2;
    codeAuthenticator += k_cAuthenticatorCodeCharacter3;
    int sum = char1Input + char2Input + char3Input;

    cout << "Authenticator Code: " << codeAuthenticator << endl;
    cout << "Message code: " << codeInput << endl << endl;

    if (checksum == k_iValidCodeChecksum) {
        if (codeInput == codeAuthenticator) {
            cout << "Message is authentic" << endl;
            cout << "Concurrence: Message is authentic \n\n";
            cout << "Characterization of message code\n";
            cout << "--------------------------------\n";
            cout << "ASCII values of message code characters: " << int(char1Input) << ", " << int(char2Input) << ", "
                 << int(char3Input) << endl;
            cout << "Sum of ASCII values for message code characters: " << sum << endl;
            cout << "Message code checksum is valid: " << checksum << endl;
        } else {
            cout << "\nMessage is invalid" << endl;
            cout << "concurrence :message is invalid\n\n";

            cout << "Characterization of message code\n";
            cout << "--------------------------------\n";
            cout << "ASCII values of message code characters: " << int(char1Input) << ", " << int(char2Input) << ", "
                 << int(char3Input) << endl;
            cout << "Sum of ASCII values for message code characters: " << sum << endl;
            cout << "Message code checksum is valid: " << checksum << endl;

            if (char1Input != k_cAuthenticatorCodeCharacter1) {
                cout << "First characters do not match: Message  " << char1Input << "; Authenticator: "
                     << k_cAuthenticatorCodeCharacter1 << endl;
            }
            if (char2Input != k_cAuthenticatorCodeCharacter2) {
                cout << "Second characters do not match: Message " << char2Input << "; Authenticator: "
                     << k_cAuthenticatorCodeCharacter2 << endl;
            }
            if (char3Input != k_cAuthenticatorCodeCharacter3) {
                cout << "Third characters do not match: Message  " << char3Input << "; Authenticator: "
                     << k_cAuthenticatorCodeCharacter3 << endl;
            }
            if (codeInput < codeAuthenticator) {
                cout << "Message code is (" << codeInput << ") lexicographically less than Authenticator code("
                     << codeAuthenticator << ")" << endl;
            } else if (codeInput > codeAuthenticator) {
                cout << "Message code is(" << codeInput << ") lexicographically greater than Authenticator code("
                     << codeAuthenticator << ")" << endl;
            }
        }
    } else {
        cout << "\nMessage is invalid" << endl;
        cout << "concurrence: message is invalid\n\n";

        cout << "Characterization of message code\n";
        cout << "--------------------------------\n";
        cout << "ASCII values of message code characters: " << int(char1Input) << ", " << int(char2Input) << ", "
             << int(char3Input) << endl;
        cout << "Sum of ASCII values for message code characters: " << sum << endl;
        cout << "Message code checksum is invalid: " << checksum <<"; expected: " <<k_iValidCodeChecksum <<endl;

        if (char1Input != k_cAuthenticatorCodeCharacter1) {
            cout << "First characters do not match: Message  " << char1Input << "; Authenticator: " << k_cAuthenticatorCodeCharacter1 << endl;
        }
        if (char2Input != k_cAuthenticatorCodeCharacter2) {
            cout << "Second characters do not match: Message " << char2Input << "; Authenticator: " << k_cAuthenticatorCodeCharacter2 << endl;
        }
        if (char3Input != k_cAuthenticatorCodeCharacter3) {
            cout << "Third characters do not match: Message  " << char3Input << "; Authenticator: " << k_cAuthenticatorCodeCharacter3 << endl;
        }
    }

    return 0;
}

