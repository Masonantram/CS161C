//
// Created by mason on 10/23/2024.
//
#include<string>
#include<cmath>
#include<iostream>
#ifndef HASHTABLE_STRINGHASH_HPP
#define HASHTABLE_STRINGHASH_HPP


class StringHash
{
    int size = 11;
    std::string* array;
    int count = 0;
    std::string empty = "_empty_";
    std::string deleted = "_deleted_";

public:

    StringHash();
    StringHash(int size);
    ~StringHash();

    bool isEmpty();
    bool isEmpty(int index);
    void resize();
    void getPrime(int& value);
    bool isPrime(int value);
    int hashFunc(std::string value);
    void addItem(std::string value);
    bool findItem(std::string value);
    void removeItem(std::string value);
    std::string displayTable();

    int getSize(){return this->size;}
    int getCount(){return this->count;}
};

void getPrime(int value);
void isPrime(int value);


#endif //HASHTABLE_STRINGHASH_HPP
