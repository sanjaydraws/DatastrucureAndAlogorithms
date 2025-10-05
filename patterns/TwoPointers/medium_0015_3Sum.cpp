#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach: Sorting + Two Pointer
    // 1. Sort the array
    // 2. Fix one number (nums[i]) and use two pointers (left, right)
    //    to find pairs such that nums[i] + nums[left] + nums[right] == 0
    // 3. Skip duplicates for both i, left, and right to avoid repeating triplets
    // 4. Collect unique triplets in result
    
    /*
Time Complexity:
- Sorting: O(n log n)
- Outer loop: O(n)
- Inner two-pointer: O(n)
Total = O(n^2)

Space Complexity:
- O(1) extra (ignoring result storage)
*/

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        // Step 1: Sort array
        sort(nums.begin(), nums.end());

        // Step 2: Fix one element and apply two-pointer
        for(int i = 0 ; i < n-2; i++){
            // skip duplicate starting elements
            if(i>0 && nums[i] == nums[i -1]) continue;

            int left = i + 1;
            int right = n - 1;

            while(left < right){
                int sum =  nums[i] + nums[left] + nums[right];

                if(sum == 0){
                    // Found one valid triplet
                    res.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for left
                    while(left<right && nums[left] == nums[left + 1]) left++;
                    // Skip duplicates for right
                    while(left<right && nums[right] == nums[right -1]) right--;

                    // Move both pointers
                    left++;
                    right--;
                }
                else if(sum < 0){
                    // Need bigger sum → move left forward
                    left++;
                }
                else{
                    // Need smaller sum → move right backward
                    right--;
                }
            }
        }
        return res;
    }
};



