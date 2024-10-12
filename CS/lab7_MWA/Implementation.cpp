// Created by mason on 3/15/2024
#include <iostream>
#include <limits>
#include "Header.hpp"
#include "Player Class.hpp"

int getInteger (int min, int max)
//Requests and validates an integer from the user. Takes in the minimum and maximum values allowed, returns the integer.
{
    int num;
    bool valid = false;

    do
    {
        std::cout << "Please select a number between " << min << " and " << max << "." << '\n';
        std::cin >> num;

        if (std::cin.fail() || num < min || num > max)
        {
            std::cout << "Invalid number." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else valid = true;
    }
    while (!valid);

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return num;
}

Player* createPlayer()
//Creates a new player with a name, age, and role indicated by the user. No parameters, returns a player pointer.
{
    Player *player;
    std::string firstName, lastName;
    int age, role;
    bool valid = false;

    do
    {
        std::cout << "Please enter the character's first name: " << '\n';
        std::getline(std::cin, firstName);

        if (std::cin.fail())
        {
            std::cout << "Invalid name." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else valid = true;
    }
    while (!valid);

    valid = false;

    do
    {
        std::cout << "Please enter their last name: " << '\n';
        std::getline(std::cin, lastName);
        if (std::cin.fail())
        {
            std::cout << "Invalid name." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else valid = true;

    }
    while (!valid);

    valid = false;

    std::cout << "Enter their age: " << '\n';
    age = getInteger(5, 90);

    std::cout << "Choose a class:" << '\n';
    std::cout << "1 = Ranger" << '\n';
    std::cout << "2 = Wizard" << '\n';
    std::cout << "3 = Rogue" << '\n';
    std::cout << "4 = Priest" << '\n';

    role = getInteger(1, 4);

    switch (role)
    {
        case 1:
            player = new Ranger(firstName, lastName, age);
            break;
        case 2:
            player = new Wizard(firstName, lastName, age);
            break;
        case 3:
            player = new Rogue(firstName, lastName, age);
            break;
        case 4:
            player = new Priest(firstName, lastName, age);
            break;
        default:
            player = new Ranger(firstName, lastName, age);
            break;
    }

    return player;
}

void displayArrays (Player** array, const int size)
//displays the array of players. Takes in the player array and size of array, no return.
{

    for (int i = 0; i < size; i++) {
        std::cout << array[i]->getFirstName() << " ";
        std::cout << array[i]->getLastName() << " ";
        std::cout << array[i]->getAge() << " ";
        std::cout << array[i]->getClassName() << " ";
        std::cout << array[i]->getAction() << " " << '\n';
    }

}
