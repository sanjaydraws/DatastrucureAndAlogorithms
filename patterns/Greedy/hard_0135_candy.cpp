//135. Candy
//https://leetcode.com/problems/candy/description/


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> cand(n, 1);  // Step 1: Give 1 candy to each child

        // Left to Right: If right child has higher rating, give more candy
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                cand[i] = cand[i - 1] + 1;
            }
        }

        // Right to Left: If left child has higher rating, fix it
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                cand[i] = max(cand[i], cand[i + 1] + 1);
            }
        }

        // Sum up all candies
        int sum = 0;
        for (int x : cand) {
            sum += x;
        }

        return sum;
    }
};
