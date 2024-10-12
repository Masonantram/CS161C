#include <iostream>
#include <limits>
#include "Header.hpp"

/*
References:
 - Deeper understanding of cin, getline, and the input buffer https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/
 */

int main() {

    TCG **TCGArray = nullptr;
    Sports **sportsArray = nullptr;

    int cardType;
    bool done = false;
    int choice;
    static int TCGCount = 0, sportsCount = 0;

    //don't forget buy/sell dates and sales metrics and totals
    //data validation

    do {
        std::cout << "What would you like to do?" << '\n';
        std::cout << "1 = add card" << '\n';
        std::cout << "2 = remove card" << '\n';
        std::cout << "3 = sort" << '\n';
        std::cout << "4 = display" << '\n';
        std::cout << "0 = exit" << '\n';

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            std::cout << "What type of card would you like to add?" << '\n';
            std::cout << "1 - Trading Card Game (Pokemon, Magic The Gathering, etc.)" << '\n';
            std::cout << "2 - Sports Cards" << '\n';
            std::cin >> cardType;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (cardType == 1) {
                addTCG(TCGArray, TCGCount);
            } else {
                addSports(sportsArray, sportsCount);
            }
        }

        if (choice == 2)
        {
            std::cout << "What type of card would you like to remove?" << '\n';
            std::cout << "1 - Trading Card Game (Pokemon, Magic The Gathering, etc.)" << '\n';
            std::cout << "2 - Sports Cards" << '\n';
            std::cin >> cardType;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (cardType == 1) {
                removeTCG(TCGArray, TCGCount);
            } else {
                removeSports(sportsArray, sportsCount);
            }
        }

        if (choice == 3)
        {
            TCGSort(TCGArray, TCGCount);
        }

        if (choice == 4) {
            displayTCG(TCGArray, TCGCount);
         //   displaySports(sportsArray, sportsCount);
        }

        if (choice == 0)
        {
            done = true;
        }

    } while (!done);

    delete[] TCGArray;
    return 0;
}

/*
 what would you like to do?

 1- add
 2- delete
 3- sort
 4- display
 5- research (sales metrics)
 0 - exit

    1 - addCard()
    what kind of card would you like to add?
    1 - TCG (pokemon, magic, etc)
    2 - sports

        1 - addTCG()
        2 - addSports()

    2 - deleteCard()
    what kind of card would you like to delete?
    1 - TCG (pokemon, magic, etc)
    2 - sports

        1 - deleteTCG()
        2 - deleteSports()

    3 - sortList()
    which list would you like to sort?
    1 - TCG
    2- sports
    3- Both
        what sorting criteria would you like to use?
        1- name
        2- set
        3-graded;
        4-grade;
        5- firstEdition;

        if TCG or both:
        6- rarity
        7- cardType
        8- game (pokemon, MTG, etc)

        if sports or both:
        6- sport
        7- position

    4 - displayList()
    which list would you like to display?
    1- TCG
    2- Sports
    3- both


 */