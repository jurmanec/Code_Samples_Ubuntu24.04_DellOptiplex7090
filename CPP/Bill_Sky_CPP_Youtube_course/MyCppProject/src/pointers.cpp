#include <iostream>
#include <filesystem>

using namespace std;

void nullCheckOnInt(string varName, int* var) {
    cout << varName;
    if (var == nullptr) {
        cout << " is null";
    } else {
        cout << " is not null. Its value is "<< *var;
    }
    cout << endl;
}

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";

    int var1 = 44;
    cout << "var1 value: " << var1 << "\n";
    cout << "var1 address: " << &var1 << "\n"; // get memory address of the var1

    int * ptr1 = &var1;
    cout << "ptr1 value" << ptr1 << "\n";
    cout << "ptr1 value at memory address: " << *ptr1 << "\n"; // dereference the pointer

    cout << "var1 value: " << *&var1 << "\n"; // get the address then dereference to get the value

    // so a variable has these things
    // - address
    // - data
    // we can get either on of these (prefix with & for the address)

    // a pointer has these things
    // - address

    int * var2 = nullptr; // nullptr is a language built-in keyword. 
    // This must be the equivalent of Java null. 
    cout << "var2 " << var2 << endl; // note that this is a pointer.
    // 0 is the null memory address.
    nullCheckOnInt("var2", var2);
    nullCheckOnInt("var1", &var1);

    // why use pointers?
    // they are small
    // they are fast.
    // sometimes they are just better.
    
}