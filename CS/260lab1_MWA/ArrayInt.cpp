//
// Created by mason on 9/30/2024.
//

#include "ArrayInt.hpp"
#include <stdexcept>
#include <iostream>

// constructor, set up the array
ArrayInt::ArrayInt(int size) : size(size), lastIndex(0) {
    theArray = new int[size];
}

// destructor, delete the array and go away
ArrayInt::~ArrayInt() { delete[] theArray; }

void ArrayInt::append (int value) // need to incorporate exception handling
{

    if (empty) {
        theArray[0] = value;
        empty = false;
    }
    else {
        theArray[++lastIndex] = value;
    }

}

int ArrayInt::getLast () {

    if (lastIndex >= 0) {
        return theArray[lastIndex];
    }
}

void ArrayInt::deleteLast()
{
    if (lastIndex > 0) {
        lastIndex--;
    }
}
