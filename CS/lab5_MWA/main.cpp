/*
 * Lab: #5 Sorting and Searching + structs
 * Student name: Mason Antram
 * IDE: Clion
 * Date: 3/3/2024
 * Version: 1.1
 * Description: Pulls, sorts, and displays a requested amount of student records from a master list.

 References:
- Setting display of float variables to two decimal places: https://stackoverflow.com/questions/5907031/printing-the-correct-number-of-decimal-places-with-cout
- Better understanding of setw() and alignment of columns : https://cpppatterns.com/patterns/write-data-in-columns.html
-  Most student names used are from the Comedy Central show Key and Peele (East/West College Bowl, S2/E2, and S3/E12).
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include "Header.hpp"

int main()
{
    int records = getInteger (MIN,MAX);

    Student* studentArray = createArray (records); //dynamically creates array of size records

    std::sort (studentArray, studentArray + records, sortByLNumber); //sorts list by l number

    displayArrays (studentArray, records);

    std::sort (studentArray, studentArray + records, sortByName); //sorts list by last name

    displayArrays (studentArray, records);

    for (int i = 1; i <= MIN; i++) //searches array for a last name from the master list, and displays the record if found.
    {
        int index = 0;
        Student* testArray = createArray(MAX); //dynamically creates test array to compare against first array

        std::sort (testArray, testArray + (MAX - 1), sortByName);

        std::string randomName = (testArray + rando(index, MAX)) -> lastName;

        std::cout << "Searching the selected records for the last name " << randomName << ":" << '\n';

        bool found = binSearch (studentArray, randomName, records, index);

        if (found)
       {
            std::cout << "Record found! Displaying below:" << '\n';
            std::cout << std::left << std::setw (COLUMN) << (*(studentArray + index)).firstName;
            std::cout << std::left << std::setw (COLUMN) << (*(studentArray + index)).lastName;
            std::cout << std::left << std::setw(COLUMN) << (*(studentArray + index)).lNumber;
            std::cout << std::left << std::setw(COLUMN) << std::setprecision(2) << std::fixed <<
            (*(studentArray + index)).GPA ;
            std::cout << '\n';
       }
        else
        {
            std::cout << "Record not found." << '\n';
        }

        delete [] testArray;
    }

    delete [] studentArray;

    return 0;
}
