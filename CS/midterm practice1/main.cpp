/*Design and implement a program that can be used with elementary school children to teach about change.
The program should ask the student to enter a price that is less than 1 dollar.
The program will calculate and display the amount of change due as well as the number of quarters, dimes, nickels and pennies.*/

#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int main() {
    double price, change, subtotal1, subtotal2, subtotal3, totalquarters, totaldimes, totalnickels, totalpennies;
    const double quarter = 0.25, dime = 0.10, nickel = 0.05, penny = 0.01;

    cout << "Please enter a price less than one dollar" << endl;
    cin >> price;

    if (cin.fail() || price <= 0 || price >= 1) {
        cout << "Invalid price. Please enter a value between 0.01 and 0.99." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n' );
                cin >> price;
    }

    change = 1.00 - price;



    totalquarters = change/quarter;
    int totalquartersr = int (totalquarters);
    subtotal1 = change - (quarter * totalquartersr);
    totaldimes = subtotal1/dime;
    int totaldimesr = int (totaldimes);
    subtotal2 = subtotal1 - (dime * totaldimesr);
    totalnickels = subtotal2/nickel;
    int totalnickelsr = int (totalnickels);
    subtotal3 = subtotal2 - (nickel * totalnickelsr);

    totalpennies = subtotal3/penny;


    cout << "Your change is " << setprecision(3) << change << endl;
    cout <<totalquartersr << " quarters" << endl;
    cout << totaldimesr << " dimes" << endl;
    cout << totalnickelsr << " nickels"  << endl;
    cout << totalpennies << " pennies" << endl;


    return 0;
}

// int quarters, dimes, nickels, pennies, price, change
// cout plz enter a price less than one dollar
// if price <= 0 or >= 1.00, say no and clear buffer
//if price 0-1.00, do 1.00 - price = change
//for coins:
// if change >= 0.25,
//      quarters = change / 0.25 (integer for quotient)
//      need to subtract quarters from change
// if change >= 0.10,
//      dimes = change / 0.10 (integer quotient)
//      subtract dimes from change
// if change >= 0.05
//      nickels = change / 0.05 (integer quotient)
//      subtract nickels from change
// if change >= 0.01
//      pennies = change / 0.01 (integer quotient)
//      subtract pennies from change
// cout total change, then coin totals