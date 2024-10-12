/************************************************************************ 
* Using a for loop, add up the integers 1 to 10.  Output the result.
* Use a constant integer LIMIT to define how many numbers to add up.
* Use an integer variable named count to increment in the loop.
* Use an integer variable name sum to add up the integers. 
*************************************************************************/

#include <iostream>
using namespace std;

int main(){
    int SUM = 0;
    const int LIMIT = 10 ;

    for (int COUNT = 0; COUNT <= LIMIT; COUNT++)
    {
        SUM += COUNT;
        cout << SUM << endl;
    }
  return 0;
}

//Check your for loop. Are you using variables named LIMIT and count? 6/7