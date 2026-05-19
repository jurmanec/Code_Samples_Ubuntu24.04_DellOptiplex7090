/**
 * @file sec2_vid3_single_responsibility.cpp
 * @brief 
 * @version 0.1
 * @date 2026-05-18
 * 
 * @copyright Copyright (c) 2026
 * 
 * Tags: design_patterns solid single_responsibility encapsulation 
 */

#include <iostream>
#include <vector>
#include <fstream>
/**
 * lexical caste provides a safe way to convert between other data types and strings
 */
//#include <boost/lexical_cast.hpp>


using namespace std;
//using namespace boost;

/**
 * Stores journal (title and entries)
 */
struct Jounral {
    string title;
    vector <string> entries;

    Jounral(const string& title): title(title) {}

    void add_entry(const string& entry) {
        static int count = 1;
        entries.push_back(to_string(count++) + ": " + entry);
    }

    // add persistence logic for the object?
    
};

/** 
 * Encapsulates the responsibility of persistence
 */
struct PersistenceManager {
    void static save(Jounral j, const string& filename) {
        ofstream ofs(filename);
        for (auto& e: j.entries) {
            ofs << e << endl;
        }
    }
};

int main() {

    Jounral j{"My Diary"};
    j.add_entry("I ate a bug");
    j.add_entry("I was happy today");

    // journal.save(diary.text);
    PersistenceManager pm;
    pm.save(j, "diary.txt");

}