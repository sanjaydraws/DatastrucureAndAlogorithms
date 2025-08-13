//✅ Include-Exclude C++ Code for Combinations:

// Include-Exclude approach: makes two recursive calls per step — one including the current element, one excluding it.

#include<iostream>
#include<vector>
using namespace std;

void generate(int n, int k, int index, vector<int>& path, vector<vector<int>>& result) {
    // If we've picked k elements, store the result
    if(path.size() == k) {
        result.push_back(path);
        return;
    }

    // If we reach beyond n, stop
    if(index > n) return;

    // Include current index
    path.push_back(index);
    generate(n, k, index + 1, path, result);

    // Exclude current index (backtrack)
    path.pop_back();
    generate(n, k, index + 1, path, result);
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> path;
    generate(n, k, 1, path, result);
    return result;
}

int main() {
    vector<vector<int>> result = combine(4, 2);

    cout << "Combinations of 2 from 1 to 4:\n";
    for(auto& comb : result) {
        cout << "[ ";
        for(int x : comb)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}


/**
 * 
 * 
 * Time Complexity:
Same as for-loop version:
T.C. = O(k * C(n, k))

 */