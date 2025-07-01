//53. Maximum Subarray
// Medium
// print max Sum of subarray + print subarray
// https://leetcode.com/problems/maximum-subarray/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find maximum subarray sum using Kadane’s Algorithm
int maxSubArray(vector<int>& nums) {
    int sum = 0;                  // Current subarray sum
    int maxSum = nums[0];         // Overall max subarray sum (initialize with first element)
    
    int start = 0, end = 0;       // Indices to store the start and end of the max subarray
    int tempStart = 0;            // Temporary start index for current subarray

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];           // Add current element to the sum

        // If current sum becomes new max, update max and record indices
        if (sum > maxSum) {
            maxSum = sum;
            start = tempStart;
            end = i;
        }

        // If current sum drops below 0, reset sum and move tempStart to next index
        if (sum < 0) {
            sum = 0;
            tempStart = i + 1;
        }
    }

    // Print the subarray with the maximum sum
    cout << "Subarray with maximum sum: ";
    for (int i = start; i <= end; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return maxSum; // Return the maximum subarray sum
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 1}; // Input array
    int result = maxSubArray(arr);          // Call Kadane’s Algorithm
    cout << "The maximum sum of subarray is: " << result << endl;
    return 0;
}
