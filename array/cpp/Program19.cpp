// https://leetcode.com/problems/rotate-array/
// rotate array
//ip - 10, 20, 30, 40, 50, 60
//op - 50 60 10 20 30 40

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        for(int index = 0;index<n;index++){
          int newIndex = (index+k) % n ;
          ans[newIndex] = nums[index];
        }
      nums = ans ;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {10, 20, 30, 40, 50, 60};
    solution.rotate(nums,2);

    // Print the sorted array
    for(int num : nums) {
        cout << num << " ";
    }

    return 0;
}

//Output
//50 60 10 20 30 40