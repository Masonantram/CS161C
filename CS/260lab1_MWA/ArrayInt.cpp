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

    if (lastIndex == size)
    {
        int* temp = new int [size *2];
        for (int i = 0; i < size; i++)
        {
            temp[i] = theArray[i];
        }
        theArray = temp;
        size = size*2;
    }
}

int ArrayInt::getLast () {

    if (empty) {
        throw std::out_of_range("Array is empty!");
    }

    return theArray[lastIndex];
}

void ArrayInt::deleteLast()
{
    if (empty)
    {
        throw std::out_of_range("Array is empty!");
    }
        lastIndex--;

    if (lastIndex < 0)
    {
        empty = true;
    }
}

void ArrayInt::resize (int value)
{
   if (value > size) {
       int *temp = new int[value];
       for (int i = 0; i < size; i++) {
           temp[i] = theArray[i];
       }
       theArray = temp;
       size = value;
   }
}

std::string ArrayInt::listElements()
{
    if (empty)
    {
        return "Empty Array";
    }
    else
    {
        std::string answer;

        for (int i = 0; i <= lastIndex; i++)
        {
            answer += std::to_string(theArray[i]);
            answer += " ,";
        }
        return answer;
    }
}