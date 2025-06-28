// https://leetcode.com/contest/weekly-contest-450/problems/smallest-index-with-digit-sum-equal-to-index/

// Q1. Smallest Index With Digit Sum Equal to Index


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int digitSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(digitSum(nums[i]) == i){
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<int> nums = {1, 3, 2};

    int result = solution.smallestIndex(nums);

    cout << "Smallest index with digit sum equal to index: " << result << endl;

    return 0;
}
