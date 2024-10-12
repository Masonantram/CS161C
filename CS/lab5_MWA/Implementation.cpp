// Created by mason on 2/26/2024.

#include <limits>
#include <iostream>
#include <iomanip>
#include <string>
#include "Header.hpp"


inline void getLastName (Student& studentArray, const int index, std::string lastName[])
/* Pulls last name from master list and adds it to Student struct array. Takes in Student array, the index, and last name
master array. No return. */
{
    ((&studentArray) + index)->lastName = lastName[index];
}

inline void getFirstName (Student& studentArray, const int index, std::string firstName[])
/* Pulls first name from master list and adds it to Student struct array. Takes in Student array, the index, and first name
master array. No return. */
{
    ((&studentArray) + index)->firstName = firstName[index];
}

inline void getLNumber (Student& studentArray, const int index, std::string lNumber[])
/* Pulls l number from master list and adds it to Student struct array. Takes in Student array, the index, and l number
master array. No return. */
{
    ((&studentArray) + index)->lNumber = lNumber[index];
}

inline void getGPA (Student& studentArray, const int index, const float GPA[])
/* Pulls GPA from master list and adds it to Student struct array. Takes in Student array, the index, and GPA
master array. No return. */
{
    ((&studentArray) + index)->GPA = GPA[index];
}

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

    std::string lastNameMaster[20] {"Williums", "Juckson", "Green, Jr.",
                                    "Joe", "Tacktheratrix", "@Aliciousness",
                                    "Billings-Clyde", "Eeeeeeeee","Javarison-Lamar", "McCringleberry",
                                    "Dookmarriot", "Morgoone","Jaxon Flaxon-Waxon", "Quatro",
                                    "Buckshank","Grundelplith M.D.", "Velociraptor Maloish",
                                    "Backslashinfourth V", "Teeth",
                                    "Lewith"};
    std::string firstNameMaster[20] {"D'Marcus", "T.J.", "D'squarius", "Sticky", "Jackmerius",
                                     "X-Wing", "D\'Isiah ", "Eeee", "Javaris Jamar",
                                    "Hingle", "L\'Carpetron", "J\'Dinkalage", "Xmus", "Quatro",
                                    "Ozamataz ", "Sequester", "Scoish",
                                    "T.J. A.J. R.J.", "Donkey", "Torque (Drilling Noise)"};
    std::string lNumberMaster[20] {"L00962312", "L00999154", "L00109282", "L00539866", "L00777004",
                                   "L00953852", "L00514348", "L00897196", "L00455901","L00791304",
                                   "L00078699", "L00516741", "L00517872", "L00861459", "L00695860",
                                   "L00016226", "L00633106","L00958642", "L00701607", "L00179899"};
    float GPAMaster[20] {2.10,2.29,3.22,2.83,3.80,3.04,2.17,4.08,3.49,3.75,
                         3.41,2.65,2.25,4.10,3.01,2.71,3.24,3.86,2.05,3.18};

    Student* studentArray = new Student[size];

    for (int i = 0; i < size; i++)
    {
        getLastName (*studentArray,  i, lastNameMaster);
        getFirstName (*studentArray,  i, firstNameMaster);
        getLNumber (*studentArray,  i, lNumberMaster);
        getGPA (*studentArray,  i, GPAMaster);
    }

    return studentArray;
}

void displayArrays (Student* studentArray, int records)
// Displays requested list of records. Takes in student/lNumber arrays and the number of records. No return value.
{
    for (int i = 0; i < records; i++)
    {
        std::cout << std::left << std::setw (COLUMN) << (*(studentArray + i)).firstName;
        std::cout << std::left << std::setw (COLUMN) << (*(studentArray + i)).lastName;
        std::cout << std::left << std::setw(COLUMN) << (*(studentArray + i)).lNumber;
        std::cout << std::left << std::setw(COLUMN) << std::setprecision(2) << std::fixed << (*(studentArray + i)).GPA ;
        std::cout << '\n';
    }
    std::cout << '\n';
}

bool sortByLNumber (Student &a, Student &b)
//Sorting method used by the std::sort function to sort by l number in ascending order. Takes two student records in, returns them sorted.
{
    return a.lNumber < b.lNumber;
}

bool sortByName (Student &a, Student &b)
//Sorting method used by the std::sort function to sort by last name in ascending order. Takes two student records in, returns them sorted.
{
    return a.lastName < b.lastName;
}

int rando(int& num, int max)
//Generates a random number in range for an array. Takes in an integer variable and a maximum number, returns the variable.
{
    return num = rand() % (max - 1);
}

bool binSearch(Student studentArray[], const std::string name, int count, int& index)
/* uses a binary search to look for records matching a random last name. Takes in student array, the name to
 * search for, the count of records, and the index to locate the name on an array. Returns true/false for found/not found. */
{
    int min = 0;
    int max = count - 1;
    bool found = false;

    while (max >= min and !found)
    {
        int mid = (min + max) / 2;

        if (name == studentArray[mid].lastName)
        {
            found = true;
        }
        else if (name > studentArray[mid].lastName)
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }

    if (found)
    {
        index = min;
    }

    return found;
}

