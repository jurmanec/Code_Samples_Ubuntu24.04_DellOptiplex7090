#include <iostream>
#include <filesystem>

using namespace std;

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
 
    double price  = 109.99, discount = price * 0.16;
    // price initializes first, then discount.
    
}