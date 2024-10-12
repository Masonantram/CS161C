/*
 * Lab: #6 Sorting + Classes
 * Student name: Mason Antram
 * IDE: Clion
 * Date: 3/7/2024
 * Version: 1.0
 * Description: Pulls, sorts, and displays a requested amount of student records from a master list.

 References:
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

    displayArrays (studentArray, records);

    std::sort (studentArray, studentArray + records, sortByName); //sorts list by name

    displayArrays (studentArray, records);

    delete [] studentArray;


    return 0;
}
