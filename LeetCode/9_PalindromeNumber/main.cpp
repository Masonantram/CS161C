#include <iostream>
#include <vector>
#include<sstream>
#include <string>

using namespace std;

bool isPalindrome (int x) { //10.33 MB per leetcode
    bool palindrome = false;
    stringstream num;
    num << x;
    string numString;
    num >> numString;
    string reverse = numString ;

  for (int i = 0; i < numString.length(); i++)
  {
      reverse[0 + i] = (numString[numString.length() - 1 - i]);
  }

    if (reverse == numString)
    {
        palindrome = true;
    }

    return palindrome;
};

bool isPalindrome2 (int x) //16.63MB per leetcode
{
    vector<int> indexed {};
    vector<int> reverse {};
    bool palindrome = false;

    if (x >= 0) {
        while (x > 0) {
            indexed.push_back(x % 10);
            x /= 10;
        }

        for (int i = 0; i < indexed.size(); i++) {
            reverse.push_back(indexed.at(indexed.size() - 1 - i));
        }

        if (indexed == reverse) {
            palindrome = true;
        }
    }

    return palindrome;
};



int main() {

int nice = 1001;

bool palindrome = isPalindrome2(nice);

//bool palindrome = isPalindrome(nice);

cout << palindrome<< '\n';


    return 0;
}

