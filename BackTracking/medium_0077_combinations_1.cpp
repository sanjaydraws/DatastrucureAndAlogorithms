
// https://leetcode.com/problems/combinations/description/
// 77. Combinations
/*
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
*/

// For-Loop Based Backtracking approach: chooses all possible next elements using a loop.
#include<iostream>
#include<vector>
using namespace std;

// Backtracking function to generate combinations
void backTracking(int n, int k, int start, vector<int>& path, vector<vector<int>>& result) {
    // If the current combination has k elements, save it
    if(path.size() == k) {
        result.push_back(path);
        return;
    }

    // Try each number from 'start' to 'n'
    for(int i = start; i <= n; i++) {
        path.push_back(i);                 // Choose the current number
        backTracking(n, k, i + 1, path, result); // Recurse with next start
        path.pop_back();                   // Undo the choice (backtrack)
    }
}

// Main function to prepare and call backtracking
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> path;
    backTracking(n, k, 1, path, result);
    return result;
}

int main() {
    vector<vector<int>> result = combine(4, 2);

    cout << "All combinations of 2 from 1 to 4:\n";
    for(int i = 0; i < result.size(); i++) {
        cout << "[ ";
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "]\n";
    }

    return 0;
}
/**
 * 
 * 
Combinations Formula 
C(n, k) = n! / (k! * (n - k)!)
n! = factorial of n, k! = factorial of k,(n - k)! = factorial of (n - k)
C(3, 2) = 3! / (2! * (3 - 2)!)
        = 6 / (2 * 1)
        = 6 / 2
        = 3


The total number of k-sized combinations from n elements is:

 
T.C. = O(k * C(n, k))
​There are C(n, k) combinations of size k from n elements.
For each combination, we spend O(k) time to build it (path.push_back, path.pop_back).


S.C. = O(k) [Recursion stack] + O(k * C(n, k)) [To store result]
O(k) space for the recursive call stack (path can hold up to k elements).

O(k * C(n, k)) space to store all the combinations in result
 
Example:
 For n = 3, k = 2:

C(3, 2) = 3! / (2! * 1!) = 6 / (2 * 1) = 3

T.C. = O(k * C(n, k))
     = O(2 * 3)
     = O(6)

S.C. = O(k) recursion + O(k * C(n, k)) result
     = O(2)       + O(2 * 3)
     = O(2)       + O(6)

*/