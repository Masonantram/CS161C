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

void Deque::addTail(int value)
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
}

int Deque::removeHead()
{
    if (count == 0)
    {
        throw std::out_of_range ("Array is empty");
    }

    count--;

    if (head >= size)
    {
        head = 0;
    }

   /* std::cout << '\n' << "array is now "; //test
    for (int i = head; i < size; i++)
    {
        if (array[i] < 0 || array[i] > 99)
        {
            array[i] = 0;
        }
        std::cout << array[i] << " ";
    }
    std::cout << '\n';*/

    return array[head++];
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

   for (int i = 0; i < count; i++)
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
       head = 0;
       tail = count;
   }
   else
   {
       int start = head + 1;
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
       head = 0;
       tail = count;
   }

}

std::string Deque::listQueue()
{
    std::string answer;

  /*  std::cout << '\n' << "head = " << head << "and tail = " << tail << "and count = " << count << '\n';
    for (int i = 0; i < size; i++)
    {
        if (array[i] < 0 || array[i] > 99)
        {
            array[i] = 0;
        }
        answer += std::to_string(array[i]);
        answer += " ";
    }*/

    if (head <= 0)
    {
        for (int i = 0; i < count; i++)
        {
            answer += std::to_string(array[i]);
            answer += " ";
        }

    }
    else
    {
        int start = head + 1;
        int index = 0;

        for (int i = start; i <= count; i++)
        {
            answer += std::to_string(array[i]);
            answer += " ";

        }

        for (int i = 0; i < tail; i++)
        {
            answer += std::to_string(array[i]);
            answer += " ";
        }
    }


    return answer;
}

void Deque::addHead(int value)
{
    if (count == size)
    {
        resize();
    }

    if (head <= 0)
    {
        head = size;
    }

   // std::cout << "head before adding " << value << " is " << head << '\n';

    array[--head] = value;
   // std::cout << "head after adding is " << head << '\n';

    for (int i = 0; i < size; i++)
    {
        if (array[i] > 40 || array[i] < 0)
        {
            array[i] = 0;
        }
        std::cout << array[i] << " ";
    }
    std::cout << '\n'; // test display
    count++;
}

int Deque::removeTail()
{
    if (count == 0)
    {
        throw std::out_of_range("Array is empty");
    }

    count--;

   // std::cout << "tail before removing is " << tail << '\n';
    if (tail <= 0)
    {
        tail = size;

    }

        return array[--tail];


}