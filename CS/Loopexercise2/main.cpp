/************************************************************************
* This program should output the first 10 odd numbers.
* There are 3 problems with it.
* Note: Do not add any new lines.
************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    cout << "This program will output the odd numbers 1, 3, ..., 19"
         << endl;
    for (int i = 0; i <= 9; i++)
    {
        cout << 2 * i + 1 << endl;
    }
    return 0;
}