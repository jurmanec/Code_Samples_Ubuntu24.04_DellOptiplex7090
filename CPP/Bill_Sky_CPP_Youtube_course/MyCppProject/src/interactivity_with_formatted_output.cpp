#include <iostream>
#include <filesystem>
#include "MyProject/utils.hpp"
#include "interactivity_with_formatted_output.h"

using namespace std;

/**
 * Use &sales to get pass by reference behavior for the int variable
 */
void getSalesPersonData(string &name, double &sales, int personNdx) {
    // Sales person  info
    int personNumber = personNdx + 1;
    cout << "Please enter the full name for Sales Person #"<< personNumber <<": ";
    getline(cin, name);
    cout << "Now, enter the total sales from the previous month for Sales Person #"<< personNumber <<": ";
    cin >> sales;
    numericInputHandleError();
}

/**
 * Sales Rep Sales Forecast Report
 * ================================
 * Sales Persons Name   Monthly Sales   Average per Year    Average per Decade
 * ------------------   -------------   ----------------    ------------------
 * Sales-Person-1       x               x*12                X*12*10
 * Sales-Person-1       x               x*12                X*12*10
 * Sales-Person-1       x               x*12                X*12*10
 */
void generateReport(string names[4], double sales[4]) {
    // Generate report
    // Padding
    cout << endl
         << endl;
    // Report header 
    cout <<  "Sales Rep Sales Forecast Report" << endl;
    cout <<  "==============================="<< endl;
    // Report columns 
    cout << setw(36) << left << "Sales Person's Name";
    cout << right << setw(20) << "Monthly Sales";
    cout << setw(20) << "Average per Year";
    cout << setw(20) << "Average per Decade" << endl;
    cout << setw(36) << left << "-------------------";
    cout << right << setw(20) << "-------------";
    cout << setw(20) << "----------------";
    cout << setw(20) << "------------------" << endl;
    // Report data
    for (int i = 0; i < 4; i++) {
        cout << setw(36) << left << names[i];
        cout << right << setw(20) << fixed << setprecision(2) << sales[i]; // fixed (fixed point) and set precision (number of decimal digits)
        cout << setw(20) << fixed << setprecision(2) << sales[i] * 12;
        cout << setw(20) << fixed << setprecision(2) << sales[i] * 12 * 10;
        cout << endl;
    }   
}

int main() {
    // Data definiton
    string salesPersonFullName1;
    string salesPersonFullName2;
    string salesPersonFullName3;
    string salesPersonFullName4;
    string names[4] = {
        salesPersonFullName1,
        salesPersonFullName2,
        salesPersonFullName3,
        salesPersonFullName4
    };
    double salesPerson1MonthlySales = 0.00;
    double salesPerson2MonthlySales = 0.00;
    double salesPerson3MonthlySales = 0.00;
    double salesPerson4MonthlySales = 0.00;
    double sales[4] {
        salesPerson1MonthlySales,
        salesPerson2MonthlySales,
        salesPerson3MonthlySales,
        salesPerson4MonthlySales
    };

    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";
    cout << "Hello, welcome to my Sales-Person Analysis Program." << endl;

    for (int i = 0; i < 4; i++) {
        getSalesPersonData(names[i], sales[i], i);
    }
    generateReport(names, sales);

}
