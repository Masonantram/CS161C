// Created by mason on 1/8/2024.

#ifndef TICTACTOE_MWA_HEADER_HPP
#define TICTACTOE_MWA_HEADER_HPP

void displayInstructions ();
bool yesNo();
char marker (int player, bool computer, char markerOne);
void initBoard(char board[], int size);
void showBoard (const char board[]);
int getMove(const char[], int player, int min, int max, bool computer);
bool checkWin (const char board[], char markerOne, char markerTwo);
bool checkTie (const char board[], char markerOne, char markerTwo);
void playerSwap (int &player);


#endif //TICTACTOE_MWA_HEADER_HPP
