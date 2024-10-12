#include <iostream>
#include <iomanip>

const int SIZE = 10;



void fillArray (int table[][SIZE])
{
    for (int i = 1; i <= SIZE; i++)
    {
        for (int j = 1; j <= SIZE; j++)
        {
            table[(i - 1)][(j - 1)] = (i * j);

        }
    }

}

void displayArray (const int table[][SIZE])
{

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << std::setw(5) << table[i][j];

        }
        std::cout << '\n';

    }
}

int main()
{
    int table[SIZE][SIZE];

    fillArray(table);

    displayArray(table);

    return 0;
}



/*
For this exercise, create a two-dimensional integer array in main that is 10x10.
Write a function that is passed this array and fills it so that the first row is the multiples of one, the second row
is the multiples of two, and so on.

Write a display function that displays the table, one row at a time. The numbers should be lined up in columns.
The display function should be passed the array safely, so that it cannot be changed in the function.
 */