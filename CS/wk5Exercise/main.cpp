#include <iostream>
#include <iomanip>

int main()
{
   const int SIZE = 10;
   int* array = new int[100];
   int newArray[SIZE][SIZE];

   for (int i = 0; i < SIZE; i++)
   {
       for (int j = 0; j < SIZE; j++)
       {
           newArray[i][j] = *(array + (i * SIZE + j));
       }
   }

    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            newArray[i - 1][j - 1] = (i * j);
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << std::setw(5) << newArray[i][j];

        }
        std::cout << '\n';

    }

   delete [] array;

    return 0;
}

/*
 * Your program should dynamically create an array of 100 values.
 * Then it should treat it as a 2D array with 10 rows and 10 columns.
 * Using nested for loops, fill the array with the multiplication table from 1*1 to 10*10.
 * Then using nested for loops, display it as 10 rows of 10 neat columns.

This is essentially the multiplication table from week 3 but using a flattened array that was dynamically allocated.
 */