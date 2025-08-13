// https://leetcode.com/problems/house-robber-ii/description/
//213. House Robber II

class Solution {
public:
    int robLinear(vector<int>& nums) {
        int prev = 0, curr = 0;
        for (int x : nums) {
            int temp = curr;
            curr = max(curr, prev + x);
            prev = temp;
        }
        return curr;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // Case 1: exclude last house
        vector<int> case1(nums.begin(), nums.end() - 1);

        // Case 2: exclude first house
        vector<int> case2(nums.begin() + 1, nums.end());

        return max(robLinear(case1), robLinear(case2));
    }
};
