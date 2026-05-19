/**
 * @file 260518_number_to_string.cpp
 * @brief 
 * @version 0.1
 * @date 2026-05-18
 * 
 * @copyright Copyright (c) 2026
 * 
 * Tags: to_string 
 * 
 * 
 */
#include <iostream>
#include <filesystem>

using namespace std;

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    

    cout << "From numbers to strings.." << endl;
    cout << to_string(1) << endl;
    cout << to_string(1.0) << endl;

    /**
     * cout interprets both as ints
     */
    cout << "No conversion, numbers to cout.." << endl;
    cout << 1 << endl;
    cout << 1.0 << endl;

    cout << "From strings to numbers.."<<endl;
    cout << stoi("1") << endl;
    cout << stod("1.0") << endl;
    cout << stod("1.01") << endl;


}