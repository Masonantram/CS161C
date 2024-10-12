#include <iostream>
#include<string>
#include<sstream>
using namespace std;

int main() {
    int width, length;

    cout << "enter your width and length: " << endl;
    cin >> width; //>> length;

 /*   //rectangle
    for (int i = 1; i <= length; i++) {
        for (int j = 1; j <= width; j++) {
            cout << "*";
            if (j == width) { cout << endl; }
        }
    }

    cout << endl;
    cout << endl;

    //triangle
    for (int i = 1; i <= width; i++){
        for (int j = 1; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }

    cout << endl;
    cout << endl;

    //square
    for (int i = 1; i <= width; i++) {
        for (int j = 1; j <= width; j++) {
            cout << "*" ;
            if (j == width){cout << endl;}

        }
    } */

    //diamond
for (int k = width; k > 0; k--) {

    for (int i = 1; i <= width; i++) {
        for (int j = 1; j <= i; j++) {
            /*    for (int k = width; k > i; k--)
                {
                    cout << " ";
                }     */
            cout << "*";
        }
        cout << endl;
    }

    /*
    for (int i = 0; i <= width; i++)
    {
        for (int j = width; j > i; j--){
            cout << " ";
        }
        cout << "*";
    }
*/
}
    return 0;
}
