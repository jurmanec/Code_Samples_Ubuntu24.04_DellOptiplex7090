#include <iostream>
#include <filesystem>

using namespace std;

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    int ival = 1024;
    int &refVal = ival;
    cout << refVal << endl;
    cout << "Address of ival: " << &ival << endl;
    cout << "Address of refVal: " << &refVal << endl;
    
}