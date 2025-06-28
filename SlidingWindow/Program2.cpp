// Find the length of the longest subarray with sum ≤ k




#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Time Complexity: O(n²)
// Space Complexity: O(1)
int longestSubarrayBruteForce(vector<int>& arr, int k) {
    int maxLen = 0;

    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += arr[j];

            if (sum <= k) {
                maxLen = max(maxLen, j - i + 1);
            } else {
                break; // optimization: break early if sum exceeds k
            }
        }
    }

    return maxLen;
}

// sliding Window
//. Sliding Window Approach (Optimal for Non-Negative Numbers Only)
// Time Complexity	O(n)
// Space Complexity	O(1)
int longestSubarrayWithSumLEK(vector<int>& arr, int k) {
    int left = 0, right = 0, sum = 0, maxLen = 0;
    int n = arr.size();

    while (right < n) {
        sum += arr[right];

        // Shrink the window if sum exceeds k
        while (sum > k && left <= right) {
            sum -= arr[left];
            left++;
        }

        // Update max length
        if (sum <= k) {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
    }

    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, 1, 0, 1, 1, 0}; // 7
    int k = 4;


    int result1 = longestSubarrayBruteForce(arr, k);
    int result2 = longestSubarrayWithSumLEK(arr, k);


    // Output
    cout << "Length of longest subarray with sum ≤ " << k << " is: " << result1 << endl;
    cout << "Length of longest subarray with sum ≤ " << k << " is: " << result2 << endl;

    return 0;
}
