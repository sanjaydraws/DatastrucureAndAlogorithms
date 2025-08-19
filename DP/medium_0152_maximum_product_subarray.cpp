
// 152. Maximum Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/description/

//Approach 4: Space Optimized (Kadane’s Variation)
//  Time: O(n)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0],minProd = nums[0], ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < 0){
                swap(maxProd, minProd);
            }
            maxProd = max(nums[i], nums[i] * maxProd);
            minProd = min(nums[i], nums[i] * minProd);

            ans = max(maxProd, ans);
        }
        return ans;
    }
};