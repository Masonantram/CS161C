//Design and implement a program that converts Roman Numerals I through V (I, II, III, IV, V) to the equivalent decimal number.

#include <iostream>
using namespace std;

int main() {
   bool I = true, II = true, III = true, IV = true, V = true;
   int answer;


   cout << "Enter roman numeral I, II, III, IV, or V, and I will convert it to the appropriate decimal number." << endl;
   cin >> answer;

   switch (answer) {
       case 'I':
           cout << "1" ;
           break;
       case 'II':
           cout << "2" ;
           break;
       case 'III':
           cout << "3" ;
           break;
       case 'IV':
           cout << "4" ;
           break;
       case 'V':
           cout << "5" ;
           break;
       default:
           if (answer != true)
               cout << "invalid symbol" << endl;
           cin.clear();
           cin.ignore(answer, '\n');
           cin >> answer;
   }


    return 0;
}
