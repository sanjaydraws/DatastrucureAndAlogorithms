
// https://leetcode.com/problems/two-sum/description/
// 1. Two Sum
// Easy


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap; // stores number → index

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // number we need to find

        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i}; // found the pair
        }

        numMap[nums[i]] = i; // store current number and index
    }

    return {}; // no pair found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No valid pair found." << endl;
    }

    return 0;
}
