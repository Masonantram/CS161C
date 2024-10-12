/*
 * Lab: #2 Sorting and Searching
 * Student name: Mason Antram
 * IDE: Clion
 * Date: 1/24/2024
 * Version: 1.0
 * Description: Pulls, sorts, and displays a requested amount of student records from a master list.

References:
- (Not sure if I need to include this) the sorting algorithms are straight out da book.
- Most student names used are from the Comedy Central show Key and Peele (East/West College Bowl, S2/E2, and S3/E12).
- Escape sequences:
 https://stackoverflow.com/questions/2414478/escaping-an-apostrophe-in-a-character-literal#:~:text=%5C'%20is%20an%20escape%20sequence,to%20know%20more%20about%20it.
 - Outputting boolean values as true/false:
 https://stackoverflow.com/questions/8261674/c-bool-returns-0-1-instead-of-true-false
 * */


#include "header.hpp"
#include <cstdlib>
#include <string>
#include <iostream>

int main()
{
    const int MIN = 5, MAX = 20;
    std::string student[MAX]{}, lNumber[MAX]{};

    srand((unsigned) time (nullptr));

    int number = getInteger(MIN,MAX);

    fillArrays(student, lNumber, number);

    std::cout << "Here are your requested records, sorted by L Number:" ;
    displayArrays(student, lNumber, number);

    selectionSortName(student, lNumber, number);

    std::cout << "Here are the records sorted by name:" ;
    displayArrays(student, lNumber, number);

    for (int i = 1; i <= 5; i++)
    {
       char randomLetter = static_cast<char>((rand() % 26) + 65);
       std::cout << "Searching for a name starting with the letter " << randomLetter << ":" << '\n';
       bool found = binSearch(student, randomLetter, number);
       std::cout << std::boolalpha << found << '\n';
    }

    return 0;
}
