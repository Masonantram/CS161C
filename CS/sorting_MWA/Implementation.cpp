// Created by mason on 1/21/2024.

#include "header.hpp"
#include <iostream>
#include <limits>
#include <iomanip>

int getInteger (int MIN, int MAX)
// Asks user for number of records to pull. Takes in the MIN(5) and MAX(20) numbers, returns the user's choice.
{
    int number;
    bool valid = false;

    do
    {
        std::cout << "Please enter the number of records that you would like to pull (between five and twenty)."
                  << '\n';
        std::cin >> number;

        if (std::cin.fail())
        {
            std::cout << "Please enter a valid number." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if(number < MIN || number > MAX)
        {
            std::cout << "Please choose a space between 5 and 20." << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else (valid = true);

    } while (!valid);

    return number;
}

void fillArrays (std::string student[], std::string lNumber[], int number)
/* Updates student/lNumber list with requested number of records from master list, in ascending order of lNumber.
 * Takes in the student/lNumber arrays and the number of records requested. No return value. */
{
    int index = number - 1;

    std::string studentMaster[20]{"D'Marcus Williums", "T.J. Juckson", "D'Squarius Green, Jr.",
                                  "Sticky Joe", "Jackmerius Tacktheratrix", "X-Wing @Aliciousness",
                                  "D\'Isiah T. Billings-Clyde", "Eeee Eeeeeeeee",
                                  "Javaris Jamar Javarison-Lamar", "Hingle McCringleberry",
                                  "L\'Carpetron Dookmarriot", "J\'Dinkalage Morgoone",
                                  "Xmus Jaxon Flaxon-Waxon", "Quatro Quatro", "Ozamataz Buckshank",
                                  "Sequester Grundelplith M.D.", "Scoish Velociraptor Maloish",
                                  "T.J. A.J. R.J. Backslashinfourth V", "Donkey Teeth",
                                  "Torque (Drilling Noise) Lewith"};
    std::string lNumberMaster[20]{"L00486713", "L00123546", "L00814785", "L00224311", "L00715466",
                                  "L00188352", "L00628426", "L00725436", "L00811112", "L00513427",
                                  "L00991022", "L00010203", "L00486271", "L00334411", "L00235689",
                                  "L00542187", "L00986512", "L00958412", "L00741129", "L00648773"};

    for (int i = 1; i < number; i++) //insertion sort
    {
        std::string value = lNumberMaster[i]; //pulling the value out from the index of the array
        std::string value2 = studentMaster[i];
        int j = i - 1;

        while (j >= 0 and lNumber[j] > value)
        {
            lNumber[j + 1] = lNumber[j];
            student[j + 1] = student[j];
            j -= 1;
        }

        lNumber[j + 1] = value;
        student[j + 1] = value2;

    }
}

void displayArrays (const std::string student[], const std::string lNumber[], int number)
// Displays requested list of records. Takes in student/lNumber arrays and the number of records. No return value.
{
    for (int i = 0; i < number; i++)
    {
        std::string value = student[i];
        int length = 45 - value.length();
        std::cout << student[i];
        std::cout << std::setw(length) << lNumber[i] << '\n';
    }
    std::cout << '\n';
}

void selectionSortName(std::string student[], std::string lNumber[], int number)
//Sorts records in ascending order by name. Takes in student/lNumber arrays and number of records. No return.
{
    for (int i = 0; i < number; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < number; j++)
        {
            if (student[j] < student[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(student[i], student[minIndex]);
        std::swap (lNumber[i], lNumber[minIndex]);
    }
}

bool binSearch(const std::string student[], char randomLetter, int number)
/* uses a binary search to look for records matching a random capital letter. Takes in student array, the letter to
 * search for, and the number of records. Returns 1/0 for found/not found.
 * This was the best way I could think of to randomize some search criteria. */
{
    int min = 0;
    int max = number - 1;
    bool found = false;

    while (max >= min and !found)
    {
        int mid = (min + max) / 2;
        std::string name = student[mid];// this pulls the name out of the array to allow me to check the first character

        if (name[0] == randomLetter)
        {
            found = true;
        }
        else if (name[0] < randomLetter)
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }

    return found;
}