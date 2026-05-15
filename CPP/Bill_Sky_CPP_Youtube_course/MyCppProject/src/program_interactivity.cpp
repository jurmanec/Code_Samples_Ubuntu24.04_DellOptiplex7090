#include <iostream>
#include <filesystem>
#include <iomanip> // formatting (i/o manipulation)

using namespace std;

void numericInputHandleError() {
    // only do the following after numeric input
    cin.clear();                                         //  clear the error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the buffer
} // note that cin and cout are streams: console in and console out.

int main() {
    
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    string userName;
    int userAge;    
    float userWeightInPounds;
    char middleInitial;
    
    cout << "Welcome to my program!" << endl;
    
    // Name
    cout << "Please enter your name: ";
    // cin >> userName; // cin will get words, not lines
    getline(cin, userName); // from file cin to variable userName (from input stream to buffer that stores string)
    cout << "Hi, "<<userName<<"."<<endl;

    // Get a single character
    cout << "Please enter your middle inital: ";
    cin.get(middleInitial);
    cout << "Your middle initial is " << middleInitial << "." << endl;

    // Age
    cout << "Please enter your age in years: ";
    cin >> userAge;
    cout << "You have been alive for " << userAge * 12 << " months!" << endl;
    numericInputHandleError();

    // Weight
    cout << "Please enter your weight in pounds: ";
    cin >> userWeightInPounds;
    //cout << "Your weight: "<< userWeightInPounds <<"."<< endl;
    cout << "Your weight: " << fixed << setprecision(4) << userWeightInPounds <<"."<< endl; // fix precision of weight
    numericInputHandleError();

    cout << "Program ending, have a nice day!" << endl;

}