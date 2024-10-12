//
// Created by mason on 1/28/2024.
//

#ifndef DUNGEONCRAWL_MWA_HEADER_HPP
#define DUNGEONCRAWL_MWA_HEADER_HPP

const int MAX_SIZE = 20;
const char ADVENTURER = 'A', EMPTY = '.', EXIT = 'X', HAZARD = 'H', MONSTER = 'M', TREASURE = 'T';

int randomNumGen (int max);
void displayInstructions();
void createDungeon (char map[][MAX_SIZE], char location[][MAX_SIZE], int hazardNo, int treasureNo, int& currY, int& currX,
                    int& monY1, int& monY2, int& monX1, int& monX2, int& newY, int& newX, int& player, bool& playing,
                    bool& isTreasure, bool& isHazard, bool& isExit, bool& isMonster);
void displayDungeon (const char map[][MAX_SIZE]);
void getMove (int player, int currY, int currX, int& newY, int& newX);
void monsterMove (char& move);
bool checkMove (const char map[][MAX_SIZE], char item, int newY, int newX);
void updateDungeon (char map[][MAX_SIZE], int player, int& currY, int& currX, int newY, int newX);
void playerSwap (int& player);
bool playAgain();


#endif //DUNGEONCRAWL_MWA_HEADER_HPP
