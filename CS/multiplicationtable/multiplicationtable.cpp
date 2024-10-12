#include <iostream>
#include <iomanip>
using namespace std;

int main() {
        const int ROWS = 10;
        const int COLS = 10;
        const int COL_WIDTH = 5;

        // print the column headings, start them 5 spaces over
        cout << setw(COL_WIDTH) << " ";

        for (int i = 1; i <= COLS; i++)
        {
            cout << setw(COL_WIDTH) << i;
        }

        cout << endl;

        // now print the times table
        // each row starts with the row number
        for (int i = 1; i <= ROWS; i++)
        {
            cout << setw(COL_WIDTH) << i;

            for (int j = 1; j <= COLS; j++)
            {
                cout << setw(COL_WIDTH) << i * j;
            }

            cout << endl;
        }

        return 0;
}
