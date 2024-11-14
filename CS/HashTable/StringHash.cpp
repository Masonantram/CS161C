//
// Created by mason on 10/23/2024.
//

#include "StringHash.hpp"

StringHash::StringHash():array(new std::string[size]){for (int i = 0; i < size; i++) {array[i] = empty;}}
StringHash::StringHash(int size):size(size), array(new std::string[size]) {for (int i = 0; i < size; i++) {array[i] = empty;}}
StringHash::~StringHash(){delete [] array;}

bool StringHash::isEmpty(){
    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (array[i] != empty && array[i] != deleted)
        {
            found = true;
        }
    }
    return found;
}
bool StringHash::isEmpty(int index) {
    bool found = false;

    if (array[index] != empty && array[index] != deleted) {
        found = true;
    }
    return found;
}

void StringHash::resize() {

    std::string* tempArray = new std::string[size];
    int tempSize = size;

    for (int i = 0; i < size; i++)
    {
        tempArray[i] = array[i];
    }

    size *= 2;
    getPrime(size);

    StringHash* temp = new StringHash(size);

    for (int i = 0; i < tempSize; i++)
    {
        temp->addItem(tempArray[i]);
    }

    array = temp->array;
    count = temp->count;
}

void StringHash::getPrime(int& value)
{
    while (!isPrime(value))
    {
        value++;
    }
}

bool StringHash::isPrime(int value)
{
    if (value <= 1)
    {
        return false;
    }

    int limit = sqrt(value);

    for (int i = 2; i <= limit; i++)
    {
        if (value % i == 0)
        {
            return false;
        }
    }
    return true;
}

int StringHash::hashFunc(std::string value){
    int code = 0;
    for (int i = 0; i < value.length(); i++)
    {

       code *= 128;
       code += (value[i]);
        code %= size;
    }


    return code;
}

void StringHash::addItem(std::string value){

    if (count > size/2)
    {
        resize();
    }

    int index = hashFunc(value);

    while(array[index] != empty && array[index] != deleted)
    {
        index++;
        if (index >=size)
        {
            index = 0;
        }
        count++;
    }
    array[index] = value;

}

bool StringHash::findItem(std::string value){

    int index = hashFunc(value);
    bool done = false;

    while (array[index] != empty && !done)
    {
        if (array[index] == value)
        {
            done = true;
        }
        else
        {
            index++;
            if (index >= size)
            {
                index = 0;
            }
        }
    }

    return done;
}

void StringHash::removeItem(std::string value){
    int index = hashFunc(value);
    bool done = false;

    while (array[index] != empty && !done)
    {
        if (array[index] == value)
        {
            array[index] = deleted;
            done = true;
        }
        else
        {
            index++;
            if (index >= size)
            {
                index = 0;
            }

            if (array[index] == empty || array[index] == deleted)
            {
                done = true;
            }
        }
    }
}

std::string StringHash::displayTable(){

    std::string answer;
    for (int i = 0; i < size; i++)
    {
       answer += array[i];
       answer += '\n';
    }

    return answer;
}