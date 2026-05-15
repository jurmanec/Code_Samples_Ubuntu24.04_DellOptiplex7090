#include <iostream>
#include <filesystem>
#include <cmath>
#include "MyProject/utils.hpp"
#include "if_statements.h"

using namespace std;

void getUserName(string &username) {
    cout << "Please enter your name: ";
    getline(cin, username);
}

void getSideLength(float &s) {
    cout << "Please enter a side length: ";
    cin >> s;
    numericInputHandleError();
}

/**
 * s for side length
 */
void getSideLengthLoop(float &s) {
    getSideLength(s);
    while (s <= 0) { 
        cout << "Entered length: " << s << "." << endl;
        cout << "Side length values must be non-negative." << endl;
        getSideLength(s);
    }
}

void getSidesAndComputeHypotenuse() {
    float a = 0;
    float b = 0;
    getSideLengthLoop(a);
    getSideLengthLoop(b);
    cout << "Sides: a=" << a << ", b=" << b << "." << endl;
    cout << "Hypotenuse: " << sqrt(pow(a, 2) + pow(b, 2)) << "." << endl;
}

int main() {
    cout<<"Program File: " << filesystem::path(__FILE__).filename() << "\n";
    
    // welcome
    string username;
    getUserName(username);
    if (username.size() == 0) {
        cout << "Your name cannot be blank. Please try again." << endl;
         getUserName(username);
    } 
    cout << "Welcome to Hypotenuse Calculator, "<< username <<"!" << endl;

    // main loop
    int tryAgain = 1;
    while (tryAgain == 1) {
        getSidesAndComputeHypotenuse();
        cout << "Would you like to continue (1|0)? ";
        cin >> tryAgain;
        numericInputHandleError();
    }

    // exit
    cout << "Done!!" << endl;
}

