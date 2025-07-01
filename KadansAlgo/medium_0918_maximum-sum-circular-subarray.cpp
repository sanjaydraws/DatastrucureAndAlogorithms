// 918. Maximum Sum Circular Subarray
//medium
// https://leetcode.com/problems/maximum-sum-circular-subarray/description/
/** 
Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.

**/

/**
 * 
 * 
 * To find this:
 * Max Circular Sum = Total Sum - Minimum Subarray Sum
  nums = [5, -3, 5]
→ Total = 7
→ Min Subarray = -3
→ Max Circular = 7 - (-3) = 10
 */

 //T.c  O(n)
 // s.c O(1)

 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute maximum circular subarray sum
int maxSubarraySumCircular(vector<int>& nums) {
    int total = nums[0];                        // Total sum starts with first element
    int currMax = nums[0], maxSum = nums[0];    // Normal Kadane's
    int currMin = nums[0], minSum = nums[0];    // Min subarray for circular case

    for (int i = 1; i < nums.size(); i++) {     // Start from i = 1 to avoid double counting nums[0]
        int x = nums[i];
        total += x;

        currMax = max(x, currMax + x);
        maxSum = max(maxSum, currMax);

        currMin = min(x, currMin + x);
        minSum = min(minSum, currMin);
    }

    if (maxSum < 0) return maxSum;              // Edge case: all numbers are negative

    return max(maxSum, total - minSum);         // Final answer: normal vs circular
}

// Utility to print result for a test case
void runTest(vector<int> nums) {
    cout << "Input: [ ";
    for (int num : nums) cout << num << " ";
    cout << "]\n";

    int result = maxSubarraySumCircular(nums);
    cout << "Maximum Circular Subarray Sum: " << result << "\n\n";
}

int main() {
    runTest({1, -2, 3, -2});
    runTest({5, -3, 5});
    runTest({-3, -2, -3});
    runTest({-3, -2, -1});
    runTest({-1, -1, -1});

    return 0;
}

/***
// 918. Maximum Sum Circular Subarray
// https://leetcode.com/problems/maximum-sum-circular-subarray/description/
/** 
Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.

**/

/**
 * 
 * 
 * To find this:
 * Max Circular Sum = Total Sum - Minimum Subarray Sum
  nums = [5, -3, 5]
→ Total = 7
→ Min Subarray = -3
→ Max Circular = 7 - (-3) = 10
 */

 //T.c  O(n)
 // s.c O(1)

 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute maximum circular subarray sum
int maxSubarraySumCircular(vector<int>& nums) {
    int total = nums[0];                        // Total sum starts with first element
    int currMax = nums[0], maxSum = nums[0];    // Normal Kadane's
    int currMin = nums[0], minSum = nums[0];    // Min subarray for circular case

    for (int i = 1; i < nums.size(); i++) {     // Start from i = 1 to avoid double counting nums[0]
        int x = nums[i];
        total += x;

        currMax = max(x, currMax + x);
        maxSum = max(maxSum, currMax);

        currMin = min(x, currMin + x);
        minSum = min(minSum, currMin);
    }

    if (maxSum < 0) return maxSum;              // Edge case: all numbers are negative

    return max(maxSum, total - minSum);         // Final answer: normal vs circular
}

// Utility to print result for a test case
void runTest(vector<int> nums) {
    cout << "Input: [ ";
    for (int num : nums) cout << num << " ";
    cout << "]\n";

    int result = maxSubarraySumCircular(nums);
    cout << "Maximum Circular Subarray Sum: " << result << "\n\n";
}

int main() {
    runTest({1, -2, 3, -2});
    runTest({5, -3, 5});
    runTest({-3, -2, -3});
    runTest({-3, -2, -1});
    runTest({-1, -1, -1});

    return 0;
}

/***
Input: [ 1 -2 3 -2 ]
Maximum Circular Subarray Sum: 3

Input: [ 5 -3 5 ]
Maximum Circular Subarray Sum: 10

Input: [ -3 -2 -3 ]
Maximum Circular Subarray Sum: -2

Input: [ -3 -2 -1 ]
Maximum Circular Subarray Sum: -1

Input: [ -1 -1 -1 ]
Maximum Circular Subarray Sum: -1

 */

 */
