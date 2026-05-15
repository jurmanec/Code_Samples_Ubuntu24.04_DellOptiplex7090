#include <iostream>

int main() {
    /*
        sizeof returns the size in bytes (8 bit chunks) 
    */ 
    std::cout << "char size is: " << sizeof(char) << "\n";
    std::cout << "bool size is: " << sizeof(bool) << "\n";
    std::cout << "int size is: " << sizeof(int) << "\n";
    std::cout << "double size is: " << sizeof(double) << "\n";
    std::cout << "unsigned size is: " << sizeof(unsigned) << "\n";
}