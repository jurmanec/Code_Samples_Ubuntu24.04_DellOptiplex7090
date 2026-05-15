#include <iostream>
#include <filesystem>

using namespace std;

void numericInputHandleError() {
    // only do the following after numeric input
    cin.clear();                                         //  clear the error flag
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear the buffer
} // note that cin and cout are streams: console in and console out.
