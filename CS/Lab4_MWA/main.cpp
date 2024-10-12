/* Lab #4: Memory Game
 * Name: Mason Antram
 * Date: 2/22/2024
 * Version: 1.0
 * IDE: CLion
 *Description: This program runs a game of memory
 *
 * References:
 * - Seed for shuffle function https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
 */

#include <iostream>
#include <exception>
#include "header.hpp"

int main()
{
    int mode, rowLength, colLength, count = 0, row1 = 0, col1 = 0, row2 = 0, col2 = 0, guesses = 1;
    bool done = false, playing = true, match;


    do
    {
        displayInstructions ();
        difficulty(&mode, &rowLength, &colLength);

        char move[rowLength][colLength];
        char *board = createBoard(mode);

        do
        {

            std::cout << "Guess #: " << guesses << '\n';

            showBoard(board, rowLength, colLength);

            getMove(rowLength, colLength, board, *move, row1, col1);

            showBoard(board, rowLength, colLength, *move, row1, col1);

            getMove(rowLength, colLength, board, *move, row1, col1, row2, col2);

            showBoard(board, rowLength, colLength, *move, row1, col1, row2, col2);

            match = checkMatch(board, colLength, row1, col1, row2, col2);

            if (match)
            {
                updateBoard(board, colLength, row1, col1, row2, col2, count);
                checkDone(board, rowLength, colLength, done, count);
            }

            if (!done)
            {
                guesses++;
                move [row1][col1] = SPACE;
                move [row2][col2] = SPACE;
            }

        } while (!done);

        std::cout << "You won in " << guesses << " guesses!" << '\n';
        playing = yesOrNo ("Play again?");

        if (playing)
        {
            restart (*move, done, guesses, rowLength, colLength, count);
        }

        delete[] board;

    } while (playing);

    return 0;
}