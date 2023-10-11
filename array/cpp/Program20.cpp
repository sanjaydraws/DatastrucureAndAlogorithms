//https://leetcode.com/problems/missing-number/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        int expectedSum = (n * (n + 1))/2;
        int actualSum  = 0;
        for(int num : nums){
           actualSum += num;
        }
        return expectedSum - actualSum;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 5, 6, 7, 8};
    cout<<"missing number:"<<solution.missingNumber(nums);

   

    return 0;
}

//Output
//missing number: 4