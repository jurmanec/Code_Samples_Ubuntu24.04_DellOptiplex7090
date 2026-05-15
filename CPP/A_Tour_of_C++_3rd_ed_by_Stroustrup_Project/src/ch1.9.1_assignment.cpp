#include <iostream>
#include <filesystem>

using namespace std;

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    /**
     * assignment copies, it does not create a reference. 
     */
    int x = 2;
    int y = 3;
    x = y;
    cout<<"without poitners.."<<endl;
    cout << "x: "<<x<<", y: "<<y<< endl;
    y = 1;
    cout << "x: "<<x<<", y: "<<y<< endl; // x remains 3 when we change y.
    /**
     * Pointers
     */
    x = 2;
    y = 3;
    int* p = &x;
    int* q = &y;
    p = q;
    cout<<"with poitners.."<<endl;
    cout << "*p: "<<*p<<", *q: "<<*q<< endl;
    y = 1;
    cout << "*p: "<<*p<<", *q: "<<*q<< endl; 
    /**
     * Assignment with references, in effect, copies.
     * Note we dont have to dereference with references when accessing the value. 
     * This occurs implicitly.
     */
    x = 2;
    y = 3;
    int& r = x;
    int& r2 = y;
    r = r2;
    cout<<"with references.."<<endl;
    cout << "r: "<<r<<", r2: "<<r2<< endl;
    y = 1;
    cout << "r: "<<r<<", r2: "<<r2<< endl; 

}