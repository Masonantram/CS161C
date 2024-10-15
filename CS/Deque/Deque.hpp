//
// Created by mason on 10/7/2024.
//
#include <string>
#ifndef DEQUE_DEQUE_HPP
#define DEQUE_DEQUE_HPP

class Deque
{
    int size;
    int* array;
    int head;
    int tail;
    int count;

public:

    Deque(int size = 20);

    ~Deque();

    void addTail(int value);
    int removeHead();
    bool isEmpty();
    std::string dumpArray();
    void resize();
    std::string listQueue();
    void addHead(int value);
    int removeTail();

    int getHead() {return head;}
    int getTail() {return tail;}
    int getCount() {return count;}
    int getSize() {return size;}
};


#endif //DEQUE_DEQUE_HPP
