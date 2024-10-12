//
// Created by mason on 11/19/2023.
//

#include "NIM_MWAtest.h"

#include<iostream>
#include<limits>

using namespace std;


void showInstructions() {
    cout << "                   Welcome to NIM. This is a game for two players. " << endl;
    cout << "                     We will start with a pile of eleven sticks. " << endl;
    cout << "Each player will take turns taking their choice of one, two, or three sticks from the pile." << endl;
    cout << "   The objective of the game is to be the player to take the last stick from the pile." << endl;
    cout << "                                     Good luck!" << endl;
}

int showBoard(int numSticks) {
    cout << "Number of sticks in pile: " << numSticks << endl;
    return numSticks;
}

int getMove(int numSticks) {
    bool valid = false;
    int choice;
    do {
        cout << "Take 1-3 sticks:" << endl;
        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 3)
        {
            cout << "Invalid move." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');

        } else if (choice > numSticks) {
            cout << "You can not take more sticks than are left in the pile." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        } else (valid = true);
    } while (!valid);

    return choice;
}

bool playAgain() {
    char input;
    bool play = false;
    bool valid = false;
    do {
        cout << "Play again Y/N?" << endl;
        cin >> input;
        if (cin.fail() || input != 'y' && input != 'Y' && input != 'n' && input != 'N') {
            cout << "Invalid move" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else valid = true;
    } while (!valid);

    if (input == 'y' || input == 'Y')
        play = true;
    if (input == 'n' || input == 'N')
        play = false;

    return play;
}
