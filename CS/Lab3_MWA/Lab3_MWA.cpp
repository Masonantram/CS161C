/*
Lab 3
Mason Antram
Date: 10/15/2023
Version 1.0
Description: This program acts as a basic calculator, allowing the user to solve basic math equations.
 */



#import <iostream>
using namespace std;

int main() {
    int value1, value2;
    char oper;
    cout << "Please enter an integer" << endl; //lines 7-12 ask the user for their math equation
    cin >> value1;
    cout << "Please enter an operator from the following list * / % + - " << endl;
    cin >> oper;
    cout << "Please enter a second integer" << endl;
    cin >> value2;

    switch (oper) { //what I wanted but failed to do was establish a loop so the user couldn't proceed without valid integers and operations.
        case '*':
            cout << value1 << " * " << value2 << " = " << value1 * value2 << endl;
            break;
        case '/':
            if (value2 == 0) cout << "The divisor can not be zero" << endl;
            else cout << value1 << " / " << value2 << " = " << value1 / value2 << endl;
            break;
        case '%':
            if (value2 == 0) cout << "The divisor can not be zero" << endl;
            else cout << value1 << " % " << value2 << " = " << value1 % value2 << endl;
            break;
            case '+':
            cout << value1 << " + " << value2 << " = " << value1 + value2 << endl;
            break;
        case '-':
            cout << value1 << " - " << value2 << " = " << value1 - value2 << endl;
            break;
        default:
            cout << "that is not a valid operation" << endl;

    }

    return 0;
}