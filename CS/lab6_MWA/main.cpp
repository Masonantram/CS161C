/*
 * Lab: #6 Sorting + Classes
 * Student name: Mason Antram
 * IDE: Clion
 * Date: 3/14/2024
 * Version: 1.1
 * Description: Pulls, sorts, and displays a requested amount of student records from a master list.
 * Note: The list is pre-made and does not require manual input

 References:
-  Most student names used are from the Comedy Central show Key and Peele (East/West College Bowl, S2/E2, and S3/E12).
*/

#include <algorithm>
#include "Header.hpp"
#include "Classes.hpp"

int main()
{
    int records = getInteger (MIN,MAX);

    Student* studentArray = new Student[records];

    for (int i = 0; i < records; i++)
    {
        Student *ptr = createStudent(i); //dynamically creates array of size records
        *(studentArray + i) = *ptr;
    }

    displayArrays (studentArray, records);

    std::sort (studentArray, studentArray + records, sortByName); //sorts list by name

    displayArrays (studentArray, records);

    delete [] studentArray;

    return 0;
}
