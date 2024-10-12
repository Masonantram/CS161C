void instructions();
void runGame();
char playerMarkerOne ();
char playerMarkerTwo ();
int getRow();
int getColumn();
bool winCondition (int player, int row, int column, char move);
void playerSwap(int &player);
bool playAgain();



int main()
{
    bool play;

    instructions();

    do
    {
        runGame();
        play = playAgain();
   } while (play);

    return 0;
}

// to add:
// is there a cleaner way to display the board?
// allow players to have the same symbol? the chaos/memorization element is intriguing.




/* Board:
 * [0,0] [0.1] [0,2]
 * [1,0] [1,1] [1,2]
 * [2,0] [2,1] [2,2]
 * */
