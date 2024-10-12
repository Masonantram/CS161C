/***************************************************************
/* Fix this validation program
/* Program should ask for a positve integer
/* and only display a positive integer.
/* Add a fix if the user types in a character.
/* Note: The program "works" but it doesn't always work.
****************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int value;
    bool valid = false;


    do {
        cout << "Enter a positive integer" << endl;
        cin >> value;
        if (cin.fail())
        {
            cout << "Invalid number, try again" << endl;
            cin.clear();
            cin.ignore(value, '\n');
        }
        if (value >0){
            valid = true;
        }
    } while (!valid);


    cout << "Your number was " << value << endl;

    return 0;
}

// If you're using cin and the user entered bad data, did you clear the buffer? Try 100, '\n'.