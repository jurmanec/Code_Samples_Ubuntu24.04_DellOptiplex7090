//============================================================================
// Name        : DynamicPuppies.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <iomanip>
#include <fstream>
#include <climits>
#include <cstring>
using namespace std;


struct Puppy {
	char name[24];
	char breed[24];
	int	ageInYears;
	float weight;
};


void clearCIN(void) {
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}//clearCIN


void printPuppys(Puppy puppyArray[], int puppySize) {
	cout << setw(24) << "Name" << setw(24) << "Breed" << setw(12) << "Age" << setw(12) << "Weight" << endl;
	cout << setw(24) << "====" << setw(24) << "=====" << setw(12) << "===" << setw(12) << "======" << endl;
	for (int i=0; i<puppySize; i++) {
		cout << setw(24) << puppyArray[i].name << setw(24) << puppyArray[i].breed << setw(12) << puppyArray[i].ageInYears << setw(12) << fixed << setprecision(2) << puppyArray[i].weight << endl;
	}//for
	cout << endl << endl;
}//printPuppys


void printPuppyPointers(Puppy* puppyArray[], int puppySize) {
	cout << setw(24) << "Name" << setw(24) << "Breed" << setw(12) << "Age" << setw(12) << "Weight" << endl;
	cout << setw(24) << "====" << setw(24) << "=====" << setw(12) << "===" << setw(12) << "======" << endl;
	for (int i=0; i<puppySize; i++) {
		cout << setw(24) << puppyArray[i]->name << setw(24) << puppyArray[i]->breed << setw(12) << puppyArray[i]->ageInYears << setw(12) << fixed << setprecision(2) << puppyArray[i]->weight << endl;
	}//for
	cout << endl << endl;
}//printPuppys


int main() {
	string		tempName;
	string 		tempBreed;
	int			tempAge;
	float 		tempWeight;
	fstream 	puppyFile;
	Puppy 		tempPuppy;
	char 		menuChoice = 'C';
	int 		endFilePosition = 0;
	int 		totalPuppies = 0;
	int 		puppyCtr = 0;
	Puppy* 		PuppyArray = nullptr;				//Dynamic array pointer of puppies
	Puppy** 	PuppyPointerArray = nullptr;		//Dynamic array pointer of puppy pointers
	Puppy* 		PuppyPointer = nullptr;				//Temporary puppy pointer


	cout << "Welcome to my Puppy Application" << endl << endl; // prints !!!Hello World!!!
	while(toupper(menuChoice) != 'X') {
		while(true) {
			cout << "Puppy Menu" << endl;
			cout << "----------" << endl;
			cout << "<W>rite to the Puppy File" << endl;
			cout << "<R>ead from the Puppy File" << endl;
			cout << "<P>ointer read from the Puppy File" << endl;
			cout << "E<x>it from this program" << endl;
			cout << "Pick one >>> ";
			cin.get(menuChoice);
			clearCIN();
			if (toupper(menuChoice) == 'W' || toupper(menuChoice) == 'R' || toupper(menuChoice) == 'P' || toupper(menuChoice) == 'X') {
				break;
			}//if
			else {
				cout << "Invalid option, please try again" << endl << endl;
			}//else
		}//while
		if (toupper(menuChoice) != 'X') {
			if (toupper(menuChoice) == 'W') {
				puppyFile.open("puppyFile.bin", ios::out | ios::binary | ios::app);
				while(true) {
					cout << "Enter a puppy's name (exit to quit): ";
					getline(cin, tempName);
					if (tempName == "exit") {
						break;
					}//if
					else {}
					cout << "Enter a puppy's breed: ";
					getline(cin, tempBreed);
					cout << "Enter a puppy's age in years: ";
					cin >> tempAge;
					clearCIN();
					cout << "Enter a puppy's weight: ";
					cin >> tempWeight;
					clearCIN();
					strcpy(tempPuppy.name, tempName.c_str());
					strcpy(tempPuppy.breed, tempBreed.c_str());
					tempPuppy.ageInYears = tempAge;
					tempPuppy.weight = tempWeight;
					puppyFile.write(reinterpret_cast<char *>(&tempPuppy), sizeof(tempPuppy));
				}//while
				puppyFile.close();
			}//if
			//Read puppies from the file and place them in a dynamically allocated array of puppies
			else if (toupper(menuChoice) == 'R') {
				puppyFile.open("puppyFile.bin", ios::in | ios::binary);
				if (!puppyFile.fail()) {
					puppyFile.seekg(0, ios::end);
					endFilePosition = puppyFile.tellg();
					totalPuppies = endFilePosition/sizeof(Puppy);
					cout << "Total puppies in file: " << totalPuppies << endl << endl;
					PuppyArray = new Puppy[totalPuppies]; // dynamically allocated array.
					puppyFile.seekg(0, ios::beg);
					puppyCtr = 0;
					puppyFile.read(reinterpret_cast<char *>(&tempPuppy), sizeof(Puppy));
					while(!puppyFile.eof()) {
						PuppyArray[puppyCtr] = tempPuppy;
						puppyCtr++;
						puppyFile.read(reinterpret_cast<char *>(&tempPuppy), sizeof(Puppy));
					}//while
					puppyFile.close();
					printPuppys(PuppyArray, totalPuppies);
					//Delete the dynamically allocated array of Puppyies (will delete the static puppies)
					delete [] PuppyArray;
				}//if
				else {
					cout << "Error opening the Puppy File" << endl << endl;
				}
			}//else if
			//Read puppies from the file and place them in a dynamically allocated array of puppy pointers
			else if (toupper(menuChoice) == 'P') {
				puppyFile.open("puppyFile.bin", ios::in | ios::binary);
				if (!puppyFile.fail()) {
					puppyFile.seekg(0, ios::end);
					endFilePosition = puppyFile.tellg();
					totalPuppies = endFilePosition/sizeof(Puppy);
					cout << "Total puppies in file: " << totalPuppies << endl << endl;
					PuppyPointerArray = new Puppy*[totalPuppies];
					puppyFile.seekg(0, ios::beg);
					puppyCtr = 0;
					PuppyPointer = new Puppy;
					puppyFile.read(reinterpret_cast<char *>(PuppyPointer), sizeof(Puppy));
					while(!puppyFile.eof()) {
						PuppyPointerArray[puppyCtr] = PuppyPointer;
						puppyCtr++;
						PuppyPointer = new Puppy;
						puppyFile.read(reinterpret_cast<char *>(PuppyPointer), sizeof(Puppy));
					}//while
					delete PuppyPointer;		//delete the temporary pointer not needed since EOF
					puppyFile.close();
					printPuppyPointers(PuppyPointerArray, totalPuppies);
					//Delete all dynamically allocated puppies and set their address in the array to nullptr
					for (int i=0; i<totalPuppies; i++) {
						delete PuppyPointerArray[i];
						PuppyPointerArray[i] = nullptr;
					}//for
					//Print the address of each puppy - should all be zero
					for (int i=0; i<totalPuppies; i++) {
						cout << PuppyPointerArray[i] << endl;
					}//for
					//Delete the dynamically allocated array of Puppy pointers (does not delete the puppies!)
					delete [] PuppyPointerArray;
				}//if
				else {
					cout << "Error opening the Puppy File" << endl << endl;
				}
			}//else if
			else {
				cout << "Something went wrong.  Program ending" << endl;
			}//else
		}//if
		else {
			cout << endl;
		}//else
	}//while
	cout << "Program ending, have a nice day" << endl;


	return 0;
}
