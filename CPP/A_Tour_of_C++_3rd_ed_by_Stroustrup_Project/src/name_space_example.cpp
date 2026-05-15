#include <iostream>
#include <filesystem>

using namespace std;

namespace MyNamespace {
    int value = 42;
}

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    
    // std::cout << MyNamespace::value << endl;

    // bring a value from another namespace into this scope
    using MyNamespace::value;
    std::cout << value << endl;
}