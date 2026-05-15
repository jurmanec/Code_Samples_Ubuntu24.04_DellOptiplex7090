#include "Puppy.h"

using namespace std;

Puppy::Puppy() {
    cout << "Creating puppy "<< this <<".." <<endl;
}

Puppy::~Puppy() {
    cout << "Destroying puppy "<< this->name << " at "<<this<<".." <<endl;
}

void Puppy::printMyName(void) {
    cout << this->name << endl;
}