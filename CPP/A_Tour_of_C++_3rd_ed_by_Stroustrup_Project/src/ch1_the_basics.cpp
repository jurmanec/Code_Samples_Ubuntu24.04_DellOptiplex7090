#include <iostream>
#include <filesystem>
#include <string>
#include <iomanip>
#include <typeinfo>

using namespace std;


void print(int i) {
    cout <<"Pinting int: "<<i<<endl;
};

void print(double d) {
    cout <<"Printing double: " << fixed << setprecision(2) <<d<< endl;
};

void print(string s) {
    cout << "Printing string: "<<s<<endl;
};

/**
 */
int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";

    cout << "print(1): ";
    print(1);

    cout << "print(1.0): ";
    print(1.0);
    
    cout << "print (one): ";
    print("one");

    // types that are not machine dependent.
    // example.
    int32_t intVar = 1;
    cout <<"int32_t intVar: "<<intVar<<endl;
    cout<<"typeid(intVar).name(): "<<typeid(intVar).name()<<endl;
    double doubleVar = 1.0;
    cout<<"typeid(doubleVar).name(): "<<typeid(doubleVar).name()<<endl;


}