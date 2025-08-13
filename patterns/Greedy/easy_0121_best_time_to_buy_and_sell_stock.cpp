//121. Best Time to Buy and Sell Stock
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // Function to calculate maximum profit
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;   // To track the minimum price so far
        int max_profit = 0;        // To track the maximum profit so far

        for (int price : prices) {
            if (price < min_price) {
                min_price = price; // Buy at this price (lowest so far)
            } else {
                int profit = price - min_price;      // Potential profit if sold today
                max_profit = max(max_profit, profit); // Update max profit
            }
        }

        return max_profit;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};  // Example input
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}

/*
Time Complexity: O(n)
- We iterate through the prices array once.

Space Complexity: O(1)
- Only a few variables (min_price, max_profit) are used, no extra space.
*/
