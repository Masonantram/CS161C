/************************************************************************
* This program is supposed read in numbers,
* add them until -1 is entered,
* then display the total of all numbers other than -1.
* There are four problems with the code.
* Your solutions can fix syntax or add a new line.
* Do not move lines of code.
************************************************************************/

#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    int value = 0;
    while (value != -1)
    {
        cout << "Enter next number, -1 to quit ";
        cin >> value;
        sum += value;
    }
    cout << "The sum of your numbers, other than -1, is " << sum +1 << endl;
    return 0;
}
