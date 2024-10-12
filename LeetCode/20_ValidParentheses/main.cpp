#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid (string s)
{

    bool valid = true;
    stack<char> stack;
    int i = 0;
    char check;

    if (s.size() % 2 != 0)
    {
        valid = false;
    }

   while (valid && i < s.size()) {

       if (s[i] == '[' || s[i] == '{' || s[i] == '(') {
           stack.push(s[i]);
           i++;
       }

       if (s[i] == ']' || s[i] == '}' || s[i] == ')') {
           if (stack.empty()) {
               valid = false;
           } else {
               if (s[i] == ']') {
                   check = stack.top();

                   if (check == '[') {
                       stack.pop();
                       i++;
                   } else {
                       valid = false;
                   }
               }

               if (s[i] == '}') {

                   check = stack.top();

                   if (check == '{') {
                       stack.pop();
                       i++;
                   } else {
                       valid = false;
                   }
               }


               if (s[i] == ')') {

                   check = stack.top();
                   if (check == '(') {
                       stack.pop();
                       i++;
                   } else {
                       valid = false;
                   }
               }
           }
       }
   }

    if (!stack.empty() && i == s.size()) {
        valid = false;
    }

    return valid;
   }

int main() {

    string test = "(}";

    bool valid = isValid(test);

    cout << valid;

    return 0;
}
