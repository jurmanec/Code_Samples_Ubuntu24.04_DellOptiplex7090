#include <iostream>
#include <filesystem>

using namespace std;

enum class Error_action {
    IGNORE,
    THROWING,
    TERMINATING,
    LOGGING
};

/** 
 * constexpr specifies that an object or function can be evaulauted at compile time (maybe like static in java?). 
 * 
 * Using it can significantly improve program performance.
 * 
 * const key word can be evaluated at runtime. However constexpr are evaluated at compile time.
 * 
 * */
constexpr Error_action default_Error_action = Error_action::THROWING;

enum class Error_code {
    RANGE_ERROR,
    LENGTH_ERROR
};

template<Error_action action = default_Error_action, class C>
constexpr void expect(C cond, Error_code x) {
    if constexpr (action == Error_action::LOGGING) {
        
    }
}


int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    
}