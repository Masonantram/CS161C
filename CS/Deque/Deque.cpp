//
// Created by mason on 10/7/2024.
//

#include "Deque.hpp"
#include <stdexcept>
#include <string>
#include <iostream>

Deque::Deque(int size): size(size), head(-1), tail(0), count(0)
{array = new int[size];}

Deque::~Deque() { delete[] array;}

void Deque::addTail(int value) // program works until we add eight more numbers
{
    if (count == size)
    {
        resize();
    }

    count++;
    array[tail++] = value;

    if (tail >= size)
    {
        tail= 0;
    }

    std::cout << "head is " << head << " and tail is = " << tail << '\n';
    std::cout << "array is now ";
    for (int i = 0; i < size; i++)
    {
        if (array[i] < 0 || array[i] > 40)
        {
            array[i] = 0;
        }
        std::cout << array[i] << " ";
    }
    std::cout << '\n';
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

std::string Deque::dumpArray()
{
    std::string answer;

   for (int i = 0; i < size; i++)
   {
       answer += std::to_string(array[i]);
       answer += " ";
   }

    return answer;

}



void Deque::resize()
{
    int* temp = new int[size *2];

   if (head <= 0)
   {
       for (int i = 0; i < size; i++)
       {
           temp[i] = array[i];
       }
       array = temp;
       size *= 2;
   }
   else
   {
       int start = head;
       int index = 0;

       while (start < size)
       {
           temp[index++] = array[start++];
       }

       for (int i = 0; i < tail; i++)
       {
           temp[index++] = array[i];
       }

       array = temp;
       size *=2;
   }

}