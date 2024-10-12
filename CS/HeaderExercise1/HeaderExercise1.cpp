/*Create prototypes for the following functions.

showInstructions: no inputs, displays the game instructions (should show complete instructions the first time,
 reduced instructions all future times).

showBoard: inputs current number of sticks, displays the board.

getMove: inputs current number of sticks, returns a valid number of sticks to be removed.
 A valid move is between 1 and 3 and not greater than the current number of sticks.

playAgain: no inputs, returns true for playing again, false otherwise.

Note: Please use the following.
int numSticks */

// answer to exercise 2: void showBoard(int numSticks){cout<<"In showBoard"<<endl;}



#include <iostream>
using namespace std;

void showInstructions();
void showBoard (int numSticks);
int getMove (int numSticks);
bool playAgain();

int currSticks = 10;
bool play = true;
bool run1 = true;
int main() {

    do {
        showInstructions();
        do {
            getMove(0);
        }while (currSticks >0);


        if (currSticks <= 0) {
            cout << "winner" << endl;
        }
        playAgain();

    } while (play);

    return 0;
}

void showInstructions() {

    if (run1){
      cout <<  "instructions1" << endl;
    } else cout << "instructions2" << endl;
}

int getMove( int numSticks){

    bool valid = false;

    do {
        cout << "take 1-3 sticks" << endl;
        cin >> numSticks;
        if (numSticks < 1 || numSticks > 3)
            cout << "invalid move" << endl;
        else valid = true;
    }while (!valid);

showBoard(numSticks);
    return numSticks;
}

void showBoard (int numSticks){
    currSticks -= numSticks;
cout << currSticks << endl;
    }

bool playAgain(){
    char input;
cout << "Play again Y/N" << endl;
cin >> input;
if (input == 'y')
    return play = true;
run1 = false;
if (input == 'n')
    return play = false;
}