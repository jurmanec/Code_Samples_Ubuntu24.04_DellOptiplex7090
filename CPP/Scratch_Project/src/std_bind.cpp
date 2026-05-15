#include <iostream>
#include <filesystem>
#include <functional>

// using namespace std::placeholders;

/**
 * std::bind
 * Allows us to take an existing function and 'bind' sepcific values to its arguments, 
 * creating a callable object with a simpler or modified interface.
 */
int multiply(int a , int b) {
    return a * b;
}

int main() {
    std::cout<<"File: " << std::filesystem::path(__FILE__).filename() << "\n";

    auto multiplyBy10 = std::bind(multiply, 10, std::placeholders::_1);
    std::cout << "multiplyBy10(5): " << multiplyBy10(5) << std::endl;
    
}