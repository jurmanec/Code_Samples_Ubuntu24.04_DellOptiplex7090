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
 * Observe that the puppy objects are destroyed when main exits.
 */
int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    
    Puppy p1; // the declaration executes the constructor.
    Puppy p2;

    strcpy(p1.name, "Snoopy");    
    cout << "p1: ";
    p1.printMyName();
    strcpy(p2.name, "Fido");
    cout << "p2: ";
    p2.printMyName();
    
}