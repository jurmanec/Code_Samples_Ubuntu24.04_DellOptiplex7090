#include <iostream>
#include <filesystem>
#include "Puppy.h"
#include <cstring>

using namespace std;

struct PuppyStruct {
    char name[32];
    char breed[24];
    int ageInYears;
    float weightInPounds;
};


/**
 * Note:
 * The general rule is to always use objects or object references (not object pointers.).
 */
int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    
    Puppy *p1; // the declaration executes the constructor.
    Puppy *p2;

    cout << "p1 adddress: " <<p1 <<endl;
    // new keyword in k++ is used for dynamic memory allocation on the heap
    // we use new for these things.
    // - memory allocation 
    // - call constructor to setup the object
    // - linking (get memory address of object)
    p1 = new Puppy();
    p2 = new Puppy();

    cout << "p1 adddress: " <<p1 <<endl;
    Puppy *p3 = new Puppy();
    strcpy(p3->name, "Doggy");

    strcpy(p1->name, "Snoopy");    
    cout << "p1: ";
    p1->printMyName();
    strcpy(p2->name, "Fido");
    cout << "p2: ";
    p2->printMyName();
    cout << "p3: ";
    p3->printMyName();

    delete p1;
    delete p2;
    delete p3;

    cout << "Done!!" <<endl;
}