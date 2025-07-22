//https://leetcode.com/problems/boats-to-save-people/description/
// 881. Boats to Save People


//Time: O(n log n) → due to sorting

// Space: O(1) extra (in-place sort)
//Greedy Approach (Two Pointer)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()); // Sort the weights
        
        int i = 0;                  // Lightest person
        int j = people.size() - 1;  // Heaviest person
        int boats = 0;

        while (i <= j) {
            if (people[i] + people[j] <= limit) {
                // Pair lightest and heaviest together
                i++;
                j--;
            } else {
                // Heaviest goes alone
                j--;
            }
            boats++; // One boat used
        }
        return boats;
    }
};
