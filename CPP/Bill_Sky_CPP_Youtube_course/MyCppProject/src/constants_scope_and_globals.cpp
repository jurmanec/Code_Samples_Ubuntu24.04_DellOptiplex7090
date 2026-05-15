#include <iostream>
#include <filesystem>
#include <climits>

using namespace std;

// note we can define functions anywhere in a file
int addTwo(int a, int b) {
    return a + b;
}

const int MY_GLOBAL_AGE = 28; // variables and constants can be defined outside of any enclosing scope.
// This makes them in the global scope
// Only useful for constants

int main() {

    // use path object to get the current file name
    cout << "File: " << filesystem::path(__FILE__).filename() << "\n";

    const int MYAGE = 44; // a const cannot be changed once they are declared.
    // MYAGE = 1; // compile error

    // constants. 
    // They are labels for a value, not variables. 
    // Thus, after MYAGE is declared, wherever else it is used, it will resolve to 44.

    // constanc from the climits header file
    cout<<"INT_MAX: " << INT_MAX << "\n";
    cout << "addTwo(2, 3): " << addTwo(2, 3) << "\n";
    cout << "MY_GLOBAL_AGE: " << MY_GLOBAL_AGE << "\n";

    return 0;
}