// Leetcode 37: Sudoku Solver
https://leetcode.com/problems/sudoku-solver/description/


// Time Complexity: O(9^E)
// E = number of empty cells

// At each empty cell, you try 1–9 values → worst-case is exponential
// Time Complexity: O(9^(n)) → Worst case: try 9 digits in each empty cell

// Space Complexity: O(1) → No extra space (board is modified in-place)
// Only the board (in-place) and recursion stack (max depth ≤ 81)


class Solution {
public:
    // Entry point: solves the Sudoku puzzle
    void solveSudoku(vector<vector<char>>& board) {
        solve(board); // Start recursive backtracking
    }

private:
    // Recursive backtracking function
    bool solve(vector<vector<char>>& board) {
        // Traverse each cell
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                // If current cell is empty
                if (board[row][col] == '.') {

                    // Try placing digits '1' to '9'
                    for (char c = '1'; c <= '9'; c++) {

                        // Check if placing c is valid
                        if (isValid(board, row, col, c)) {
                            board[row][col] = c; // Place the digit

                            // Recursively try to solve the rest
                            if (solve(board)) return true;

                            // Backtrack if this path leads to failure
                            board[row][col] = '.';
                        }
                    }

                    // If no valid digit fits, backtrack
                    return false;
                }
            }
        }

        // All cells filled correctly
        return true;
    }

    // Check if placing char c at (row, col) is valid
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check row and column for duplicates
            if (board[row][i] == c || board[i][col] == c)
                return false;

            // Get top-left of 3x3 box
            int boxRow = 3 * (row / 3);
            int boxCol = 3 * (col / 3);

            // Traverse 3x3 box using index breakdown
            int r = boxRow + i / 3;
            int co = boxCol + i % 3;

            // Check 3x3 sub-box for duplicates
            if (board[r][co] == c)
                return false;
        }
        return true; // Placement is safe
    }
};
