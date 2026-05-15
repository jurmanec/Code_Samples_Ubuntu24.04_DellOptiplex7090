#include <iostream>
#include <filesystem>

using namespace std;

class Vector {

public:
    Vector(int s): elem{new double[s]}, sz{s} { // initialization before constructor body

    }
    double& operator[](int i){ // overload the subscript `[]` operator
        return elem[i];
    }
private:
    double* elem;
    int sz;
};

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    
}