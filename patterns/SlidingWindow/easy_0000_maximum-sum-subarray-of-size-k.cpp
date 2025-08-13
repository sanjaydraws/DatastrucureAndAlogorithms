
// Maximum Sum of Subarray of Size K

#include <iostream>
#include <vector>
#include <algorithm> // for max()

using namespace std;

// Function to find the maximum sum of any subarray of size k
int maxSumK(vector<int>& nums, int k) {
    int maxSum = 0;      // Stores the result (maximum sum found)
    int windowSum = 0;   // Sum of the current window of size k

    // Step 1: Calculate the sum of the first window of size k
    for (int i = 0; i < k; i++) {
        windowSum += nums[i];
    }

    maxSum = windowSum;  // Initialize maxSum with the first window sum

    // Step 2: Slide the window from index k to end of array
    for (int end = k; end < nums.size(); end++) {
        // Slide the window forward: subtract the element going out and add the new element coming in
        windowSum += nums[end] - nums[end - k];

        // Update maxSum if the current windowSum is greater
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;  // Return the maximum sum found
}

int main() {
    vector<int> nums = {2, 1, 5, 1, 3, 2};
    int k = 3;
    int result = maxSumK(nums, k);
    cout << "Maximum sum of subarray of size " << k << " is: " << result << endl;

    return 0;
}
