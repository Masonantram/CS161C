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

void ArrayInt::append (int value)
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
        for (int i = 0; i <= size; i++)
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

        for (int i = 0; i < lastIndex; i++)
        {
            answer += std::to_string(theArray[i]);
            answer += " ,";
        }
        answer += std::to_string(theArray[lastIndex]);

        return answer;
    }
}

void ArrayInt::insertAt(int index, int value)
{

    if (index < 0 || index > lastIndex || index > size)
    {
        throw std::out_of_range("Attempt to write at invalid location.");
    }

    if (lastIndex + 1 == size)
    {
        int *temp = new int[size * 2];
        for (int i = 0; i < size; i++) {
            temp[i] = theArray[i];
        }
        theArray = temp;
        size *= 2;
    }

    for (int i = lastIndex + 1; i > index; i--)
    {
        theArray[i] = theArray[i - 1];


    }
    theArray[index] = value;
    lastIndex++;
}

int ArrayInt::removeAt(int index)
{
    if (index < 0 || index > lastIndex || index > size)
    {
        throw std::out_of_range("Attempt to read from empty array.");
    }

    int value = theArray[index];

    for (int i = index; i <= lastIndex; i++)
    {
        theArray[i] = theArray[i+1];
    }
    lastIndex--;

    return value;
}

bool ArrayInt::find(int value)
{
    bool found = false;
    int index = 0;

    while (!found && index <= lastIndex)
    {
        if (theArray[index++] == value)
        {
            found = true;
        }
    }

    return found;
}

bool ArrayInt::findRemove(int value)
{
    bool found = false;
    int index = 0;

    while (!found && index <= lastIndex)
    {
        if (theArray[index] == value)
        {
            found = true;
            for (int i = index; i <= lastIndex; i++)
            {
                theArray[i] = theArray[i+1];
            }
            lastIndex--;
        }
        index++;
    }

    return found;
}

int ArrayInt::findLargest()
{
    if (empty)
    {
        throw std::out_of_range("Attempt to read from empty array.");
    }

    int largest = -1;

    for (int i = 0; i <= lastIndex; i++)
    {
        if (theArray[i] > largest)
        {
            largest = theArray[i];
        }
    }
    return largest;
}

void ArrayInt::removeLargest() {

    if (empty) {
        throw std::out_of_range("Attempt to remove from empty array.");
    }
    int largest = -1;

    for (int i = 0; i <= lastIndex; i++) {
        if (theArray[i] > largest) {
            largest = theArray[i];

        }
    }

    for (int i = 0; i <= lastIndex; i++) {
        if (theArray[i] == largest) {
            for (int j = i; j <= lastIndex; j++) {
                theArray[j] = theArray[j + 1];
            }
        }
    }
    lastIndex--;
}

int ArrayInt::getAt(int index)
{
    if (index < 0 || index > size)
    {
        throw std::out_of_range("Attempt to read at invalid location.");
    }

    return theArray[index];
}

void ArrayInt::setAt(int index, int value)
{
    if (index < 0 || index > size)
    {
        throw std::out_of_range("Attempt to store at invalid location.");
    }

    theArray[index] = value;
    empty = false;
    if (index > lastIndex)
    {
        lastIndex = index;
    }

}



























