//904. Fruit Into Baskets
//https://leetcode.com/problems/fruit-into-baskets/description/


class Solution {
public:
    // Approach: Sliding Window (Variable Size Window) + HashMap
    // We want the longest subarray with at most 2 distinct fruits.
    // Use a sliding window [left, right] and a hash map (basket) to count fruits.
    // Expand window by moving 'right'. If we have > 2 fruit types, shrink window by moving 'left'.
    // Track the maximum window size.

    // Time Complexity: O(n)  -> Each element is inserted/removed at most once.
    // Space Complexity: O(1) -> Hash map stores at most 2 fruit types.

    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket; // fruit type -> count
        int left = 0, maxLen = 0;

        for (int right = 0; right < fruits.size(); right++) {
            // Add current fruit to the basket
            basket[fruits[right]]++;

            // If more than 2 distinct fruits, shrink window from left
            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]); // remove empty fruit type
                }
                left++;
            }

            // Update maximum window length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
