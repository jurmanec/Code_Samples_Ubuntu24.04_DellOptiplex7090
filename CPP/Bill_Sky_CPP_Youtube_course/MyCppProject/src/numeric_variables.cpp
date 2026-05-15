#include <iostream>

using namespace std;

int main(int, char**){
    
    
    cout << "Hello, numeric_varialbes!\n";

    // data definitions here are the same as they would be in C.

    // Integer types 2, 4, and 8 bytes
    
    // 16 bits (2 bytes)
    short int var1 = 0; // short int from -32768 to 32767 (-2^15 to 2^15-1)
    unsigned short int var2 = 0; // 0 to 65535 (0 to 2^16)
    
    // 32 bits (4 bytes)
    int var3 = 0; // -2^31 to 2^31-1
    unsigned int var4 = 0; // 0 to 2^32

    // 64 bits (8 bytes)
    long int var5 = 0; // -2^63 to 2^63-1
    unsigned long int var6 = 0; // 0 to 2^ 64

    var1 = -100;
    var2 = 200;

    // floating point
    float singlePrecisionFloat = 0;
    double doublePrecitionFloat = 0;

    // values
    cout << "\n";
    cout << "Values:\n";
    cout << "var1: " << var1 << "\n";
    cout << "var2: " << var2 << "\n";
    cout << "var3: " << var3 << "\n";
    cout << "var4: " << var4 << "\n";
    cout << "var5: " << var3 << "\n";
    cout << "var6: " << var4 << "\n";
    // size
    cout << "\n";
    cout << "Byte sizes:\n";
    cout << "sizeof(var1): " << sizeof(var1) << ", sizeof(short int): " << sizeof(short int) << "\n";
    cout << "sizeof(var2): " << sizeof(var2) << ", sizeof(unsigned short int): " << sizeof(unsigned short int) << "\n";
    cout << "sizeof(var3): " << sizeof(var3) << ", sizeof(int): " << sizeof(int) << "\n";
    cout << "sizeof(var4): " << sizeof(var4) << ", sizeof(unsigned int): " << sizeof(unsigned int) << "\n";
    cout << "sizeof(var5): " << sizeof(var5) << ", sizeof(long int): " << sizeof(long int) << "\n";
    cout << "sizeof(var6): " << sizeof(var6) << ", sizeof(unsigned long int): " << sizeof(unsigned long int) << "\n";
    cout << "sizeof(float): " << sizeof(float) << "\n";
    cout << "sizeof(double): " << sizeof(double) << "\n";
    cout << "sizeof(long double): " << sizeof(long double) << "\n"; // 128 bits

    return 0;
}
