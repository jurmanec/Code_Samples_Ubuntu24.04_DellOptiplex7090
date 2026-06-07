#include <iostream>
#include <filesystem>

using namespace std;

class Vector {

    public:
    Vector(int s) {
        if (s < 0) {
            throw length_error{"Vector constructor: negative size"};
            elem =  new double[2];
            sz = s;
        }
    }

    double& operator[](int i) {
        // validate (pre-condition invariant)
        if (!(i >= 0 && i < size()))
            throw out_of_range{"Vector::operator[]"};
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
    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    v[3] = 3;
    v[4] = 3;

    cout << "v has size: " <<v.size() << endl;
    cout << "v is an object at: " << &v <<endl;

    /* test error handling*/
    cout << "v[4]: " <<v[4]<<endl; // no error
    try {
        cout << "v[5]: " <<v[5]<<endl; // no error
    } catch (const out_of_range& err) {
        cerr << err.what() << endl;
    }

    try {
        Vector v2(-27);
    } catch (const length_error& err) {
        cerr << err.what() << endl;
    }
}