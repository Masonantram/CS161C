#include <iostream>
#include <algorithm>
#include <random>
#include <iomanip>
#include <limits>
#include <exception>
#include "header.hpp"

inline int getIndex (const int rowIndex, const int colIndex, const int colLength)
/* Flattens two-dimensional arrays into one-dimension for easy passing through functions. Takes in the current row and
 * column coordinates and the max column length. Returns the one-dimensional integer equivalent. */
{
    return (rowIndex * colLength) + colIndex;
}

int getInteger (int min, int max)
//Requests and validates an integer from the user. Takes in the minimum and maximum values allowed, returns the integer.
{
    int num;
    bool valid = false;

    do
    {
        std::cin >> num;

        if (std::cin.fail() || num < min || num > max)
        {
            std::cout << "Please choose a row between 1 and " << max << "." << '\n';
        }
        else valid = true;
    } while (!valid);

    return num;
}

void shuffle (char* board, int size)
//shuffles the filled board array. Takes in the board array and size, no return value.
{
    int seed = (unsigned)time(0);

    std::shuffle (board,board + (size - 1),std::default_random_engine(seed) );
}

void displayInstructions ()
//Displays full instructions on the first run, and truncated instructions after that. No parameters or return.
{
    static int counter = 1;

    if (counter == 1)
    {
        std::cout << "Welcome to this game of memory!" << '\n';
        std::cout << "In this game, your goal is to match pairs of letters until the board is clear. " << '\n';
        std::cout << "To choose a space, you will first select your desired row, then the column of the space." << '\n';
        std::cout << "There are two modes: easy (eight pairs) and hard (fifteen pairs). Good luck!" << '\n';
    }
    else
    {
        std::cout << "Remember, match pairs until the board is clear." << '\n';
    }

    counter++;
}

void difficulty (int* mode, int* rowLength, int* colLength)
/* Allows the user to choose the difficulty of the game. Takes in empty variables for the difficulty and number of
rows/columns of the board. No explicit return. */
{
    bool valid = false;
    int choice;

    do
    {
        std::cout << "Please enter 1 for easy mode (16 cards) or 2 for hard (30 cards)." << '\n';
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > 2)
        {
            std::cout << "Please choose 1 for easy or 2 for hard." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            *mode = choice;
            (valid = true);
        }

        if (*mode == 1)
        {
            *rowLength = EASY_ROW;
            *colLength = EASY_COL;
        }

        if (*mode == 2)
        {
            *rowLength = HARD_ROW;
            *colLength = HARD_COL;
        }

    } while (!valid);
}


char* createBoard (int mode)
// creates and fills the board. Takes in the difficulty setting, returns a dynamically-allocated board array.
{
    int easy = 1, hard = 2, start = 0, size;

    char charArray[15]{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                       'K', 'L', 'M', 'N', 'O'};


    if (mode == easy)
    {
        size = EASY_ROW * EASY_COL;
    }

    if (mode == hard)
    {
        size = HARD_ROW * HARD_COL;
    }

    char *board = new char[size];

    for (int i = 0; i < (size / 2); i++)
    {
        *(board + i) = charArray[i];
    }


    for (int i = (size / 2); i < size; i++)
    {
        *(board + i) = charArray[start++];
    }

    shuffle (board, size);

    return board;
}

void showBoard (const char* board, int rowLength, int colLength)
//Displays the initial board. Takes in board array and number of rows/columns, no explicit return.
{
    for (int i = 0; i < rowLength; i++)
    {
        for (int j = 0; j < colLength; j++)
        {
            if (*(board + getIndex(i, j, colLength)) != SPACE)
            {
                std::cout << "|" << std::setw(2) << UNKNOWN << std::setw(2) ;
            }
            else
            {
                std::cout << "|"  << std::setw(2) << *(board + getIndex(i, j, colLength)) << std::setw(2);
            }
        }

        std::cout << std::setw(2) << "|"  << '\n';
    }
}

void showBoard (const char* board, int rowLength, int colLength, const char* move, int row1, int col1)
/* Overloaded function, displays updated board after first move. Takes in board array, number of rows/columns,
 * move array, and move coordinates. No return. */
{
    for (int i = 0; i < rowLength; i++)
    {
        for (int j = 0; j < colLength; j++)
        {

            if (*(board + getIndex(i, j, colLength)) != SPACE &&
                *(move + getIndex(i, j, colLength)) !=  *(move + getIndex(row1, col1, colLength)))
            {
                std::cout << "|" << std::setw(2) << UNKNOWN << std::setw(2) ;
            }
            else
            {
                std::cout << "|"  << std::setw(2) << *(board + getIndex(i, j, colLength)) << std::setw(2);
            }
        }
        std::cout << std::setw(2) << "|"  << '\n';
    }
}
void showBoard (const char* board, int rowLength, int colLength, const char* move, int row1, int col1, int row2, int col2)
/* Overloaded function, displays updated board after both moves. Takes in board array, number of rows/columns,
 * move array, and move coordinates. No return. */
{
    for (int i = 0; i < rowLength; i++)
    {
        for (int j = 0; j < colLength; j++)
        {

            if (*(board + getIndex(i, j, colLength)) != SPACE &&
                    *(move + getIndex(i, j, colLength)) !=  *(move + getIndex(row1, col1, colLength))
                    && *(move + getIndex(i, j, colLength)) !=  *(move + getIndex(row2, col2, colLength)))
            {
                std::cout << "|" << std::setw(2) << UNKNOWN << std::setw(2) ;
            }
            else
            {
                std::cout << "|"  << std::setw(2) << *(board + getIndex(i, j, colLength)) << std::setw(2);
            }
        }
        std::cout << std::setw(2) << "|"  << '\n';
    }
}

void getMove (const int rowLength,const int colLength,const char* board, char* move, int& row1, int& col1)
/* Gets and validates move from user. Takes in board array, number of rows/columns, move array, and move coordinates.
 * No return. */
{
    bool valid = false;

    do
    {

        std::cout << "Please choose the row from which you wish to choose." << '\n';
        row1 = getInteger (1, rowLength);
        row1 -= 1;


        std::cout << "Which card from this row will you choose?" << '\n';
        col1 = getInteger (1, colLength);
        col1 -= 1;

        if (*(board + getIndex(row1, col1, colLength)) == SPACE)
        {
            std::cout << "This space is already clear." << '\n';
        }
        else valid = true;

    } while (!valid);

     *(move + getIndex(row1, col1, colLength)) = MOVE;
}

void getMove (const int rowLength,const int colLength,const char* board, char* move, int row1, int col1, int& row2, int& col2)
/* Overloaded function, gets and validates second move from user. Takes in board array, number of rows/columns, move array,
 * and move coordinates. No return. */
{
    bool valid = false;

    do
    {

        std::cout << "Please choose the row from which you wish to choose." << '\n';
        row2 = getInteger(1, rowLength);
        row2 -= 1;

        std::cout << "Which card from this row will you choose?" << '\n';
        col2 = getInteger(1, colLength);
        col2 -= 1;

        if (*(board + getIndex(row2, col2, colLength)) == SPACE)
        {
            std::cout << "This space is already clear." << '\n';
        }
        else if (*(move + getIndex(row2, col2, colLength)) ==
        *(move + getIndex(row1, col1, colLength)))
        {
            std::cout << "You already chose this space." << '\n';
        } else valid = true;

    } while (!valid);

    *(move + getIndex(row2, col2, colLength)) = MOVE;
}


bool checkMatch (const char* board, int colLength, int row1, int col1, int row2, int col2)
/* Checks both moves from user against the board for matching items. Takes in the board array, number of rows/columns,
 * and both sets of move coordinates. Returns true/false for a match. */
{
    bool found = false;
    if (*(board + getIndex(row1, col1, colLength)) == *(board + getIndex(row2, col2, colLength)))
    {
        found = true;
    }

    return found;
}

void updateBoard (char* board, int colLength, int row1, int col1, int row2, int col2, int& count)
/* Updates board if there is a match. Takes in board array, number of columns, and two sets of move coordinates.
 * No return. */
{
    *(board + getIndex(row1, col1, colLength)) = SPACE;
    *(board + getIndex(row2, col2, colLength)) = SPACE;
    count++;
}

void checkDone (const char* board, int rowLength, int colLength, bool& done, int count)
/* Checks to see if board has been cleared. Takes in board array, number of rows/columns, and "done" variable.
Returns done variable as true/false. */
{

    if (count == getIndex(rowLength, 0, colLength) / 2 )
    {
        done = true;
    }
}

bool yesOrNo(std::string message)
/* Takes user input and validates for Y/y/N/n. Takes in a string message, returns true/false for yes/no. */
{
    char response;
    bool yesNo, valid;

    std::cout << message;

    do
    {
        std::cin >> response;
        if (std::cin.fail() && response != 'Y' && response != 'y' && response != 'N' && response != 'n')
        {
            std::cout << "Y or N plz." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        else
        {
            valid = true;
        }
    } while (!valid);

    if (response == 'y' || response == 'Y')
    {
        yesNo = true;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
        yesNo = false;
    }

    return yesNo;
}

void restart (char* move, bool& done, int& guesses, int rowLength, int colLength, int& count)
/* Takes in move array, boolean done variable, number of guesses, and number of rows/columns and resets the array and
 * variables for a new game. */
{
    done = false;
    guesses = 0;
    count = 0;

    for (int i = 0; i < rowLength; i++)
    {
        for (int j = 0; j < colLength; j++)
        {
            *(move + getIndex(i, j, colLength)) = SPACE;
        }
    }
}
