//
// Created by mason on 10/23/2024.
//
#include<string>
#include<iostream>
#include<cmath>

#ifndef HASHTABLE_CHAINHASH_HPP
#define HASHTABLE_CHAINHASH_HPP

class ChainLink
{public:
    std::string data;
    ChainLink* next;
    std::string empty = "_empty_";
    std::string deleted = "_deleted_";
    ChainLink();
    ChainLink(std::string value);

    ChainLink* getNext(){return this->next;}
    void setNext(ChainLink* next){this -> next = next;}
    std::string getData(){return this->data;}
};


class ChainHash {
public:
    int size = 7;
    ChainLink* array = nullptr;
    std::string empty = "_empty_";
    std::string deleted = "_deleted_";
    int count = 0;

    ChainHash();
    ChainHash(int size);
    ~ChainHash();

    int hashFunc(std::string value);
    void addItem(std::string value);
    bool findItem(std::string value);
    void removeItem(std::string value);
    void resize();
    std::string displayTable();
    void getPrime(int& value);
    bool isPrime(int value);
};

#endif //HASHTABLE_CHAINHASH_HPP
