#ifndef PUPPY_H
#define PUPPY_H
#include <iostream>

#pragma once

class Puppy {

    public:    
    Puppy(); // constructor
    ~Puppy(); // destructor

    char name[32];
    char breed[24];
    int ageInYears;
    float weightInPounds;

    void printMyName(void);

    private:

};
#endif