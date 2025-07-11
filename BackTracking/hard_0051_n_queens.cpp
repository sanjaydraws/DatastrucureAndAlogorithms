
//https://leetcode.com/problems/n-queens/description/
//51. N-Queens

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;

        // Create an empty board of size n x n filled with '.'
        vector<string> board(n, string(n, '.'));

        // Track which columns, main diagonals, and anti-diagonals are under attack
        vector<bool> cols(n, false);             // cols[col] → true if column is used
        vector<bool> diag1(2 * n - 1, false);    // diag1[row - col + n - 1]
        vector<bool> diag2(2 * n - 1, false);    // diag2[row + col]

        backtrack(0, n, board, cols, diag1, diag2, results);
        return results;
    }

    void backtrack(int row, int n,
                   vector<string>& board,
                   vector<bool>& cols,
                   vector<bool>& diag1,
                   vector<bool>& diag2,
                   vector<vector<string>>& results) {

        // Base Case: All queens placed
        if (row == n) {
            results.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n - 1;  // Map negative index to 0-based
            int d2 = row + col;

            // Skip if position is under attack
            if (cols[col] || diag1[d1] || diag2[d2]) continue;

            // Place queen and mark attacked zones
            board[row][col] = 'Q';
            cols[col] = diag1[d1] = diag2[d2] = true;

            backtrack(row + 1, n, board, cols, diag1, diag2, results);

            // Backtrack: Remove queen and unmark
            board[row][col] = '.';
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};





// Time Complexity: O(n!) 
//   → Worst-case for backtracking trying all column permutations per row

// Space Complexity: O(n^2 + n)
//   → O(n^2) to store all board states in results
//   → O(n) for cols + O(2n) for diag1 & diag2
//   → O(n) recursion stack depth
