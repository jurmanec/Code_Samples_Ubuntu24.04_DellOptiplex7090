#include <iostream>
#include <filesystem>
#include "MyProject/utils.hpp"
#include "switch_statement.h"

using namespace std;

void menuLoop(char &userResponse) {
    cout<<endl;
    cout << "Main Menu" << endl;
    cout << "=========" << endl;
    cout << "Print <H>ello" << endl;
    cout << "Print <G>oodby" << endl;
    cout << "Input <I>nteger" << endl;
    cout << "E<x>it from the program" << endl;
    cout << "Selection: ";

    cin.get(userResponse);
    numericInputHandleError();
}

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    
    char userResponse;
    int intInput;
    
    while(true)  {
       
        menuLoop(userResponse);
        cout<<"You entered "<<userResponse<<"."<<endl;
        userResponse = toupper(userResponse);
        switch(userResponse) {
            case 'H':
                cout<<"Hello there!"<<endl;
                break;
            case 'G':
                cout<<"Goodbye all!"<<endl;
                break;
            case 'I':
                cout<<"Please enter an integer: ";
                cin>>intInput;
                numericInputHandleError();
                cout<<"You entered "<<intInput<<"."<<endl;
                break;
            case 'X':
                cout<<"You choose to exit the program"<<endl;
                break;
            default:
                cout<<"Invalid menu option";
                break;
        }
        if (userResponse == 'X') {
            break;
        }

    }

    cout << "Done!!" << endl;
}

