/************************************************************************ 
* Using a while loop, add up the integers 1 to 10. Output the result. 
* Use a constant integer LIMIT to define how many numbers to add up. 
* Use integer variables count and sum in your code.
*************************************************************************/

#include <iostream>
using namespace std;

int main(){
int COUNT = 0, SUM = 0;
const int LIMIT = 10 ;
while (COUNT <= LIMIT) {
    SUM += COUNT;
    cout << SUM << endl;
    COUNT++;
}
    return 0;
}

//Constant integer LIMIT is not defined correctly.
//Set LIMIT to a value.