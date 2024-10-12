#include <iostream>

//notes:
//win condition triggers at wrong times

//need to clear board on new game
//(I built but did not test the boardclear function. it is set on the shadow board but not on showboard)
//plays can be made on spaces outside of the board
//can the board code and design be cleaned up/consolidated?
//can I use pointers to use one board? I feel like if I can set up the board as a reference and use pointers to access it, I could use and clear one board.
// if i try to pass the board to a function as board and not board[][] will it work?

char playerMarkerOne ()
{
    char marker;
    bool valid;

    do
    {
        std::cout << "Player 1, please choose your marker (one character)" << '\n';
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
        std::cout << "Player 2, please choose your marker (one character)" << '\n';
        std::cin >> marker;
        if (std::cin.fail())
        {
            std::cout << "Please choose one character" << '\n';
        } else valid = true;
    } while (!valid);
    return marker;
}

void clearBoard (int &row, int &column, char &move)
{
    char board[6][7];

    row = 0;
    column = 0;
    move = ' ';

    for (int i = row; i < 5; i++)
    {
        for (int j = column; j < 6; j++)
        {
            board[row][column] = move;
        }
    }

}

void showBoard (int row, int column, char move)
{
    static char board [6][7];

    board[row][column] = move;


    std::cout << "| " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " | " << board[0][3] << " | " <<
              board[0][4] << " | " << board[0][5] << " | " << board[0][6] << " | " << '\n';

    std::cout << "-----------------------------" << '\n';

    std::cout << "| " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " | " << board[1][3] << " | " <<
              board[1][4] << " | " << board[1][5] << " | " << board[1][6] << " | " << '\n';

    std::cout << "-----------------------------" << '\n';

    std::cout << "| " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " | " << board[2][3] << " | " <<
              board[2][4] << " | " << board[2][5] << " | " << board[2][6] << " | " << '\n';

    std::cout << "-----------------------------" << '\n';

    std::cout << "| " << board[3][0] << " | " << board[3][1] << " | " << board[3][2] << " | " << board[3][3] << " | " <<
              board[3][4] << " | " << board[3][5] << " | " << board[3][6] << " | " << '\n';

    std::cout << "-----------------------------" << '\n';

    std::cout << "| " << board[4][0] << " | " << board[4][1] << " | " << board[4][2] << " | " << board[4][3] << " | " <<
              board[4][4] << " | " << board[4][5] << " | " << board[4][6] << " | " << '\n';

    std::cout << "-----------------------------" << '\n';

    std::cout << "| " << board[5][0] << " | " << board[5][1] << " | " << board[5][2] << " | " << board[5][3] << " | " <<
              board[5][4] << " | " << board[5][5] << " | " << board[5][6] << " | " << '\n';

    std::cout << "-----------------------------" << '\n';

    std::cout << '\n';


    /* [0,0][0,1][0,2][0,3][0,4][0,5][0,6]
       [1,0][1,1][1,2][1,3][1,4][1,5][1,6]
       [2,0][2,1][2,2][2,3][2,4][2,5][2,6]
       [3,0][3,1][3,2][3,3][3,4][3,5][3,6]
       [4,0][4,1][4,2][4,3][4,4][4,5][4,6]
       [5,0][5,1][5,2][5,3][5,4][5,5][5,6] */

}

int getColumn(int player)
{
    int column;
    bool valid = false;

    do
    {
        std::cout << "Player " << player << ", Enter the column that you wish to place your marker" << '\n';
        std::cin >> column;
        column --; //to align with column 0, 1, 2...

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please enter a valid number." << '\n';
        }

        if (column > 6 || column < 0)
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Please choose a column between 1 and 7";
        }

        if (column >= 0 && column <= 6) valid = true;

    } while (!valid);

    return column;
}

bool winCondition (int player, int row, int column, char move)
{
    static char board[6][7];
    bool win = false;
    char moveOne = 1, moveTwo = 1;

    (player == 1)? moveOne = move: moveTwo = move;


    (player == 1)? board[row][column] = moveOne : board[row][column] = moveTwo;


//these win conditions can probably be cleaned up with for statements

    if (board[row-3][column] == moveOne && board[row-2][column] == moveOne &&
    board[row-1][column] == moveOne && board[row][column] == moveOne)
        win = true;

    if (board[row-2][column]  == moveOne && board[row-1][column] == moveOne &&
    board[row][column] == moveOne && board[row+1][column] == moveOne)
        win = true;

    if (board[row-1][column]  == moveOne && board[row][column]  == moveOne &&
    board[row+1][column]  == moveOne && board[row+2][column]  == moveOne)
        win = true;

    if (board[row][column] == moveOne && board[row+1][column] == moveOne &&
    board[row+2][column] == moveOne && board[row+3][column] == moveOne)
        win = true;

    if (board[row][column-3]  == moveOne && board[row][column-2] == moveOne &&
    board[row][column-1] == moveOne && board[row][column] == moveOne)
        win = true;

    if (board[row][column-2] == moveOne && board[row][column-1] == moveOne &&
    board[row][column] == moveOne && board[row][column+1] == moveOne)
        win = true;

     if (board[row][column-1]  == moveOne && board[row][column] == moveOne &&
     board[row][column+1] == moveOne && board[row][column+2] == moveOne)
        win = true;

    if (board[row][column] == moveOne && board[row][column+1] == moveOne &&
    board[row][column+2] == moveOne && board[row][column+3] == moveOne)
        win = true;

    if (board[row-3][column-3] == moveOne && board[row-2][column-2] == moveOne &&
    board[row-1][column-1] == moveOne && board[row][column] == moveOne)
        win = true;

     if (board[row][column] == moveOne && board[row+1][column+1] == moveOne &&
     board[row+2][column+2] == moveOne && board[row+3][column+3] == moveOne)
        win = true;

    if (board[row-3][column] == moveTwo && board[row-2][column] == moveTwo &&
    board[row-1][column] == moveTwo && board[row][column] == moveTwo)
        win = true;

    if (board[row-2][column]  == moveTwo && board[row-1][column] == moveTwo &&
    board[row][column] == moveTwo && board[row+1][column] == moveTwo)
        win = true;

    if (board[row-1][column]  == moveTwo && board[row][column]  == moveTwo &&
    board[row+1][column]  == moveTwo && board[row+2][column]  == moveTwo)
        win = true;

    if (board[row][column] == moveTwo && board[row+1][column] == moveTwo &&
    board[row+2][column] == moveTwo && board[row+3][column] == moveTwo)
        win = true;

    if (board[row][column-3]  == moveTwo && board[row][column-2] == moveTwo &&
    board[row][column-1] == moveTwo && board[row][column] == moveTwo)
        win = true;

    if (board[row][column-2] == moveTwo && board[row][column-1] == moveTwo &&
    board[row][column] == moveTwo && board[row][column+1] == moveTwo)
        win = true;

    if (board[row][column-1]  == moveTwo && board[row][column] == moveTwo &&
    board[row][column+1] == moveTwo && board[row][column+2] == moveTwo)
        win = true;

    if (board[row][column] == moveTwo && board[row][column+1] == moveTwo &&
    board[row][column+2] == moveTwo && board[row][column+3] == moveTwo)
        win = true;

    if (board[row-3][column-3] == moveTwo && board[row-2][column-2] == moveTwo &&
    board[row-1][column-1] == moveTwo && board[row][column] == moveTwo)
        win = true;

    if (board[row][column] == moveTwo && board[row+1][column+1] == moveTwo &&
    board[row+2][column+2] == moveTwo && board[row+3][column+3] == moveTwo)
        win = true;

    /*   [0,0][0,1][0,2][0,3][0,4][0,5][0,6]
         [1,0][1,1][1,2][1,3][1,4][1,5][1,6]
         [2,0][2,1][2,2][2,3][2,4][2,5][2,6]
         [3,0][3,1][3,2][3,3][3,4][3,5][3,6]
         [4,0][4,1][4,2][4,3][4,4][4,5][4,6]
         [5,0][5,1][5,2][5,3][5,4][5,5][5,6] */

    clearBoard (row, column, move);

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



void runGame()
{
    static char board[6][7];
    static int row[7] {5,5,5,5,5,5, 5};
    static int player = 1;
    bool win = false;
    char move;

    char moveOne = playerMarkerOne(); //players choose their symbol
    char moveTwo = playerMarkerTwo();

    showBoard(0, 0,' ');

   do
   {
     //  std::cout << player << '\n';
        int column = getColumn(player);

       (player == 1)? move = moveOne: move = moveTwo; // assigns appropriate marker to player move

        showBoard(row[column], column, move);

       win = winCondition(player, row[column], column, move);

        row[column] -= 1;

        //std::cout << win << '\n';

       if (!win) playerSwap(player);

   } while (!win);

   if (board[0][0] == (moveOne || moveTwo)  && board[0][1] == (moveOne || moveTwo) && board[0][2] == (moveOne || moveTwo)
   && board[0][3] == (moveOne || moveTwo) && board[0][4] == (moveOne || moveTwo) && board[0][5] == (moveOne || moveTwo)
   && board[0][6] == (moveOne || moveTwo))
   {std::cout << "Stalemate!";}
   else std::cout << "The winner is " << player << "!" << '\n';

}

    /*   [0,0][0,1][0,2][0,3][0,4][0,5][0,6]
         [1,0][1,1][1,2][1,3][1,4][1,5][1,6]
         [2,0][2,1][2,2][2,3][2,4][2,5][2,6]
         [3,0][3,1][3,2][3,3][3,4][3,5][3,6]
         [4,0][4,1][4,2][4,3][4,4][4,5][4,6]
         [5,0][5,1][5,2][5,3][5,4][5,5][5,6] */


int main()
{

    bool playing;

    do
    {
        runGame();
        playing = playAgain();

    } while (playing);


    return 0;
}
