#include <iostream>
#include <filesystem>
#include <complex>

using namespace std;

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    
    double d1 = 2.3;
    double d2 {2.3};
    double d3 = {2.3};
    complex<double> z = 1;
    complex<double> z2 {d1, d2};
    complex<double> z3 = {d1, d2};

    cout <<"d1: "<<d1<<endl;
    cout <<"d2: "<<d2<<endl;
    cout <<"d3: "<<d3<<endl;
    cout <<"z: "<<z<<endl;
    cout <<"z2: "<<z2<<endl;
    cout <<"z3: "<<z3<<endl;
    cout <<"z3.real(): "<<z3.real()<<", z3.imag(): "<<z3.imag()<<endl;

    int i1 = 7.8;
    // int i2 {7.8}; // compile error for list form if data does not match the type
    // cout << "i2: "<<i2<<endl;
    

}