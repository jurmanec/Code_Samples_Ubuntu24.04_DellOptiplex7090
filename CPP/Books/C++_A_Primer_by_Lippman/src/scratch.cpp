#include <iostream>
#include <filesystem>

using namespace std;

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    
    int i = 42;
    int *p;
    int *&r = p; // syntax for reference to a pointer

}