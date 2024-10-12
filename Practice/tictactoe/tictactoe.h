#ifndef TICTACTOE_TICTACTOE_H
#define TICTACTOE_TICTACTOE_H

void runGame();
char playerMarkerOne ();
char playerMarkerTwo ();
int getRow();
int getColumn();
bool winCondition (int player, int row, int column, char move);
void playerSwap(int &player);

#endif //TICTACTOE_TICTACTOE_H
