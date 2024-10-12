/*
Final Project - Trading Card Inventory and Sales Management
Student name: Mason Antram
IDE: Clion
Date: 3/22/2024
Version: 1.0
Description: This program allows the user to create and maintain a database of trading cards and sales metrics.

References:
- Deeper understanding of cin, getline, and the input buffer https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/
 * */

#include <iostream>
#include <limits>
#include "Header.hpp"

int main()
{

    Card** collection = nullptr; //empty card collection to start
    bool done = false;
    int choice;
    static int cardCount = 0;

    displayInstructions ();

    do
    {
        do
        {
            std::cout << "What would you like to do?" << '\n';
            std::cout << "1 = Add card" << '\n';
            std::cout << "2 = Remove card" << '\n';
            std::cout << "3 = Display and sort" << '\n';
            std::cout << "4 = Sales metrics" << '\n';
            std::cout << "5 = Display" << '\n';
            std::cout << "0 = Exit" << '\n';

            std::cin >> choice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (std::cin.fail() || choice < 0 || choice > 5 )
            {
                std::cout << "Please choose a number between 0 and 5. Press enter to retry." << '\n';
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (std::cin.fail() || choice < 0 || choice > 5 );

        if (choice == 1)
        {//adds card to collection
            addCard(collection,cardCount);
        }

        if (choice == 2)
        {//removes card from collection
            removeCard (collection, cardCount);
        }

        if (choice == 3)
        {//sorts collection
            sortCollection(collection, cardCount);
        }

        if (choice == 4)
        {//displays sales metrics for collection
            salesMetrics(collection, cardCount);
        }

        if (choice == 5)
        {
            displayCollection(collection, cardCount);
        }

        if (choice == 0)
        {
            done = true;
        }

    } while (!done);

    delete[] collection;
    return 0;
}
