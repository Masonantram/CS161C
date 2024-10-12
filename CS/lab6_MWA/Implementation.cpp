// Created by mason on 3/7/2024.

#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include "Header.hpp"

int getInteger (int min, int max)
//Requests and validates an integer from the user. Takes in the minimum and maximum values allowed, returns the integer.
{
    int num;
    bool valid = false;

    do
    {
        std::cout << "Please select between " << min << " and " << max << " records to pull." << '\n';
        std::cin >> num;

        if (std::cin.fail() || num < min || num > max)
        {
            std::cout << "Please select a number between " << min << " and " << max << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else valid = true;
    } while (!valid);

    return num;
}

Student* createStudent (int index)
//dynamically creates a Student pointer from a master list of names and ages. Takes in an index number, returns the pointer.
{

    std::string studentMaster[20]{"D'Marcus Williums", "T.J. Juckson", "D'Squarius Green, Jr.",
                                  "Sticky Joe", "Jackmerius Tacktheratrix", "X-Wing @Aliciousness",
                                  "D\'Isiah T. Billings-Clyde", "Eeee Eeeeeeeee",
                                  "Javaris Jamar Javarison-Lamar", "Hingle McCringleberry",
                                  "L\'Carpetron Dookmarriot", "J\'Dinkalage Morgoone",
                                  "Xmus Jaxon Flaxon-Waxon", "Quatro Quatro", "Ozamataz Buckshank",
                                  "Sequester Grundelplith M.D.", "Scoish Velociraptor Maloish",
                                  "T.J. A.J. R.J. Backslashinfourth V", "Donkey Teeth",
                                  "Torque (Drilling Noise) Lewith"};

    int ageMaster[20] {11, 22, 65, 89, 70, 47, 32, 35,
                       56,14, 62, 23, 30, 38, 44,16, 51,
                       88, 79, 64};

    Student* ptr = new Student;

       *ptr = Student(studentMaster[index], ageMaster[index]);

    return ptr;
}

void displayArrays (Student* const studentArray, int records)
// Displays requested list of records. Takes in student array and the number of records. No return value.
{
    std::cout << std::left << std::setw (COLUMN) << "Name:";
    std::cout << std::left << std::setw (COLUMN) << "Age:";
    std::cout << '\n';

    for (int i = 0; i < records; i++)
    {
        std::cout << std::left << std::setw (COLUMN) << (*(studentArray + i)).getName();
        std::cout << std::left << std::setw (COLUMN) << (*(studentArray + i)).getAge();
        std::cout << '\n';
    }
    std::cout << '\n';
}
