//
// Created by mason on 3/23/2024.
//

#include "Header.hpp"
#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>


//Card constructors
Card::Card () {const std::string type = " "; const std::string series = " "; const std::string subType = " "; const std::string name = " ";
    const std::string set = " "; const bool graded = false; const int grade = 0; const bool firstEdition = false; buyDate.day = "0";
    buyDate.month = "0"; buyDate.year = "0"; sellDate.day = "0"; sellDate.month = "0"; sellDate.year = "0"; const float buyPrice = 0.00;
    const float sellPrice = 0.00;}
Card::Card (const std::string type, const std::string series, const std::string subType, const std::string name, const std::string set,
            const bool graded,const int grade, const bool firstEdition, const date buyDate, const date sellDate, const float buyPrice,
            const float sellPrice)
{
    this -> type = type;
    this -> series = series;
    this -> subType = subType;
    this -> name = name;
    this -> set = set;
    this -> graded = graded;
    this -> grade = grade;
    this -> firstEdition = firstEdition;
    this -> buyDate = buyDate;
    this -> sellDate = sellDate;
    this -> buyPrice = buyPrice;
    this -> sellPrice = sellPrice;
}

TCG::TCG () {}
TCG::TCG (const std::string type, const std::string series, const std::string subType, const std::string name, const std::string set,
const bool graded,const int grade, const bool firstEdition, const date buyDate, const date sellDate,
const float buyPrice, const float sellPrice, const std::string rarity)
:Card (type, series, subType, name, set, graded, grade, firstEdition, buyDate, sellDate, buyPrice, sellPrice), rarity (rarity)
{
    TCGCard = new TCG;
    TCGCard -> setType(type);
    TCGCard -> setSeries(series);
    TCGCard -> setSubType(subType);
    TCGCard -> setName(name);
    TCGCard -> setSet(set);
    TCGCard -> setGraded(graded);
    TCGCard -> setGrade(grade);
    TCGCard -> setFirstEdition(firstEdition);
    this -> rarity = rarity;
}

Sports::Sports () {}
Sports::Sports (const std::string type, const std::string series, const std::string subType, const std::string name, const std::string set,
const bool graded,const int grade, const bool firstEdition, const date buyDate, const date sellDate,
const float buyPrice, const float sellPrice)
:Card (type, series, subType, name, set, graded, grade, firstEdition, buyDate, sellDate, buyPrice, sellPrice)
{
    sportsCard = new Sports;
    sportsCard -> setType(type);
    sportsCard -> setSeries(series);
    sportsCard -> setSubType(subType);
    sportsCard -> setName(name);
    sportsCard -> setSet(set);
    sportsCard -> setGraded(graded);
    sportsCard -> setGrade(grade);
    sportsCard -> setFirstEdition(firstEdition);
}

void displayInstructions ()
{//brief intro. no parameters or return value.
    std::cout << "Welcome to your Trading Card Inventory Management System!" << '\n';
    std::cout << "Please choose from the menu below to manage your inventory and sales." << '\n';
    std::cout << '\n';
}

void addCard(Card**& array, int& count)
//Adds a new card to the collection. Takes in the card collection array and card count, no return value.
{
    std::string rarity = "N/A", type, series, subType, name, set;
    bool graded = false, firstEdition = false, validated = false;
    int grade = 0, intChoice = 0;
    char charChoice = 0;
    date buyDate, sellDate;
    float buyPrice = 0, sellPrice = 0;

    do
    { //two distinct types of Card allows for logging of most any type of trading card series available today.
        std::cout << "What type of card would you like to add?" << '\n';
        std::cout << "1 - Trading Card Game (Pokemon, Magic The Gathering, etc.)" << '\n';
        std::cout << "2 - Sports Cards" << '\n';
        std::cin >> intChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (std::cin.fail() || intChoice < 1 || intChoice > 2)
        {
            std::cout << "Please choose option 1 or 2. Press enter to retry." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (std::cin.fail() || intChoice < 1 || intChoice > 2);

    if (intChoice == 1)
    { //The wording around the series and subType variables is slightly different between types of Card to allow for consolidation of variables
        type = "TCG";

        std::cout << "What is the name of the series (Pokemon, etc.)?" << '\n';
        std::getline(std::cin, series);

        std::cout << "What type of card is this? (trainer, creature, sorcery, etc.)" << '\n';
        std::getline(std::cin, subType);

        std::cout << "What is the rarity of this card?" << '\n';
        std::getline(std::cin, rarity);
    }
    else
    {
        type = "Sports";

        std::cout << "What sport does this player play?" << '\n';
        std::getline(std::cin, series);

        std::cout << "What position does this player play?" << '\n';
        std::getline(std::cin, subType);
    }

    std::cout << "What is the name of the card?" << '\n';
    std::getline(std::cin, name);

    std::cout << "Card set: " << '\n';
    std::getline(std::cin, set);

    do
    {
        std::cout << "Is it graded (Y/N)?" << '\n';
        std::cin >> charChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        validated = yesNoValidation(charChoice, validated);
        if (std::cin.fail() || !validated)
        {// data validation for Y/N
            std::cout << "Invalid answer. Press enter to retry." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (std::cin.fail() || !validated);

    if (charChoice == 'Y' || charChoice == 'y')
    {
        do {
            graded = true;
            std::cout << "What grade (1-10)?" << '\n';
            std::cin >> grade;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (std::cin.fail() || grade < 1 || grade > 10)
            { //data validation for number in range
                std::cout << "Please enter a grade between 1 and 10. Press enter to retry." << '\n';
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (std::cin.fail() || grade < 1 || grade > 10);

        charChoice = 0;

    } else graded = false;

    do
    {
        std::cout << "Is it first edition (Y/N)?" << '\n';
        std::cin >> charChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        validated = yesNoValidation(charChoice, validated);// data validation for Y/N

        if (std::cin.fail() || !validated)
        {
            std::cout << "Invalid answer. Press enter to retry." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (charChoice == 'Y' || charChoice == 'y')
        {
            firstEdition = true;
        } else firstEdition = false;

    } while (std::cin.fail() || !validated);

    do
    { //sales metrics allow the user to track their purchases and sales
        std::cout << "Would you like to set sales metrics (Y/N)?" << '\n';
        std::cin >> charChoice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        validated = yesNoValidation(charChoice, validated); // data validation for Y/N

        if (std::cin.fail() || !validated)
        {
            std::cout << "Invalid answer. Press enter to retry." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (charChoice == 'Y' || charChoice == 'y')
            /* buy/sell dates are taken in as a string, allowing me to consolidate the string when displayed (and allowing
             a person to use words instead of numbers to mark the date) */
        {
            do
            {
                std::cout << "What is the buy date?" << '\n';
                std::cout << "Month:" << '\n';
                std::getline(std::cin, buyDate.month);
                validated = emptyValidation(buyDate.month, validated);//validation for empty field

                if (!validated)
                {
                    std::cout << "Can't leave the field empty. Press enter to try again." << '\n';
                }

            } while (!validated);

            do
            {
                std::cout << "Day:" << '\n';
                std::getline(std::cin, buyDate.day);

                validated = emptyValidation(buyDate.month, validated);//validates for empty field

                if (!validated)
                {
                    std::cout << "Can't leave the field empty. Press enter to try again." << '\n';
                }

            } while (!validated);

            do
            {
                std::cout << "Year:" << '\n';
                std::getline(std::cin, buyDate.year);

                validated = emptyValidation(buyDate.month, validated);//validates for empty field

                if (!validated)
                {
                    std::cout << "Can't leave the field empty. Press enter to try again." << '\n';
                }
            } while (!validated);

            do
            {
                std::cout << "How much did you buy it for?" << '\n';
                std::cin >> buyPrice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (buyPrice < 0)
                {//data validation for negative dollars
                    std::cout << "You can't sell a card for negative money. Press enter to retry." << '\n';
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } while (buyPrice < 0);

            std::cout << "What is the sell date?" << '\n';
            std::cout << "Month:" << '\n';
            std::getline(std::cin, sellDate.month);

            std::cout << "Day:" << '\n';
            std::getline(std::cin, sellDate.day);

            std::cout << "Year:" << '\n';
            std::getline(std::cin, sellDate.year);

            do
            {
                std::cout << "How much did you sell it for (0 for not sold)?" << '\n';
                std::cin >> sellPrice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (sellPrice < 0) { //data validation for negative dollars
                    std::cout << "You can't sell a card for negative money. Press enter to retry." << '\n';
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            } while (sellPrice < 0);
        }
    } while (std::cin.fail() || !validated);

    count++; //increases card count

    if (array == nullptr)
    {//if no card collection array yet, creates one.
        array = new Card *[count];

        if (intChoice == 1)
        {// creates a card* and adds to collection
            array[0] = new TCG(type, series, subType, name, set, graded, grade, firstEdition, buyDate, sellDate,
                               buyPrice, sellPrice, rarity);
        }
        else
        {
            array[0] = new Sports(type, series, subType, name, set, graded, grade, firstEdition, buyDate, sellDate,
                                  buyPrice, sellPrice);
        }
    }
    else
    {
        Card **tempArray = new Card *[count];//creates temporary array to copy contents

        for (int i = 0; i < count - 1; i++)
        {
            tempArray[i] = array[i]; //copies from current array to temp array
        }

        if (intChoice == 1)
        { //creates new Card*
            tempArray[count - 1] = new TCG(type, series, subType, name, set, graded, grade, firstEdition, buyDate,
                                           sellDate, buyPrice, sellPrice, rarity);
        }
        else
        {
            tempArray[count - 1] = new Sports(type, series, subType, name, set, graded, grade, firstEdition, buyDate,
                                              sellDate, buyPrice, sellPrice);
        }

        delete[] array;
        array = tempArray;//copies temporary array back to current array

        std::cout << "Record created!" << '\n';
    }
}

void removeCard (Card**& array, int& count)
{
    int index;
    bool valid = false;

    displayCollection(array, count);

    try
    {
        std::cout << "Which record would you like to remove? Enter the index number." << '\n';
        std::cin >> index;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (count == 0)
        {//throws exception for trying to delete from an empty array
            throw std::out_of_range("array is empty");
        }

        if ((index - 1) > count - 1)
        { //throws exception for trying to delete an index outside the range of the array
            throw std::out_of_range("index is past the array size.");
        }

        std::cout << "Record deleted!" << '\n';

        count--;//shrinks card count
    }
    catch (std::exception& one)
    {
        std::cout << one.what() << '\n';
    }

    for (int i = 0; i < count - 1; i++)
    {//removes indicated index by moving everything past the index down
        array[i] = array[i + 1];
    }
}

void sortCollection(Card**& array, const int count)
//Allows the user to sort their collection in multiple ways. Takes in the collection array and card count, no explicit return.
{
    int choice;

    do
    {
        std::cout << "How would you like to sort?" << '\n';
        std::cout << "1 - Card type (TCG/Sports)" << '\n';
        std::cout << "2 - Name" << '\n';
        std::cout << "3 - Set" << '\n';
        std::cout << "4 - Series (sport name for sports cards)" << '\n';
        std::cout << "5 - Card sub-type (player position, spell, creature, etc.)" << '\n';
        std::cout << "6 - Grade" << '\n';
        std::cout << "7 - Rarity" << '\n';

        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (std::cin.fail() || choice < 1 || choice > 7)
        {//data validation for a choice on the menu
            std::cout << "Please choose a number between 1 and 7. Press enter to retry." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

    } while (std::cin.fail() || choice < 1 || choice > 7);

    if (choice == 1)
    {//sorts by type of card (TCG/Sports)
        std::sort(array, array + count, sortType);
    }

    if (choice == 2)
    {//sorts by card name
        std::sort(array, array + count, sortName);
    }

    if (choice == 3)
    {//sorts by card set
        std::sort(array, array + count, sortSet);
    }

    if (choice == 4)
    {//sorts by card series
        std::sort(array, array + count, sortSeries);
    }

    if (choice == 5)
    {//sorts by card sub-type (trainer, sorcery, etc.)
        std::sort(array, array + count, sortSubType);
    }

    if (choice == 6)
    {//sorts by grade
        std::sort(array, array + count, sortGrade);
    }

    if (choice == 7)
    {//sorts by rarity
        std::sort(array, array + count, sortRarity);
    }

    std::cout << "Collection is sorted!" << '\n';
}

void displayCollection(Card** array, const int count)
//Displays the card colection. Takes in the collection array and card count, no return.
{
    int choice;

    do
    {
        std::cout << "Which collection would you like to see?" << '\n';
        std::cout << "1 - TCG" << '\n';
        std::cout << "2 - Sports" << '\n';
        std::cout << "3 - Both" << '\n';
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice < 1 || choice > 3)
        {
            std::cout << "Please choose a number between 1 and 3. Press enter to retry." << '\n';
        }
    } while (choice < 1 || choice > 3);

    if (choice == 1)
    {//displays only cards of the type TCG
        int tempCount = 1;

        std::cout << std::setw(8) << std::left << "Index:" << std::setw(8) << std::left << "Type:" << std::setw(15)
                  << std::left << "Series:" << std::setw(15) << std::left << "Card Type:" << std::setw(15) << std::left
                  << "Name:" << std::setw(15) << std::left << "Set:" << std::setw(8) << std::left << "1 Ed?" << std::setw(8)
                  << std::left << "Graded?" << std::setw(8) << std::left << "Grade:" << std::setw(15) << std::left
                  << "Rarity:" << '\n';

        if (array != nullptr)
        {
            for (int i = 0; i < count; i++)
            {
                if ((**(array + i)).getType() == "TCG")
                {
                    std::cout << std::setw(8) << std::left << (tempCount++);
                    std::cout << std::setw(8) << std::left << (**(array + i)).getType();
                    std::cout << std::setw(15) << std::left << (**(array + i)).getSeries();
                    std::cout << std::setw(15) << std::left << (**(array + i)).getSubType();
                    std::cout << std::setw(15) << std::left << (**(array + i)).getName();
                    std::cout << std::setw(15) << std::left << (**(array + i)).getSet();
                    std::cout << std::setw(8) << std::left << std::boolalpha << (**(array + i)).getFirstEdition();
                    std::cout << std::setw(8) << std::left << std::boolalpha << (**(array + i)).getGraded();
                    std::cout << std::setw(8) << std::left << (**(array + i)).getGrade();
                    std::cout << std::setw(15) << std::left << (**(array + i)).getRarity() << '\n';
                }
            }
        }
    }

    if (choice == 2)
    {//displays only cards of the type Sports
        int tempCount = 1;

        std::cout << std::setw(8) << std::left << "Index:" << std::setw(8) << std::left << "Type:" << std::setw(15)
                  << std::left << "Series:" << std::setw(15) << std::left << "Card Type:" << std::setw(15) << std::left
                  << "Name:" << std::setw(15) << std::left << "Set:" << std::setw(8) << std::left << "1 Ed?" << std::setw(8)
                  << std::left << "Graded?" << std::setw(8) << std::left << "Grade:" << std::setw(15) << std::left
                  << "Rarity:" << '\n';

        if (array != nullptr)
        {
            for (int i = 0; i < count; i++)
            {
                if ((**(array + i)).getType() == "Sports")
                {
                    std::cout << std::setw(8) << std::left << (tempCount++);
                    std::cout << std::setw(8) << std::left << (**(array + i)).getType();
                    std::cout << std::setw(15) << std::left << (**(array + i)).getSeries();
                    std::cout << std::setw(15) << std::left << (**(array + i)).getSubType();
                    std::cout << std::setw(15) << std::left << (**(array + i)).getName();
                    std::cout << std::setw(15) << std::left << (**(array + i)).getSet();
                    std::cout << std::setw(8) << std::left << std::boolalpha << (**(array + i)).getFirstEdition();
                    std::cout << std::setw(8) << std::left << std::boolalpha << (**(array + i)).getGraded();
                    std::cout << std::setw(8) << std::left << (**(array + i)).getGrade();
                    std::cout << std::setw(15) << std::left << (**(array + i)).getRarity() << '\n';
                }
            }
        }
    }

    if (choice == 3)
    {//displays all cards in the collection
        std::cout << std::setw(8) << std::left << "Index:" << std::setw(8) << std::left << "Type:" << std::setw(15)
                  << std::left <<
                  "Series:" << std::setw(15) << std::left << "Card Type:" << std::setw(15) << std::left << "Name:"
                  << std::setw(15) << std::left << "Set:" << std::setw(8) << std::left << "1 Ed?" << std::setw(8) <<
                  std::left << "Graded?" << std::setw(8) << std::left << "Grade:" << std::setw(15) << std::left
                  << "Rarity:" << '\n';

        if (array != nullptr)
        {
            for (int i = 0; i < count; i++)
            {
                std::cout << std::setw(8) << std::left << (i + 1);
                std::cout << std::setw(8) << std::left << (**(array + i)).getType();
                std::cout << std::setw(15) << std::left << (**(array + i)).getSeries();
                std::cout << std::setw(15) << std::left << (**(array + i)).getSubType();
                std::cout << std::setw(15) << std::left << (**(array + i)).getName();
                std::cout << std::setw(15) << std::left << (**(array + i)).getSet();
                std::cout << std::setw(8) << std::left << std::boolalpha << (**(array + i)).getFirstEdition();
                std::cout << std::setw(8) << std::left << std::boolalpha << (**(array + i)).getGraded();
                std::cout << std::setw(8) << std::left << (**(array + i)).getGrade();
                std::cout << std::setw(15) << std::left << (**(array + i)).getRarity() << '\n';
            }
        }
    }
}

void salesMetrics (Card** array, const int count)
// Gives the user buying/selling metrics for their collection. Takes in the collection array and number of cards, no return.
{
    float buyTotal = 0, sellTotal = 0, totalPL = 0;

    std::cout << std::setw(15) << std::left << "Index:" << std::setw(15) << std::left << "Name" << std::setw(15)
              << std::left << "Buy Date:" << std::setw(15) << std::left << "Sell Date:" << std::setw(15) << std::left
              << "Buy Price:" << std::setw(15) << std::left << "Sell Price:" << std::setw(15) << std::left << "P/L:" << '\n';

    for (int i = 0; i < count; i++)
    {
        std::cout << std::setw(15) << std::left << i + 1

                  << std::setw(15) << std::left << ((**(array + i)).getName())
                  << std::setw(15) << std::left
                  << ((**(array + i)).getBuyDate()).month + "/" + ((**(array + i)).getBuyDate()).day + "/"
                     + ((**(array + i)).getBuyDate()).year <<

                  std::setw(15) << std::left << ((**(array + i)).getSellDate()).month + "/" +
                                                ((**(array + i)).getSellDate()).day + "/" +
                                                ((**(array + i)).getSellDate()).year;

        std::cout << std::setw(15) << std::left << std::fixed << std::setprecision(2)
                  << ((**(array + i)).getBuyPrice());

        std::cout << std::setw(15) << std::left << std::fixed << std::setprecision(2)
                  << ((**(array + i)).getSellPrice());

        std::cout << std::setw(15) << std::left << std::fixed << std::setprecision(2) <<
                  profitLoss(((**(array + i)).getSellPrice()), ((**(array + i)).getBuyPrice()));

        std::cout << '\n';

        buyTotal += ((**(array + i)).getBuyPrice());
        sellTotal += ((**(array + i)).getSellPrice());
        totalPL = sellTotal - buyTotal;

        std::cout << std::setw(15) << std::left << "Totals:" << std::setw(15) << std::left << "" << std::setw(15)
                  << std::left << "" << std::setw(15) << std::left << "" << std::setw(15) << std::left << std::setprecision(2)
                  << buyTotal << std::setw(15) << std::left << std::fixed << std::setprecision(2) << sellTotal <<
                  std::setw(15) << std::left << std::fixed << std::setprecision(2) << totalPL << '\n';
    }
}

inline bool yesNoValidation (const char choice, bool& valid)
//validates choice for Y/y/N/n. Takes in the user's entry and valid variable, returns the valid variable.
{
    if (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
    {
        valid = false;
    } else (valid = true);

    return valid;
}

inline bool emptyValidation (const std::string choice, bool& valid)
//validates entry for empty. Takes in the user's entry and valid variable, returns the valid variable.
{
    if (choice.empty())
    {
        valid = false;
    } else (valid = true);

    return valid;
}



