//
// Created by mason on 1/28/2024.
//
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include "header.hpp"


int randomNumGen (int max)
//generates a pseudorandom number for use in placing objects on the map. Takes in a max value, returns that random value.
{
    int random = rand() %(max);
    return random;
}

void displayInstructions ()
// displays full instructions once, and truncated rules with repeated plays. No parameters or return value.
{
    static int counter = 0;

    if (counter == 0)
    {
        std::cout << "Welcome to your dungeon crawler!" << '\n';
        std::cout << "You are an adventurer (marked ""A"") on a quest to the exit (marked ""X"")." << '\n';
        std::cout << "Avoid hazards (marked ""H"") and monsters (marked ""M"")." << '\n';
        std:: cout << "Find treasure (marked ""T"") for a fun surprise." << '\n';
        std::cout << "Use W/A/S/D to move. Good luck!" << '\n';
    }
    else
    {
        std::cout << "Remember, get to the exit, avoid the hazards, don't get eaten." << '\n';
    }

    counter++;
}

void createDungeon (char map[][MAX_SIZE], char location[][MAX_SIZE], int hazardNo, int treasureNo, int& currY, int& currX,
                    int& monY1, int& monY2, int& monX1, int& monX2, int& newY, int& newX, int& player, bool& playing,
                    bool& isTreasure, bool& isHazard, bool& isExit, bool& isMonster)
 /* clears map and adventurer location arrays, as well as resets win/loss variables and adventurer/monster coordinates.
  * Takes in all variables except for the number of treasures and hazards. No explicit return value. */
{
    bool placed = false;
    player = 1;
    playing = true;
    isTreasure = false;
    isHazard = false;
    isExit = false;
    isMonster = false;

    for (int i = 0; i < MAX_SIZE; i++) // clearing map
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            map[i][j] = EMPTY;
        }
    }

    for (int i = 0; i < MAX_SIZE; i++) // clearing location array
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
           location[i][j] = EMPTY;
        }
    }

    do
    {   // randomly places hazards
        currY = randomNumGen((MAX_SIZE - 1));
        currX = randomNumGen((MAX_SIZE - 1));

        if (map[currY][currX] == EMPTY)
        {
            map[currY][currX] = HAZARD;
            hazardNo--;
        }

    } while (hazardNo > 0);

    do
    {  // randomly places treasures
        currY = randomNumGen((MAX_SIZE - 1));
        currX = randomNumGen((MAX_SIZE - 1));

        if (map[currY][currX] == EMPTY)
        {
            map[currY][currX] = TREASURE;
            treasureNo--;
        }

    } while (treasureNo > 0);

    do
    { // places exit
        currY = randomNumGen((MAX_SIZE - 1));
        currX = randomNumGen((MAX_SIZE - 1));

        if (map[currY][currX] == EMPTY)
        {
            map[currY][currX] = EXIT;
            placed = true;
        }
    } while (!placed);

    placed = false;

    do // places one monster
    {
        monY1 = randomNumGen((MAX_SIZE - 1));
        monX1 = randomNumGen((MAX_SIZE - 1));

        if (map[monY1][monX1] == EMPTY)
        {
            map[monY1][monX1] = MONSTER;

            placed = true;

        }
    } while (!placed);

    placed = false;

    do //places second monster
    {
        monY2 = randomNumGen((MAX_SIZE - 1));
        monX2 = randomNumGen((MAX_SIZE - 1));

        if (map[monY2][monX2] == EMPTY)
        {
            map[monY2][monX2] = MONSTER;

            placed = true;
        }
    } while (!placed);

    placed = false;

    do // places adventurer on a remaining empty spot
    {
        currY = randomNumGen((MAX_SIZE - 1));
        currX = randomNumGen((MAX_SIZE - 1));

        if (map[currY][currX] == EMPTY)
        {
            map[currY][currX] = ADVENTURER;
            location[currY][currX] = ADVENTURER;
            newY = 0;
            newX = 0;

            placed = true;
        }
    } while (!placed);

}

void displayDungeon (const char map[][MAX_SIZE])
// displays dungeon with locations of hazards, treasure, exit, and adventurer. Takes in map array, no return value.
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            std::cout << std::setw(3) << map[i][j];
        }
        std::cout << '\n';
    }
}


void getMove (int player, int currY, int currX, int& newY, int& newX)
/* Gets move from the console for the adventurer, and using the monsterMove helper function, generates a pseudorandom move
 * for monsters. Takes in the player number and current coordinates by copy and new coordinates by reference. No return value.
 * */

{
   char move;
   bool valid = false;

        newY = currY;
        newX = currX;

        do
        {
            if (player != 1)
            {
                monsterMove(move);
                valid = true;
            }
            else
            {
                do
                {
                    std::cout << "Please make a move (W/A/S/D)" << '\n';
                    std::cin >> move;

                    if (std::cin.fail() || // validates for W/A/S/D
                        move != 'W' && move != 'w' && move != 'A' && move != 'a' && move != 'S' && move != 's'
                        && move != 'D' && move != 'd') {
                        std::cout << "Choose W, A, S, or D." << '\n';
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } else valid = true;

                } while (!valid);
            }

                valid = false;

                if (move == 'W' || move == 'w')
                {
                    if ((currY - 1) < 0 && player == 1)// checks for out of bounds and changes new coordinates
                    {
                        std::cout << "Out of bounds." << '\n';
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else if ((currY - 1) < 0 && player != 1)
                    {
                        valid = false;
                    }
                    else
                    {
                        newY = currY - 1;
                        valid = true;
                    }
                }

                if (move == 'S' || move == 's')
                {
                    if ((currY + 1) > (MAX_SIZE - 1) && player == 1)
                    {
                        std::cout << "Out of bounds." << '\n';
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else if ((currY + 1) > (MAX_SIZE - 1) && player != 1)
                    {
                        valid = false;
                    }
                    else
                    {
                        newY = currY + 1;
                        valid = true;
                    }
                }

                if (move == 'A' || move == 'a')
                {
                    if ((currX - 1) < 0 && player == 1)
                    {
                        std::cout << "Out of bounds." << '\n';
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else if ((currX - 1) < 0 && player != 1)
                    {
                        valid = false;
                    }
                    else
                    {
                        newX = currX - 1;
                        valid = true;
                    }
                }

                if (move == 'D' || move == 'd')
                {
                    if ((currX + 1) > (MAX_SIZE - 1) && player == 1)
                    {
                        std::cout << "Out of bounds." << '\n';
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    }
                    else if ((currX + 1) > (MAX_SIZE - 1) && player != 1)
                    {
                        valid = false;
                    }
                    else
                    {
                        newX = currX + 1;
                        valid = true;
                    }
                }

        } while (!valid);
    }

void monsterMove (char& move)
{
    int rando;

    rando = randomNumGen(3);

    switch (rando)
    {
        case 0:
        {
            move = 'W';
        }
            break;
        case 1:
        {
            move = 'S';
        }
            break;
        case 2:
        {
            move = 'A';

        }
            break;
        case 3:
        {
            move = 'D';
        }
            break;
        default:
        {
            move = 'W';
            break;
        }
    }

}

 bool checkMove (const char map[][MAX_SIZE], char item, int newY, int newX)
 //Checks proposed move against the map for hazards, exit, treasure, and monsters. Takes in map array, the type of item
 // being checked, and the proposed new x/y coordinates. Returns true/false for found.
 {
    bool found = false;

    if (map[newY][newX] == item)
    {
        found = true;
    }

return found;
}

void updateDungeon (char map[][MAX_SIZE], int player, int& currY, int& currX, int newY, int newX)
/*If the move is valid, updates map and current coordinates with the new ones, and clears the old spot.
 * Takes in the map array, player,and old/new x/y coordinates. No return value. */
{


    if (player == 1)
    {
        map[currY][currX] = EMPTY;
        map[newY][newX] = ADVENTURER;
    }
    else if (map[newY][newX] == EMPTY)
    {
        map[currY][currX] = EMPTY;
        map[newY][newX] = MONSTER;
    }

    currY = newY;
    currX = newX;

}


void playerSwap (int& player)
//switches players. Takes in player number by reference, no return value.
{
    if (player == 1)
    {
        player = 2;
    }
    else if (player == 2)
    {
        player = 3;
    }
    else if (player == 3)
    {
        player = 1;
    }
}

bool playAgain()
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

