#include <iostream>
#include <string>
#include <limits>

void append (std::string list[], int &count, std::string value)
//Adds names to the list array. Takes in list array, count, and value to add. No return.
{
    list[count++] = value;
}

std::string getName(std::string list[], int size, int &count)
//Gets guest name from user. Takes in list array, size, and count. Returns the name entered.
{
    std::string name;

    bool valid = false, done = false;

    do
    {
        do
        {
            std::cout << "Please enter first and last name. Enter done to exit." << '\n';
            std::getline(std::cin, name, '\n');


            if (std::cin.fail())
            {
                std::cout << "Invalid input. Try again.";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

            if (count >= (size -1))
            {
                std::cout << "Guest list is at capacity (20). Type done to exit." << '\n';
            }
            else valid = true;
        } while (!valid);

        if (name != "done" && name != "Done")
        {
            append(list,count,name);
        }
        else (done = true);

    } while (!done);

    return name;
}


void selectionSort(std::string list[], int count)
//sorts names entered by first name. Takes in list array and count, no return.
{
    for (int i = 0; i < count; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < count; j++)
        {
            if (list[j] < list[minIndex])
            {
                minIndex = j;
            }
        }
        std::swap(list[i], list[minIndex]);
    }
}

void displayList(std::string list[], int count)
//displays the guest list. Takes in list array and count, no return.
{
    for (int i = 0; i < count; i++)
    {
        std::cout << list[i] << '\n';
    }
}

int main()
{
    const int SIZE = 20;
    int count = 0;
    std::string list[SIZE];

   getName(list, SIZE, count);

   selectionSort(list, count);

   displayList(list, count);

    return 0;
}

/* For this exercise, assume you are digitizing a guest list for an event. Expect that names
 * will be entered as first name followed by last name on a single line. Create a string array of
 * 20 elements. Read both the first and last names, then join them into a full name and store them
 * in the array until either the array is full, or the user enters the string "done". Use separate functions
 * to input the names, sort them, and display them. Main should call these functions as needed.
 *
 * Example input:
 * Susan Jones
 * Bob White
 * Joe Allen
 * done
 *
 * Sort the names alphabetically by first name using a selection sort. Display the sorted list, one guest per line.
 *
 */