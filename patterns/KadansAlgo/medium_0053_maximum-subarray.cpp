//53. Maximum Subarray
// Medium
// print max Sum of subarray + print subarray
// https://leetcode.com/problems/maximum-subarray/description/


#include <iostream>
#include <vector>
#include <algorithm> // for max()
using namespace std;
// kadane's algorithm
int maxSubArray(vector<int>& nums) {
  int sum = 0 ;
  int maxSum = nums[0];
  for(int i = 0; i<nums.size();i++){
      sum += nums[i];// add the current element to the sum
      maxSum = max(maxSum,sum);// update the maxSum if the current sum is greater
      if(sum<0){
          sum = 0; // reset the sum if it becomes negative
      }
  }  
    return maxSum;
}

int maxSubArray(vector<int>& nums) {
    int currSum = nums[0];       // Start with the first element
    int maxSum = nums[0];        // Initialize max with first element

    for (int i = 1; i < nums.size(); i++) {
        //Choose whether to start a new subarray at nums[i] or extend the previous one.
        currSum = max(nums[i], currSum + nums[i]); // Decide: restart or continue
        //Continuously update the maximum subarray sum found so far.
        maxSum = max(maxSum, currSum);             // Update max
    }

    return maxSum;
}

int main() {
    // Example test case
    vector<int> arr = {1, 2, 3, 4, 5, 6, 1};

    int result =maxSubArray(arr);
    cout << "The maximum sum of subarray is: " << result << endl;
   
    return 0;
}
