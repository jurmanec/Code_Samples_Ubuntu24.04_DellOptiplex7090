#include <iostream>
#include <filesystem>

using namespace std;

struct Zombie {
    int daysDead;
    string name;
};

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    
    // the types of pointers matter. 
    Zombie z; // declare variable of type Zombie struct
    z.name = "Scarry Zombie";
    z.daysDead = 3;
    Zombie* z_ptr = &z; // get pointer to z
    z_ptr->daysDead = 92;
    (*z_ptr).daysDead = 91;
    cout << "zombie z name: " << z.name << endl;
    cout << "zombie z days dead: " << z.daysDead << endl;

    // arrays
    int myarr[5] = {0,2,4,6,8};
    cout << "myarr: " <<myarr << endl; // pointer to the start of my array
    cout << "myarr: " << *myarr << endl; // first element
    int* myarr_ptr = myarr; // pointer for iteration variable
    for (int i = 0; i < 5; i++) {
        cout << "myarr element at " << i << ": "<< *(myarr_ptr++) << endl; 
    }

    // offset from the myaar pointer
    cout << "Only one pointer." << endl;
    for (int i = 0; i < 5; i++) {
        // use pointer arithmetic to advance. Each increment is by the size of one element in the array.
        cout << "myarr element at " << i << ": "<< *(myarr + i) << endl; 
    }
    
    // whenever we create an array, we're actually creating a pointer. 

    // range based for loop
    cout << "range based for loop" << endl;
    for (int x: myarr) {
        cout << x << " ";
    }
    cout << endl;

}