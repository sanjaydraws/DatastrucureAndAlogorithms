// https://leetcode.com/problems/find-pivot-index/
//leetcode 724. Find Pivot Index

#include <iostream>
#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size();i++){
            sum += nums[i];
        }
        int leftSum = 0 ;
        int rightSum = sum;
        for(int i = 0;i<nums.size();i++){
            rightSum = rightSum - nums[i];
            if(leftSum == rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 7, 3, 6, 5, 6};
    int result = sol.pivotIndex(nums);
    std::cout << "Pivot index is: " << result << std::endl;
    return 0;
}

// Output
// Pivot index is: 3