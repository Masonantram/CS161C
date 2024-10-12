/*
Lab 4, loops
Mason Antram
Date: 10/22/2023
Version 1.0
Description: This program will give you the factors of a given positive number

*/

#include <iostream>
using namespace std;

int main() {
    int INTEGER, MIN = 1, DIVISOR = 1, FACTOR = 0;


    cout << "Please enter a positive integer " << endl;
    cin >> INTEGER;

    while (cin.fail() || INTEGER < MIN) { //I chose this type of loop because I needed the user to be looped back an indefinite amount of times until their input makes the conditions true
        cout << "You have entered an invalid integer " << endl;
        cin.clear();
        cin.ignore(INTEGER);
        cin >> INTEGER;
    }

    for (DIVISOR = 1; DIVISOR <= INTEGER; DIVISOR++) { //I chose this type of loop because I needed the program to run a max number of times equal to the integer given.
        if (INTEGER % DIVISOR == 0)
            cout << DIVISOR << " is a factor of " << INTEGER << endl;
    }
}