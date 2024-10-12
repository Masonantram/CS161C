// Created by mason on 3/7/2024.

#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include "Header.hpp"



Student::Student() { this->name = " "; this->age = 0;}

Student::Student (std::string name, int age) { this -> name = name; this -> age = age;}

void Student::setName (std::string name) { this -> name = name;}
void Student::setAge(int age) {this -> age = age;}

const std::string Student::getName() {return name;}
const float Student::getAge() {return age;}

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

Student* createArray (int size)
//dynamically creates an array of type Student and of the size passed in. Returns the array.
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

    Student* studentArray = new Student[size];

    for (int i = 0; i < size; i++)
    {
        studentArray[i].setName(studentMaster[i]);
        studentArray[i].setAge(ageMaster[i]);
    }

    return studentArray;
}

void displayArrays (Student* studentArray, int records)
// Displays requested list of records. Takes in student/lNumber arrays and the number of records. No return value.
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
}

bool sortByName (Student &a, Student &b)
//Sorting method used by the std::sort function to sort by name in ascending order. Takes two student records in, returns them sorted.
{
    return a.getName() < b.getName();
}

