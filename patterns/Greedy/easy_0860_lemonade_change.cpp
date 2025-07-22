//https://leetcode.com/problems/lemonade-change/
//860. Lemonade Change

class Solution {
public:
//  Time Complexity:
//  O(n) where n = number of customers

//  Space Complexity:
// O(1) only using 2 variables
bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;

    for (int bill : bills) {
        if (bill == 5) {
            // No change needed
            five++;
        } else if (bill == 10) {
            // Need to give back one $5
            if (five == 0) return false;
            five--; ten++;
        } else { // bill == 20
            // Prefer giving 1x $10 + 1x $5 as change
            if (ten > 0 && five > 0) {
                ten--; five--;
            }
            // Else give 3x $5 if no $10 available
            else if (five >= 3) {
                five -= 3;
            }
            // Not enough change
            else {
                return false;
            }
        }
    }

    return true;
};