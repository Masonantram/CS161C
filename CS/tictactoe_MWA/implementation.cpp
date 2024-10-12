//Created by Mason Antram on 1/8/2024.

#include "header.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>

void displayInstructions ()
// displays full instructions once, and truncated rules with repeated plays. No parameters or return value.
{
    static int counter = 0;

    if (counter == 0)
    {
        std::cout << "Welcome to Tic-Tac-Toe! This is a game for two players." << '\n';
        std::cout << "Each player will take turns placing a marker on the board:" << '\n';
        std::cout << "|1|2|3|" << '\n';
        std::cout << "|4|5|6|" << '\n';
        std::cout << "|7|8|9|" << '\n';
        std::cout << "First person to get three in a row (horizontally, vertically, or diagonally) wins!" << '\n';
    }
    else
    {
        std::cout << "Remember, three in a row wins!" << '\n';
        std::cout << "Winner starts." << '\n';
    }

   counter++;

}

bool yesNo()
/* Takes user input and validates for Y/y/N/n.
 * No parameters, returns true/false for yes/no. */
{
    char response;
    bool yesNo, valid;

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

    (response == 'y' || response == 'Y') ? yesNo = true : yesNo = false;

    return yesNo;
}

char marker (int player, bool computer, char markerOne)
/* allows a player to choose a character to use on the board. Takes in the player number and player one's choice
 * (if applicable), returns the player's choice. */
{
    char marker;
    bool valid = false;

    if (player == 2 && computer)
    {
        bool good = false;

        do
        {
            marker = (rand() % 126) + 1;
            if (marker != markerOne)
            {
                good = true;
            }
        } while (!good);
    }
    else
    {
        do
        {
            std::cout << "Player " << player << ", please choose your marker (one character)." << '\n';
            std::cin >> marker;
            if (std::cin.fail())
            {
                std::cout << "Please choose one character." << '\n';
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }

            if (marker == markerOne)
            {
                std::cout << "Player one claimed this marker. Try again." << '\n';
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }

            if (std::cin.good() && marker != markerOne)
            {
                valid = true;
            }
        } while (!valid);
    }

    return marker;
}

void initBoard (char board[], int size)
// initiates/clears empty board at beginning of game. Takes in board array from main, no return value.
{
    for (int i = 0; i < size; i++) // clears board for new game
    {
        board[i] = 0;
    }
}

void showBoard (const char board[])
//shows the updated board as the game goes on. Takes in the board array from main, no return value.
{
    std::cout << board[0] << " | " << board[1] << " | " << board[2] << '\n';
    std::cout <<  "----------" << '\n';
    std::cout << board[3] << " | " << board[4] << " | " << board[5] << '\n';
    std::cout << "----------" << '\n';
    std::cout << board[6] << " | " << board[7] << " | " << board[8] << '\n';
}

int getMove (const char board[],int player, int min, int max, bool computer)
/* requests move from player and validates input for a number, in range, in an available spot.
Takes in the board array, the current player, board range, and if there is a computer opponent.
 Returns the corresponding move. */
{
    int move;
    bool valid = false;

    {
        do
        {
            std::cout << "Player " << player << ", Please enter the space (1-9) you wish to place your marker." << '\n';

            if (player == 1 || (player == 2 && !computer))
            {
                std::cin >> move;
            }

            if (player == 2 && computer)
            {
                move = 1 + (rand() % 9);
            }

            if (std::cin.fail())
            {
                std::cout << "Please enter a valid number." << '\n';
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }

            if (move < min || move > max)
            {
                std::cout << "Please choose a space between 1 and 9." << '\n';
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }

            if (board[move - 1])
            {
                std::cout << "This spot is taken, try again." << '\n';
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }

            if ((move >= min && move <= max) && !board[move - 1])
            {
                valid = true; //if move is between 1-9 & space is empty, yay
            }

        } while (!valid);
    }

    move -= 1; // to align with space 0, 1, 2...

    return move;
}

bool checkWin (const char board[], char markerOne, char markerTwo)
/* Checks board for three of the same player's marker in a row. Takes in the board and each player's marker,
 * returns true/false. */
//I feel like there is a better way of doing this using bitwise indicators perhaps?
{
    bool win = false;

    if (board[0] == markerOne && board[1] == markerOne && board[2] == markerOne) win = true; // horizontal win
    if (board[3] == markerOne && board[4] == markerOne && board[5] == markerOne) win = true;
    if (board[6] == markerOne && board[7] == markerOne && board[8] == markerOne) win = true;


    if (board[0] == markerOne && board[3] == markerOne && board[6] == markerOne) win = true; // vertical win
    if (board[1] == markerOne && board[4] == markerOne && board[7] == markerOne) win = true;
    if (board[2] == markerOne && board[5] == markerOne && board[8] == markerOne) win = true;

    if (board[0] == markerOne && board[4] == markerOne && board[8] == markerOne) win = true; // diagonal win
    if (board[6] == markerOne && board[4] == markerOne && board[2] == markerOne) win = true;

    if (board[0] == markerTwo && board[1] == markerTwo && board[2] == markerTwo) win = true;
    if (board[3] == markerTwo && board[4] == markerTwo && board[5] == markerTwo) win = true;
    if (board[6] == markerTwo && board[7] == markerTwo && board[8] == markerTwo) win = true;

    if (board[0] == markerTwo && board[3] == markerTwo && board[6] == markerTwo) win = true;
    if (board[1] == markerTwo && board[4] == markerTwo && board[7] == markerTwo) win = true;
    if (board[2] == markerTwo && board[5] == markerTwo && board[8] == markerTwo) win = true;

    if (board[0] == markerTwo && board[4] == markerTwo && board[8] == markerTwo) win = true;
    if (board[6] == markerTwo && board[4] == markerTwo && board[2] == markerTwo) win = true;

    return win;
}

bool checkTie (const char board[], char markerOne, char markerTwo)
//Checks to see if all spots on the board are taken. Takes in board and each player's marker, returns true/false.
{
    bool tie = false;

    if (board[0] && board[1] && board[2] && board[3] && board[4] && board[5] && board[6] && board[7] && board[8])
    {
        tie = true;
    }

    return tie;
}

void playerSwap(int &player)
//changes players if win condition is not met. Takes in current player, no return value.
{
    (player == 1)? player = 2: player = 1;
}

