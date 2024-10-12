//
// Created by mason on 3/18/2024.
//
#include <iostream>
#include <limits>
#include <iomanip>
#include <exception>
#include <stdexcept>
#include <algorithm>
#include "Header.hpp"

    Card::Card () {std::string name = " "; std::string set = " "; bool graded = false; int grade = 0; bool firstEdition = false;}
    Card::Card (const std::string name, const std::string set, const bool graded,const int grade,const bool firstEdition)
    {
        this -> name = name;
        this -> set = set;
        this -> graded = graded;
        this -> grade = grade;
        this -> firstEdition = firstEdition;
    }

    TCG::TCG () {}
    TCG::TCG (const std::string name, const std::string set, const bool graded, const int grade, const bool firstEdition,
              const std::string rarity, const std::string subType):Card(name, set, graded, grade, firstEdition), rarity(rarity), subType(subType)//i think i need to add rarity and subtype to this list
    {
        TCGCard = new TCG;
        TCGCard -> setName(name);
        TCGCard -> setSet(set);
        TCGCard -> setGraded(graded);
        TCGCard -> setGrade(grade);
        TCGCard -> setFirstEdition(firstEdition);
        this -> rarity = rarity;
        this -> subType = subType;
    }

    Sports::Sports () {}
    Sports::Sports (const std::string name, const std::string set, const bool graded,const int grade,const bool firstEdition,
            const std::string position, const std::string sport):Card(name, set, graded, grade, firstEdition), position(position), sport(sport)
    {
        sportsCard = new Sports;
        sportsCard -> setName(name);
        sportsCard -> setSet(set);
        sportsCard -> setGraded(graded);
        sportsCard -> setGrade(grade);
        sportsCard -> setFirstEdition(firstEdition);
        this -> position = position;
        this -> sport = sport;
    }

void addTCG(TCG**& array, int& count) {
    std::string name;
    std::string set;
    bool graded = false;
    int grade = 0;
    bool firstEdition = false;

    std::string choice;

    std::string rarity;
    std::string subType;

    std::cout << "What is the name of the card?" << '\n';
    std::getline(std::cin, name);

    std::cout << "Card set: " << '\n';
    std::getline(std::cin, set);

    std::cout << "What is the rarity of this card?" << '\n';
    std::getline(std::cin, rarity);

    std::cout << "What type of card is this? (trainer, creature, sorcery, etc.)" << '\n';
    std::getline(std::cin, subType);

    std::cout << "Is it graded (Y/N)?" << '\n';
    std::getline(std::cin, choice);
    if (choice == "Y" || choice == "y")
    {
        graded = true;
        std::cout << "What grade?" << '\n';
        std::cin >> grade;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else graded = false;

    std::cout << "Is it first edition?" << '\n';
    std::getline(std::cin, choice);
    if (choice == "Y" || choice == "y")
    {
        firstEdition = true;
    }
    else firstEdition = false;

    count++;

    if (array == nullptr)
    {
        array = new TCG *[count];

        array[0] = new TCG(name, set, graded, grade, firstEdition, rarity, subType);
    }
    else
    {
        TCG **tempArray = new TCG *[count];
      //  TCG* newCard = new TCG(name, set, graded, grade, firstEdition, rarity, subType);

        for (int i = 0; i < count - 1; i++)
        {
            tempArray[i] = array[i];
        }
        tempArray[count - 1] =  new TCG(name, set, graded, grade, firstEdition, rarity, subType);

        delete [] array;
        array = tempArray;

    }
}

void addSports(Sports**& array, int& count) {
    std::string name;
    std::string set;
    bool graded = false;
    int grade = 0;
    bool firstEdition = false;

    std::string choice;

    std::string position;
    std::string sport;

    std::cout << "What sport does the player play?" << '\n';
    std::getline(std::cin, sport);

    std::cout << "What position does this player play?" << '\n';
    std::getline(std::cin, position);

    std::cout << "What is the name of the card?" << '\n';
    std::getline(std::cin, name);

    std::cout << "Card set: " << '\n';
    std::getline(std::cin, set);

    std::cout << "Is it graded (Y/N)?" << '\n';
    std::getline(std::cin, choice);
    if (choice == "Y" || choice == "y")
    {
        graded = true;
        std::cout << "What grade?" << '\n';
        std::cin >> grade;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else graded = false;

    std::cout << "Is it first edition?" << '\n';
    std::getline(std::cin, choice);
    if (choice == "Y" || choice == "y")
    {
        firstEdition = true;
    }
    else firstEdition = false;

    count++;

    if (array == nullptr)
    {
        array = new Sports *[count];

        array[0] = new Sports(name, set, graded, grade, firstEdition, position, sport);
    }
    else
    {
        Sports **tempArray = new Sports *[count];
      //  Sports* newCard = new Sports(name, set, graded, grade, firstEdition, position, sport);

        for (int i = 0; i < count - 1; i++)
        {
            tempArray[i] = array[i];
        }
        tempArray[count - 1] =  new Sports(name, set, graded, grade, firstEdition, position, sport);

        delete [] array;
        array = tempArray;

    }
}

void removeTCG (TCG**& array, int& count)
{
    int index;
    bool valid = false;
//throw an exception for trying to delete an empty space or from an empty list
    displayTCG(array, count);

    do {
        std::cout << "Which record would you like to remove?" << '\n';
        std::cin >> index;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (count == 0)
        {
            throw std::out_of_range("array is empty");
        }
        else if ((index - 1) > count - 1)
        {throw std::out_of_range("index is past the array size.");}
        else valid = true;

    }while (valid = false);
     //array[(index - 1)] = nullptr;


    for (int i = 0; i < count - 1; i++)
    {
        array[i] = array[i + 1];
    }
    count--;
}

void removeSports (Sports**& array, int& count)
{
    int index;
    bool valid = false;
//throw an exception for trying to delete an empty space or from an empty list
    displaySports(array, count);

    do {
        std::cout << "Which record would you like to remove?" << '\n';
        std::cin >> index;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (count == 0)
        {
            throw std::out_of_range("array is empty");
        }
        else if ((index - 1) > count - 1)
        {throw std::out_of_range("index is past the array size.");}
        else valid = true;

    }while (valid = false);
    //array[index] = nullptr;


    for (int i = 0; i < count - 1; i++)
    {
        array[i] = array[i + 1];
    }
    count--;
}

void displayTCG(TCG** array, const int count)
{
    std::cout << std::setw(15)<< std::left << "Index:" << std::setw(15)<< std::left << "Name:" << std::setw(15)<< std::left << "Set:" << std::setw(15)<< std::left <<"Rarity:"
    << std::setw(15)<< std::left << "Card Type:" << std::setw(15)<< std::left << "First Edition?" << std::setw(15)<<
    std::left <<"Graded?" << std::setw(15)<< std::left <<  "Grade:" << '\n';
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(15) << std::left << (i + 1) ;
        std::cout << std::setw(15)<< std::left << (**(array + i)).getName();
        std::cout << std::setw(15)<< std::left << (**(array + i)).getSet();
        std::cout << std::setw(15)<< std::left << (**(array + i)).getRarity();
        std::cout << std::setw(15)<< std::left << (**(array + i)).getSubType();
        std::cout << std::setw(15)<< std::left << (**(array + i)).getFirstEdition();
        std::cout << std::setw(15)<< std::left << (**(array + i)).getGraded();
        std::cout << std::setw(15)<< std::left << (**(array + i)).getGrade() << '\n';

    }
}

void displaySports(Sports** array, const int count) {
     std::cout << std::setw(15)<< std::left << "Index:" << std::setw(15)<< std::left << "Name:" << std::setw(15) << std::left << "Sport:" << std::setw(15) <<
     std::left << "Position:" << std::setw(15) << std::left << "Set:" << std::setw(15) << std::left << "First Edition?"
     << std::setw(15) << std::left << "Graded?" << std::setw(15) << std::left << "Grade:" << '\n';
    for (int i = 0; i < count; i++) {
        std::cout << std::setw(15) << std::left << (i + 1);
        std::cout << std::setw(15) << std::left << (**(array + i)).getName();
        std::cout << std::setw(15) << std::left << (**(array + i)).getSport();
        std::cout << std::setw(15) << std::left << (**(array + i)).getPosition();
        std::cout << std::setw(15) << std::left << (**(array + i)).getSet();
        std::cout << std::setw(15) << std::left << (**(array + i)).getFirstEdition();
        std::cout << std::setw(15) << std::left << (**(array + i)).getGraded();
        std::cout << std::setw(15) << std::left << (**(array + i)).getGrade() << '\n';
    }
}

void TCGSort(TCG**& array, const int TCGCount)
{
    int choice;

    std::cout << "How would you like to sort?" << '\n';
    std::cout << "1 - Name" << '\n';
    std::cout << "2 - Set" << '\n';
    std::cout << "3 - Grade" << '\n';
    std::cout << "4 - Card type" << '\n';

    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (choice == 1)
    {
       std::sort(array, array + TCGCount, sortTCGByName);
    }

    if (choice == 2)
    {
        std::sort(array, array + TCGCount, sortTCGBySet);
    }

    if (choice == 3)
    {
        std::sort(array, array + TCGCount, sortTCGByGrade);
    }

    if (choice == 4)
    {
        std::sort(array, array + TCGCount, sortTCGBySubType);
    }
    /*inline bool sortTCGByName (TCG* &a, TCG* &b) {return a->getName() < b->getName();}
inline bool sortTCGBySet (TCG* &a, TCG* &b) {return a->getSet() < b->getSet();}
inline bool sortTCGByGrade (TCG* &a, TCG* &b) {return a->getGrade() < b->getGrade();}
inline bool sortTCGBySubType (TCG* &a, TCG* &b) {return a->getSubType() < b->getSubType();}*/

}