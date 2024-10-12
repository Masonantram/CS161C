/*
 * Lab: Week 3 Dungeon Crawler
 * Student name: Mason Antram
 * IDE: Clion
 * Date: 2/5/2024
 * Version: 1.0
 * Description: Runs a one-player dungeon crawler program
*/


#include <iostream>
#include <ctime>
#include <cstdlib>
#include "header.hpp"


int main()
{
    int hazardNo = 20, treasureNo = 5, player = 1, advY = 0, advX = 0, newY = 0, newX = 0, monX1 = 0,
    monX2 = 0, monY1 = 0, monY2 = 0;
    char map[MAX_SIZE][MAX_SIZE]{}, location[MAX_SIZE][MAX_SIZE]{};
    bool playing = true, newGame = true, isTreasure = false, isHazard = false, isExit = false, isMonster = false;

    srand((unsigned) time (nullptr));

    do {
        displayInstructions();
        createDungeon(map, location, hazardNo, treasureNo, advY, advX, monY1, monY2, monX1, monX2,
                      newY, newX, player, playing, isTreasure, isHazard, isExit, isMonster);

        do
        {

        if (player == 1)
        {
            displayDungeon(map);
            getMove(player, advY, advX, newY, newX);
            isHazard = checkMove(map, HAZARD, newY, newX);
            isTreasure = checkMove(map, TREASURE, newY, newX);
            isExit = checkMove(map, EXIT, newY, newX);
            isMonster = checkMove(map, MONSTER, newY, newX);

            if (isTreasure && player == 1)
            {
                std::cout << "Incoming: one high five" << '\n';
            }

            if ((isHazard || isExit || isMonster) && player == 1)
            {
                playing = false;
            }

            updateDungeon(map, player, advY, advX, newY, newX);
        }

        if (player == 2)
            {
            getMove(player, monY1, monX1, newY, newX);

                isHazard = checkMove(map, HAZARD, newY, newX);
                isTreasure = checkMove(map, TREASURE, newY, newX);
                isExit = checkMove(map, EXIT, newY, newX);
                isMonster = checkMove(map, MONSTER, newY, newX);

                if (!isHazard && !isTreasure && !isExit && !isMonster)
                {
                    updateDungeon(map, player, monY1, monX1, newY, newX);
                }
            }


        if (player == 3)
            {
                getMove(player, monY2, monX2, newY, newX);
                isHazard = checkMove(map, HAZARD, newY, newX);
                isTreasure = checkMove(map, TREASURE, newY, newX);
                isExit = checkMove(map, EXIT, newY, newX);
                isMonster = checkMove(map, MONSTER, newY, newX);

                if (!isHazard && !isTreasure && !isExit && !isMonster)
                {
                    updateDungeon(map, player, monY2, monX2, newY, newX);
                }
            }

        if (playing)
        {
            playerSwap(player);
        }

        } while (playing);

//end game scenarios
        if (isHazard)
        {
            std::cout << "It is a stationary object, and you hit it. You lose!" << '\n';
        }

        if (isExit)
        {
            std::cout << "You made it!" << '\n';
        }

        if (isMonster)
        {
            std::cout << "Monster think adventurer yummy nom nom" << '\n';
        }

        std::cout << "Play again?" << '\n';

        newGame = playAgain(); // asks for new game

    } while (newGame);

    return 0;
}
