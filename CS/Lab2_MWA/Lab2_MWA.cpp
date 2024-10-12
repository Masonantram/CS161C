/*
Lab 2
Mason Antram
Date: 10/8/2023
Version 1.0
Description: This program will generate two random numbers, then ask you for the sum of the two numbers. It will then show you the equation and if your answer was correct or incorrect.
 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr))); //this allows the program to generate unique, random numbers each time.
    int value1, value2, sumComp, sumUser;
    value1 = rand() % (99 - 1 + 1); // Lines 15 and 16 limit the range of random numbers generated to 1-99.
    value2 = rand() % (99 - 1 + 1);
    sumComp = value1 + value2; //This is the computer-generated sum of the two random values
    cout << "What is the sum of " << value1 << " and " << value2 << "?" << endl; // Prompt for user
    cin >> sumUser; // User enters their answer for the sum of the two random values
    cout << setw(12) << value1 << endl; // Lines 20-23 generate the addition problem in standard equation form.
    cout << setw(10) <<"+ " << value2 << endl;
    cout << setw(12) << "----" << endl;
    cout << setw(12) << sumComp << endl; // The answer provided will be the computer-generated answer
    if (sumComp==sumUser) // This statement (lines 24-26) will indicate to the user whether their answer was correct or incorrect.
        cout << "Correct!" << endl ;
    else cout << "Incorrect." << endl ;

    return 0;
}