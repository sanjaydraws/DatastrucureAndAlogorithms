// https://leetcode.com/problems/find-the-duplicate-number/
// find duplicate number


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
     // M1 - 
    // T.c - O(nlogn) SC - O(n)
    int findDuplicate1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0 ; i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }
    // M2 : negative marking method
    // TC : O(n) SC:O(1)
    int findDuplicate2(vector<int>& nums){
        int ans = -1;
        for(int i = 0; i < nums.size(); i++){
            int index = abs(nums[i]);
            // if already visited
            if(nums[index]<0){
                ans = index;
                break;
            }
            // mark visited
            nums[index] *= -1;
        }
      return ans;
    }
    //M3 -Positioning method
    // Without modifying array 
    // TC : O(n) SC : O(1)
    int findDuplicate3(vector<int>& nums){
        while (nums[0]!=nums[nums[0]])
        {
            swap(nums[0], nums[nums[0]]);
        }
        return nums[0];
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 2, 2};
    Solution sol;
    int result = sol.findDuplicate3(nums);

    if(result != -1) {
        cout << "Duplicate element: " << result;
    }
}
/**
Output:
Duplicate element: 2
*/