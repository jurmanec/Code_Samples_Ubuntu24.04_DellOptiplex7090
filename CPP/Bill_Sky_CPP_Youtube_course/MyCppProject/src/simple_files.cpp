#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;

int main() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    
    // ofstream is for reading.
    // ifstream is for writing.
    // declare output stream pointer variable.
    // 1) Open the file (for output)
    // 2) Write data to the file
    // 3) Close the file 
   
    string userString;    

    ofstream outFile; 

    outFile.open("someStrings.txt"); // opening the file will create it if it does not exist.
    if (outFile.fail()) {
        cout<<"An error occured creating the file."<<endl;
    } else {
        cout<<"File created!!"<<endl;
    }

    // ifstream thisFile("someStrings2.txt");
    // if (thisFile.is_open()) {
    //     cout<<"someStrings2.txt is open!!"<<endl;
    // }
    // thisFile.open("someStrings2.txt");
   
    bool firstLine = true;
    //Process the file
    while(userString != "-999") {
        cout<<"Please enter a string to save to a file (-999 to quit): ";
        getline(cin, userString);
        if (userString == "-999") {
            break;
        } else {
            if (firstLine) {
                outFile << userString;
                firstLine = false;
            } else {
                outFile << endl;
                outFile << userString;
            }
        }
    }
    outFile.close();

    

    cout<<"Done!!"<<endl;
}