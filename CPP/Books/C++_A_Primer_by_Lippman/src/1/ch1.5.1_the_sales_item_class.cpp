#include <iostream>
#include <filesystem>
#include "Sales_item.h"

using namespace std;

void read_and_write_sales_items() {
    cout<<"File: " << filesystem::path(__FILE__).filename() << "\n";

    Sales_item book;
    cout << "Enter isbn, number of copies sold, and sales price: ";
    cin  >> book;
    cout << book << endl; // print back isbn, total revenue, and average price
}

int main() {

    // read_and_write_sales_items();

    Sales_item it1, it2;
    cin >> it1 >> it2; // waits for input two times
    cout << "Item 1 isbn: " << it1.isbn() << endl;
    cout << it1 + it2 << endl; // prints sum and average price

}