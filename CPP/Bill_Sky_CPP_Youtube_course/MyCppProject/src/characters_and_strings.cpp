#include <iostream>
#include <string> // need for string

using namespace std; // string is in this namnespace

// in C++, we have built in primitive types 
// e.g. short int, int, long int, float, double, 
// char, etc.
// We also have classes and objects. 
// Here we see the construction of a string object, a string literal contruction. 
int main() {

    char middleInitial = 'I';
    string fullName = "Jacob Urmanec"; // string is not a primitive datatype. It is a class in the standard C++ library. 
    // Note there are 13 characters, so 13 bytes of data for fullName's data.

    cout << "middle initial: " << middleInitial << "\n";
    cout << "sizeof(char): " << sizeof(char) << "\n"; // one byte
    cout << "full name: " << fullName << "\n";
    cout << "sizeof(string): " << sizeof(string) << "\n"; // 
    cout << "sizeof(fullName): " << sizeof(fullName) << "\n"; // fullName does not contain the data. It is a pointer to the data
    cout << "sizeof.size(): " << fullName.size() << "\n"; // string objects have a .size() method

}                                                                                                                                                                                                                                                                                                                                                       