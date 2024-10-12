#include <iostream>
#include "NIM_MWAtest.h"

using namespace std;



int main()
{
    const int MAX_STICKS = 11;

    // outer replay game loop

    do {

        // define initial start for game
        int numSticks = MAX_STICKS;
        int player = 1;

        // tell the user how to play the game
        showInstructions();

        // game loop, continues until no sticks left
        do {
            // display the board
            showBoard(numSticks);

            // get a valid move and update the board state
            int the_move = getMove(numSticks);

            numSticks -= the_move;

            // switch player if not done
            if (numSticks != 0 )
            {
                player = (player == 1)?2:1;
            }

        } while (numSticks != 0);

        // game over, show who won
        cout << " player " << player << " won!!\n";

        // do they want to go again?
    } while ( playAgain() );

    return 0;
}

