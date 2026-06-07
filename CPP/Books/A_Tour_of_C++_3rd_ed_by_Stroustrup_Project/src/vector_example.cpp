#include <iostream>
#include <filesystem>

using namespace std;

class Vector {

    public:
    Vector(int s): elem{new double[s]}, sz{s} {}

    double& operator[](int i) {
        return elem[i];
    }

    int size() {
        return sz;
    }

    private:
    double* elem;
    int sz;
};

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";

    Vector v(5);

    cout << "v has size: " <<v.size() << endl;
    cout << "v is an object at: "<<endl;
    
}