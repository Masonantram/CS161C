/*
 * Lab: Tic-tac-toe
 * Student name: Mason Antram
 * IDE: Clion
 * Date: 1/19/2024
 * Version: 1.1
 * Description: Runs the two-player game Tic-tac-toe

References used in program, outside the curriculum:
random number seeding, generation
https://www.simplilearn.com/tutorials/cpp-tutorial/random-number-generator-in-cpp#rand_and_srand_functions_in_c
*/

#include <iostream>
#include <cstdlib>
#include "header.hpp"

int main()
{
    const int SIZE = 9, MIN = 1, MAX = 9;
    static int winCounterOne = 0, winCounterTwo = 0;
    char board[SIZE]{}, markerOne, markerTwo;
    bool computer, play, done, win, tie;
    int player = 1, move;

    srand((unsigned) time (nullptr));

    do
    { //displays instructions, collects player marker choice, initiates/clears board
        displayInstructions();

        std::cout << "Player one wins: " << winCounterOne << '\n';
        std::cout << "Player two wins: " << winCounterTwo << '\n';

        std::cout << "Use computer opponent?" << '\n';
        computer = yesNo ();

        markerOne = marker(1, computer, ' ');
        markerTwo = marker(2, computer, markerOne);

        initBoard(board, SIZE);

        do
        { // starts game
            showBoard(board);

            move = getMove(board, player, MIN, MAX, computer);

            (player == 1)? board[move] = markerOne: board[move] = markerTwo;

           win = checkWin(board, markerOne, markerTwo);
           tie = checkTie(board, markerOne, markerTwo);

            done = (win || tie);

            if (!win && !tie)
            {
                playerSwap(player);
            }

        } while (!done);

        if (tie && !win)
        {
            std::cout << "It's a tie!" << '\n';
        }

        if (win)
        {
            std::cout << "The winner is " << player << "!" << '\n';
        }

        if (!tie)
        {
            (player == 1)? winCounterOne += 1: winCounterTwo += 1;  //runs the win counter for repeated playing
        }

        std::cout << "Play again?" << '\n';
        play = yesNo();

   } while (play);

    return 0;
}
