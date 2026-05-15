#include <iostream>
#include <filesystem>

using namespace std;

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";

    int sum =  0;
    
    sum = 1 + 2;
    cout << sum << "\n";

    // use floats if we want to have a decimal result of division

    
}