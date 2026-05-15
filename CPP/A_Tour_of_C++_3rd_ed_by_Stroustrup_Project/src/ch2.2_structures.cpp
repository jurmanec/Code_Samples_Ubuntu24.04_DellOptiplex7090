#include <iostream>
#include <filesystem>

using namespace std;

struct Vector {
    double* elem;
    int sz;
};

/**
 * new keyword. 
 * Make the allocation independent of scope. 
 * Must be freed using delete. 
 */
void vector_init(Vector& v, int s) { // Vector& means we're passing v by non-const reference
    v.elem = new double[s]; // new means heap memory (aka free store | dynamic memory) allocated
    v.sz = s;
}

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";


    
}