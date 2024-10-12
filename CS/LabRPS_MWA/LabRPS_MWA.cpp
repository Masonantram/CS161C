/*
Rock Paper Scissors
Mason Antram
Date: 11/18/2023
Version 1.0
Description: This program runs a game of rock paper scissors against a computer opponent.
*/

#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

void displayInstructions();
int getMove();
int getCompMove();
void getWinner();
void playAgain();

const string RPS[5]{"rock", "paper", "scissors"};// I am sure that I could more effectively use the array in the future.
bool play = true;

int main() {

    do {
        displayInstructions();
        getWinner();
        playAgain();
    } while (play);
}

void displayInstructions() { // displays the rules of the game
    cout << "             Welcome to Rock, Paper, Scissors." << endl;
    cout << "    In this game, you will be playing against the computer." << endl;
    cout << "When prompted, make your choice of either rock, paper or scissors." << endl;
    cout << "Rock smashes scissors, scissors cut paper, and paper covers rock." << endl;
    cout << "                       Good luck!" << endl;
}

int getMove() { // collects input from the user
    static int userMove;
    char input;
    bool valid = false;

    do
    {
        cout << "Please choose rock, paper, or scissors" << endl;
        cin >> input;
       if ( cin.fail() || input != 'r' && input != 'p' && input != 's' && input != 'R' && input != 'P' && input != 'S')
       {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid move" << endl;
        } else (valid = true);

    } while (!valid);

    if (input == 'r' || input == 'R')
    {
        userMove = 0;
    }
    if (input == 'p' || input == 'P')
    {
        userMove = 1;
    }
    if (input == 's' || input == 'S')
    {
        userMove = 2;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return userMove;
}

int getCompMove() { // makes a randomly-generated move for the computer
    int compMove = (rand()) % 3;
    return compMove;
}

void getWinner() { // compares user/computer moves and declares a winner
    int playerValue, compValue;

    playerValue = getMove();
    compValue = getCompMove();

        cout << "You chose " << RPS[playerValue] << " and the computer chose " << RPS[compValue] << "." << endl;
        if ((playerValue == 0 && compValue == 2) || (playerValue == 1 && compValue == 0)
        || (playerValue == 2 && compValue == 1 )){
            cout << "You win!" << endl;
        } else if (playerValue == compValue){
            cout << "It's a tie!" << endl;
        } else cout << "You lose!" << endl;

        play = false;
}

void playAgain() { // Asks user if they want to play again. Loops back to beginning for yes, and terminates for no.
    char input;
    bool valid = false;

    do
    {
        cout << "Play again Y/N?" << endl;
        cin >> input;

        if (cin.fail() || input != 'y' && input != 'Y' && input != 'n' && input != 'N')
        {
            cout << "Invalid choice." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else (valid = true);

    } while (!valid);

    if (input == 'y' || input == 'Y')
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        play = true;
    }

}
