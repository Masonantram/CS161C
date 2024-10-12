/************************************************************************
/* Draw a 4 x 6 rectangle using nested for loops.
/* Declare variables height and width in your for loops and use them
/* as the variables which change value and iterate through the loops.
/* output should be:
/* ######
/* ######
/* ######
/* ######
*************************************************************************/

#include <iostream>

using namespace std;

int main(){

    for (int HEIGHT = 1; HEIGHT <= 4; HEIGHT++)
    {
        for (int WIDTH = 1; WIDTH <= 5; WIDTH++) {
            cout << "#" ;
        }
        cout <<  "#" << endl ;
    }

}
