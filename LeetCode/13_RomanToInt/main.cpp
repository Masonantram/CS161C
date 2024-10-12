#include <iostream>
#include <string>
#include <map>

using namespace std;

    int romanToInt(string s) {

        map<char, int> romanInt;
        map<char, int>::iterator itr;
        map<char, int>::iterator itr2;
        int total = 0;

        //fill the map
        //remember: by default, maps are sorted by key in ascending order
        romanInt.insert(pair<char, int>('I', 1));
        romanInt.insert(pair<char, int>('V', 5));
        romanInt.insert(pair<char, int>('X', 10));
        romanInt.insert(pair<char, int>('L', 50));
        romanInt.insert(pair<char, int>('C', 100));
        romanInt.insert(pair<char, int>('D', 500));
        romanInt.insert(pair<char, int>('M', 1000));

     for (int i = 0; i < s.size(); i++)
     {//iterators are looking at the current index and the index ahead of it to determine addition or subtraction
         itr = romanInt.find(s[i]);
         itr2 = romanInt.find(s[i+1]);

         if (itr != romanInt.end()) // if the key is found (it will point to the theoretical end of the map if not)
         {
             if (itr2 -> second > itr -> second) //if I is before V in the string, for example, subtract instead of add
             {
                 total -= itr -> second;
             }
             else
             {
                 total += itr -> second;
             }
         }

     }
        return total;
    }


int main() {

    string potato = "MMCDZZ"; // test number
    int sol = romanToInt(potato);

    cout<< sol << '\n';


    return 0;
}
