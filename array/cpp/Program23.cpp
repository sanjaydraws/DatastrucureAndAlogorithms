// https://leetcode.com/problems/rotate-image/
#include <iostream>
#include <vector>
#include <algorithm> // Add this line

using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transpose 
        for(int i = 0; i< n ;i++){
            for(int j = i;j <matrix[i].size();j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // reverse
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution sol;
    sol.rotate(matrix);

    // Print the rotated matrix
    for(const auto& row : matrix) {
        for(int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

/**
 7 4 1 
8 5 2 
9 6 3 
*/