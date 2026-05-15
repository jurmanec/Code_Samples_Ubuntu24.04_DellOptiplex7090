#include <iostream>

using namespace std;

int main() {
    cout << "Test" << "\n";

    int var1 = 100;
    int var2 = 200;
    string str1 = "Hi";

    cout << var1 << "\n";
    var1 = var2; // reassing var1 to point at the data held by var2
    cout << var1 << "\n";
    var1 = 900;
    cout << var1 << "\n";
    // from variable name, get the memory address of the data it points to
    cout << "var1 address: " << &var1 << "\n";
    cout << "var1 value: " << var1 << "\n";
}