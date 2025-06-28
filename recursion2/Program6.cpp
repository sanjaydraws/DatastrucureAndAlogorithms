// print Subset of int Array
// Time Complexity: O(2^n) (each element has 2 choices)

// Space Complexity: O(n) (subset vector + recursion stack)
#include <iostream>
#include <vector>
using namespace std;

void printSubsets(vector<int>& nums, vector<int>& subset, int index) {
    if (index == nums.size()) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
        return;
    }

    // Include current element
    subset.push_back(nums[index]);
    printSubsets(nums, subset, index + 1);

    // Exclude current element (backtrack)
    subset.pop_back();
    printSubsets(nums, subset, index + 1);
}

int main() {
    vector<int> nums = {3, 1, 2};  // 🟡 Your example
    vector<int> subset;

    cout << "All subsets:\n";
    printSubsets(nums, subset, 0);

    return 0;
}


/***
                          []
                        /  \
                    [3]    []
                   /  \    /  \
              [3,1] [3]  [1]   []
              /  \  / \   / \   / \
       [3,1,2][3,1][3,2][3][1,2][1][2][]

 
 */