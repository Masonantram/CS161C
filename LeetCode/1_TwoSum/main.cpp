#include <iostream>
#include <vector>

//submitted to LeetCode 7/27/24

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) { //takes in list of numbers and the target sum

    vector<int> answer {};

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size(); j++) {
            if (target - nums[i] == nums[j] && i != j) { // takes two numbers from nums and determines if the sum equals the target, and they aren't the same number
                answer.push_back(i);
                answer.push_back(j);
                return answer;
            }
        }
    }
    return {};
}


int main() {

    vector<int> nums {1, 3, 5, 8, 11, 13};
    int target = 24;

    vector<int> answer = twoSum(nums, target);

    };