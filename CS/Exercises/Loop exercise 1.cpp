#include <iostream>
using namespace std;

int main()
{
    int sum;
    int value (0);
    while (value != -1)
    {
        cout << "Enter next number, -1 to quit " << endl;
        cin >> value;
        sum += value;
    }
    cout << "The sum of your numbers, other than -1, is " << sum + 1 << endl;
    return 0;
}

