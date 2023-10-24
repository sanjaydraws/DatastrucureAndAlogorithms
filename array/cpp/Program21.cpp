// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
// rearrange array elements by sign

/*
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
vector<int> rearrangeArray(vector<int>& nums) {
  vector<int> positive,negative;
  for(int num :nums){
    // Separate positive and negative numbers
    if(num>0){
      positive.push_back(num);
    }else{
      negative.push_back(num);
    }
  }
  // Merge the two vectors alternatively
  int i = 0, j = 0, k = 0;
  while(i < positive.size() && j <negative.size()){
    nums[k++] = positive[i++];
    nums[k++] = negative[j++];
  }
  return nums;
}
};


int main() {
  Solution solution;
  vector<int> nums = {3, 1, -2, -5, 2, -4};
  vector<int> result = solution.rearrangeArray(nums);
  for(int num : result) {
      std::cout << num << " ";
  }
  return 0;
}
//Output
//3 -2 1 -5 2 -4