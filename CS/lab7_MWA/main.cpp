/*
 * Lab: #7 Inheritance, Polymorphism
 * Student name: Mason Antram
 * IDE: Clion
 * Date: 3/17/2024
 * Version: 1.1
 * Description: Creates and displays a party of players based on input given by the user.
 */


#include <iostream>
#include "Header.hpp"
#include "Player Class.hpp"

int main() {

    std::cout << "Please enter the number of characters you would like in your party." << '\n';
    int size = getInteger(5, 10);

    Player** playerArray = new Player*[size];

    for (int i = 0; i < size; i++)
    {
        playerArray[i] = createPlayer();
    }

    displayArrays(playerArray, size);

    delete [] playerArray;

    return 0;
}
