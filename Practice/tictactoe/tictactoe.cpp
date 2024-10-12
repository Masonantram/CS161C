#include <iostream>
#include "tictactoe.h"


void instructions ()
{
    std::cout << "Welcome to Tic-Tac-Toe! This is a game for two players." << '\n' ;
    std::cout << "Each player will take turns placing a marker on the board." << '\n' ;
    std::cout << "First person to get three in a row wins!" << '\n' ;
}

void runGame()
{
    static char board[3][3]{};
    static int player = 1, winCounterOne = 0, winCounterTwo = 0;
    char move;
    bool valid = false, win;
    int row, column;

    std::cout << "Player one wins: " << winCounterOne << '\n';
    std::cout << "Player two wins: " << winCounterTwo << '\n';

    char markerOne = playerMarkerOne();
    char markerTwo = playerMarkerTwo();

    do //displays board after each player's turn
    {
    std::cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " |" << '\n';
    std::cout <<  "--------------" << '\n';
    std::cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " |" << '\n';
    std::cout << "--------------" << '\n';
    std::cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " |" << '\n';

        (player == 1) ? move = markerOne : move = markerTwo; // assigns the right marker to the right player's move

    do
    {
        std::cout << "Player " << player << '\n';
        row = getRow();
        column = getColumn();

        if (board[row][column] == markerOne || board[row][column] == markerTwo) //prevents a player from overwriting a previous move
        {
            std::cout << "This space is already taken. Try again." << '\n';
            valid = false;
        } else valid = true;

    }while (!valid);

    board[row][column] = move; //puts move on board

    win = winCondition(player, row, column, move); //checks for three in a row

    if (!win) playerSwap(player); //switches players if no winner

    } while (!win);

    (player == 1)? winCounterOne += 1: winCounterTwo += 1; //runs the win counter for repeated plays


    std::cout << "The winner is player " << player << "!" << '\n';
}

char playerMarkerOne ()
{
    char marker;
    bool valid;

    do
    {
        std::cout << "Player one, please choose your marker (one character)" << '\n';
        std::cin >> marker;
        if (std::cin.fail())
        {
            std::cout << "Please choose one character" << '\n';
        } else valid = true;
    } while (!valid);
    return marker;
}


char playerMarkerTwo ()
{
    char marker;
    bool valid;

    do
    {
        std::cout << "Player two, please choose your marker (one character)" << '\n';
        std::cin >> marker;
        if (std::cin.fail())
        {
            std::cout << "Please choose one character" << '\n';
        } else valid = true;
    } while (!valid);
    return marker;
}

int getRow ()
{
    int row ;
    bool valid = false;

    do
    {
        std::cout << "Please enter the row you wish to place your marker" << '\n';
        std::cin >> row;
        row -= 1; // to align with row 0, 1, 2

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please enter a valid number." << '\n';
        }

        if (row > 2 || row < 0)
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please choose a row between 1 and 3" << '\n';
        }

        if (row >= 0 && row <= 2) valid = true;

    } while (!valid);

    valid = false;

    return row;
}

int getColumn()
{
    int column;
    bool valid = false;

    do
    {
        std::cout << "Enter the column that you wish to place your marker" << '\n';
        std::cin >> column;
        column -= 1; //to align with column 0, 1, 2

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please enter a valid number." << '\n';
        }

        if (column > 2 || column < 0)
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please choose a column between 1 and 3";
        }

        if (column >= 0 && column <= 2) valid = true;

    } while (!valid);

    return column;
}


bool winCondition (int player, int row, int column, char move)
{
    static char board[3][3]; //made a shadow board to mimic the visible board and check for a win
    bool win = false;
    char moveOne = 1, moveTwo = 1;

    if (player ==1) moveOne = move;
    if (player == 2) moveTwo = move;

    board[row][column] = move;


    if (board[0][0] == moveOne && board [0][1] == moveOne && board [0][2] == moveOne) win = true;
    if (board[1][0] == moveOne && board [1][1] == moveOne && board [1][2] == moveOne) win = true;
    if (board[2][0] == moveOne && board [2][1] == moveOne && board [2][2] == moveOne) win = true;
    if (board[0][0] == moveOne && board [1][0] == moveOne && board [2][0] == moveOne) win = true;
    if (board[0][1] == moveOne && board [1][1] == moveOne && board [2][2] == moveOne) win = true;
    if (board[2][0] == moveOne && board [2][1] == moveOne && board [2][2] == moveOne) win = true;
    if (board[0][0] == moveOne && board [1][1] == moveOne && board [2][2] == moveOne) win = true;
    if (board[2][0] == moveOne && board [1][1] == moveOne && board [0][2] == moveOne) win = true;

    if (board[0][0] == moveTwo && board [0][1] == moveTwo && board [0][2] == moveTwo) win = true;
    if (board[1][0] == moveTwo && board [1][1] == moveTwo && board [1][2] == moveTwo) win = true;
    if (board[2][0] == moveTwo && board [2][1] == moveTwo && board [2][2] == moveTwo) win = true;
    if (board[0][0] == moveTwo && board [1][0] == moveTwo && board [2][0] == moveTwo) win = true;
    if (board[0][1] == moveTwo && board [1][1] == moveTwo && board [2][2] == moveTwo) win = true;
    if (board[2][0] == moveTwo && board [2][1] == moveTwo && board [2][2] == moveTwo) win = true;
    if (board[0][0] == moveTwo && board [1][1] == moveTwo && board [2][2] == moveTwo) win = true;
    if (board[2][0] == moveTwo && board [1][1] == moveTwo && board [0][2] == moveTwo) win = true;

    // [0,0] [0.1] [0,2]
    // [1,0] [1,1] [1,2]
    // [2,0] [2,1] [2,2]

    return win;
}


void playerSwap(int &player)
{
    (player == 1)? player = 2: player = 1;
}


bool playAgain()
{
    char again;
    bool play, valid;

    do
    {
        std::cout << "Play again Y/N?" << '\n';
        std::cin >> again;
        if (std::cin.fail())
        {
            std::cout << "Y or N plz" << '\n';
        } else valid = true;
    } while (!valid);

    (again == 'y' || again == 'Y')? play = true : play = false; //really, if not y, then game over

    return play;
}