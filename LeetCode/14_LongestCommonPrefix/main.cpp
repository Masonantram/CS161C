#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    string answer;

    int n = strs.size();

    if (strs.size() > 1)
    {
    for (int i = 0; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            int small = i;

            if (strs[j] < strs[small]) {
                small = j;
            }

            if (i != small) {
                swap(strs[i], strs[small]);
            }
        }
    }
    }

    string first = strs[0];
    string last = strs[strs.size() - 1];
    int e = 0, size;
    if (first.size() > last.size())
    {
        size = first.size();
    }
    else
    {
        size = last.size();
    }

    while (first[e] == last[e] && e < first.size())
    {
        answer += first[e++];
    }

    return answer;
}


int main() {

    vector<string> testWords {"a"}; // words are assumed to be lowercase

   string answer = longestCommonPrefix(testWords);

   cout << answer << '\n';

    return 0;
}
