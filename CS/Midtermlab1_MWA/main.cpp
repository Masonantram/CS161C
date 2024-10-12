/* Mason Antram
 * 11/3/2023
 * Midterm Lab #1
 * This program asks the user for an integer and will then tell the user whether that
 * integer is positive, negative, or neither. */


#include <iostream>
using namespace std;

int main() {
    int value;

    cout << "Please enter an integer." << endl;
    cin >> value;

    if (value < 0) {
        cout << "This integer is negative." << endl;
    }

    if (value > 0) {
        cout << "This integer is positive." << endl;
    }

    if (value == 0) {
        cout << "This integer is neither positive or negative." << endl;
    }

    return 0;
}
