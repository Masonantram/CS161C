//
// Created by mason on 10/7/2024.
//

#include "Deque.hpp"
#include <stdexcept>

Deque::Deque(int size): size(size), head(-1), tail(0), count(0)
{array = new int[size];}

Deque::~Deque() { delete[] array;}

void Deque::addTail(int value)
{
/*    if (count >= size)
    {
        resize();
    }*/

count++;
    array[tail++] = value;

    if (tail >= size)
    {
        tail= 0;
    }

}

int Deque::removeHead()
{
    if (count == 0)
    {
        throw std::out_of_range ("Array is empty");
    }

    count--;
    head++;

    if (head >= size)
    {
        head = 0;
    }

    return array[head];
}

bool Deque::isEmpty()
{
    if (count == 0)
    {
        return true;
    }

    return false;
}
