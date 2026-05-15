#include <iostream>
#include <filesystem>

using namespace std;

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    
}