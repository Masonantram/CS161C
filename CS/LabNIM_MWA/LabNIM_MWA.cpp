/*
Lab 5, NIM
Mason Antram
Date: 10/30/2023
Version 1.0
Description: This program runs the two-player game NIM.

*/


#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    char ANSWER;

    do { // main phase of the game
        int STICKS_CURRENT = 11, PLAYER1, PLAYER2, STICKS = 1, PLAYER_CURRENT = 1;
        bool VALID = true;

        cout << "                   Welcome to NIM. This is a game for two players. " << endl;
        cout << "    We will start with a pile of eleven sticks, seen here.  --> | | | | | | | | | | | " << endl;
        cout << "Each player will take turns taking their choice of one, two, or three sticks from the pile." << endl;
        cout << "   The objective of the game is to be the player to take the last stick from the pile." << endl;
        cout << "                                     Good luck!" << endl;

        do {
            // after some head scratching and coming to this solution to represent integers as "sticks", I realized
            // that I could have probably used a for statement, like we did in the second data validation exercise
            // to make a rectangle.
            switch (STICKS_CURRENT) {
                case 1:
                    cout << setw(150) << "Pile: | " << endl;
                    break;
                case 2:
                    cout << setw(150) << "Pile: | | " << endl;
                    break;
                case 3:
                    cout << setw(150) << "Pile: | | | " << endl;
                    break;
                case 4:
                    cout << setw(150) << "Pile: | | | | " << endl;
                    break;
                case 5:
                    cout << setw(150) << "Pile: | | | | | " << endl;
                    break;
                case 6:
                    cout << setw(150) << "Pile: | | | | | | " << endl;
                    break;
                case 7:
                    cout << setw(150) << "Pile: | | | | | | | " << endl;
                    break;
                case 8:
                    cout << setw(150) << "Pile: | | | | | | | | " << endl;
                    break;
                case 9:
                    cout << setw(150) << "Pile: | | | | | | | | | " << endl;
                    break;
                case 10:
                    cout << setw(150) << "Pile: | | | | | | | | | | " << endl;
                    break;
                default:
                    cout << setw(150) << "Pile: | | | | | | | | | | | " << endl;
                    break;

            }

            cout << "Player " << PLAYER_CURRENT << ", how many sticks would you like to remove?" << endl;
            cin >> STICKS;

            while (cin.fail() || STICKS < 1 || STICKS > 3 ) { // this keeps the player from entering anything besides 1,2,or 3.
                cout << "Please choose a number of sticks between 1 and 3." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin >> STICKS;
            }

            while (STICKS > STICKS_CURRENT) { // this will stop a user from taking the pile negative
                cout << "You can't take more sticks than what is in the pile." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin >> STICKS;
            }

             STICKS_CURRENT -= STICKS; // initiates a running total for the remaining sticks

           if (PLAYER_CURRENT == 1 && STICKS_CURRENT > 0) { // switches players if there are still sticks in the pile
               PLAYER_CURRENT = 2;
           }
           else if (PLAYER_CURRENT == 2 && STICKS_CURRENT > 0) {
               PLAYER_CURRENT = 1;
           }

        } while (STICKS_CURRENT > 0);

        cout << "                Game over!" << endl;
        cout << "         The winner is Player " << PLAYER_CURRENT << "!" << endl;
        cout << " " << endl;
        cout << "            New game (Y/N)?" << endl;
        cin >> ANSWER;
        ANSWER = tolower(ANSWER);

    } while (ANSWER == 'y');
        return 0;
    }
// I enjoyed taking some time to make the program presentable and user-friendly.




/*
 *
 * int max sticks (11), current sticks, player input 1 and 2
 * big loop
 * (
 * cout welcome to NIM, rules
 * small loop
 * (
 * prompt player 1 for an integer between 1 and 3
 *      if not integer between 1 and 3, display error and clear buffer
 * if valid, check input against current sticks and subtract input value
 * if new current sticks value is > 0 , start over and prompt player 2
 * loop continues between player 1/2 until sticks <= 0
 * If current sticks <= 0 , cout winner and proceed to new game prompt
 * )
 * Ask if they want to play a new game
 *      If yes, start big loop over
 *      If no, terminate
 *      )

 */