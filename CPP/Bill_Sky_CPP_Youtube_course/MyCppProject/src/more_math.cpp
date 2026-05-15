#include <iostream>
#include <filesystem>
#include <cmath>

using namespace std;

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";

    cout << "pow(2, 2): " << pow(2, 2) << endl;
    cout << "sqrt(25): " << sqrt(25) << endl;
}