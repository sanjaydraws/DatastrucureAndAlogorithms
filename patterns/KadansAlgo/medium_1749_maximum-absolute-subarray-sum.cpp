// 1749. Maximum Absolute Sum of Any Subarray

// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/

/*
Example 1:

Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
Example 2:

Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int maxAbsoluteSum(vector<int>& nums) {
    int sum = 0;
    int negSum = 0;
    int minSum = nums[0];
    int maxSum = nums[0];
    for(int i = 0; i < nums.size(); i++) {
        // max sum of subarray
        sum += nums[i];
        maxSum = max(maxSum, sum);
        if(sum < 0){
            sum = 0;
        }

        // min sum of subarray
        negSum += nums[i];
        minSum = min(minSum, negSum);
        if(negSum > 0){
            negSum = 0;
        }
    }
    return max(maxSum, abs(minSum));
}

int main() {
    vector<int> nums = {1, -3, 2, 3, -4}; // Sample input
    int result = maxAbsoluteSum(nums);
    cout << "Maximum absolute subarray sum: " << result << endl;
    return 0;
}
