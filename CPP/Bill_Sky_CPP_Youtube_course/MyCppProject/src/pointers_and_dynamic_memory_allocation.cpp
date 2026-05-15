#include <iostream>
#include <filesystem>

using namespace std;

struct Donut {
    int calories;
    float cost;
    float price;
};

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";

    // Declaration 
    int *int_ptr = nullptr;
    int int_var = 100;

    Donut* donut_ptr = nullptr;
    
    
    
    // Creation 
    // dynamically allocated memory. 
    // allocated it at runtime rather than at compile time.
    // `new` keyword to dynamically allocate memory in a C++ program. 
    // C uses malloc. `new` does the same in C++ 
    int_ptr = new int(100); // if recollection is correct. C required a size for malloc. Here we just use `new` and `int`. The size must be inferred from the type.
    // in modern C++ (C++11 and later), smart pointers are recommended instead of new. 
    // e.g., make_unique, make_shared.
    // 
    cout << *int_ptr << endl; // 100
    *int_ptr = 200;
    cout << *int_ptr << endl; // 200

    donut_ptr = new Donut;
    donut_ptr->calories = 100;
    donut_ptr->cost = 1.0;
    donut_ptr->price = 1.0;
    cout << "donut calories: "<< donut_ptr->calories << endl;

    // cleanup
    delete int_ptr; // free memory allocation that the pointer refers to.
    int_ptr = nullptr;
    delete donut_ptr;
    donut_ptr = nullptr;
}