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
    else if (tail >= size)
    {
        tail= 0;
    }

    count++;
    array[tail++] = value;

}

int Deque::removeHead()
{
    if (count == 0)
    {
        throw std::out_of_range ("Array is empty in removeHead");
    }

    count--;

    if (head < 0)
    {
        head = 0;
    }

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

   if (head < 0)
   {
       for (int i = 0; i < size; i++)
       {
           temp[i] = array[i];
       }
       array = temp;
       size *= 2;
       head = -1;
       tail = count ;
   }
   else
   {
       int start = head;
       int index = 0;

       while (start < size)
       {
           //std::cout << "adding start" << start << '\n';
           temp[index++] = array[start++];
       }

       for (int i = 0; i < tail; i++)
       {
          // std::cout << "adding array " << array[i] << '\n';
           temp[index++] = array[i];
       }

       array = temp;
       size *=2;
       head = -1;
       tail = count ;
   }
/*std::cout << "array after resize is ";
    for (int i = 0; i < size; i++)
    {
        if (array[i] > 50 || array[i] < 0)
        {
            array[i] = 0;
        }
        std::cout << array[i] << "  ";
    }
    std::cout << '\n';*/
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

    if (head < 0)
    {
        for (int i = 0; i < count; i++)
        {
            answer += std::to_string(array[i]);
            answer += " ";
        }
    }
    else
    {
        int start = head ;

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
  //  std::cout << '\n' << "head before adding is " << head << '\n';
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

  /*  for (int i = 0; i < size; i++)
    {
        if (array[i] > 40 || array[i] < 0)
        {
            array[i] = 0;
        }
        std::cout << array[i] << " ";
    }
    std::cout << '\n'; // test display*/
    count++;
}

int Deque::removeTail()
{
    if (count == 0)
    {
        throw std::out_of_range("Array is empty in removeTail");
    }
    count--;
    
    if (tail <= 0)
    {
        tail = size;
    }
        return array[--tail];
}

void Deque::solveThink (int numArray[], int num)
{
    for (int i = num - 1; i >=0; i--) {
        addTail(numArray[num-- - 1]);
    }

}