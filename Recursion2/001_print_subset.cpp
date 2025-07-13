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
    vector<int> nums = {3, 1, 2};  
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

 Call: printSubsets(nums, subset = [], index = 0)
│
├── Include nums[0] = 3 → subset = [3]
│   └── printSubsets(nums, [3], 1)
│       ├── Include nums[1] = 1 → subset = [3,1]
│       │   └── printSubsets(nums, [3,1], 2)
│       │       ├── Include nums[2] = 2 → subset = [3,1,2]
│       │       │   └── printSubsets([3,1,2], 3) → ❗ base case → print [3 1 2]
│       │       └── Exclude 2 → backtrack to [3,1]
│       │           └── printSubsets([3,1], 3) → print [3 1]
│       └── Exclude 1 → backtrack to [3]
│           └── printSubsets([3], 2)
│               ├── Include 2 → [3,2]
│               │   └── printSubsets([3,2], 3) → print [3 2]
│               └── Exclude 2 → [3]
│                   └── printSubsets([3], 3) → print [3]
├── Exclude 3 → backtrack to []
│   └── printSubsets([], 1)
│       ├── Include 1 → [1]
│       │   └── printSubsets([1], 2)
│       │       ├── Include 2 → [1,2]
│       │       │   └── printSubsets([1,2], 3) → print [1 2]
│       │       └── Exclude 2 → [1]
│       │           └── printSubsets([1], 3) → print [1]
│       └── Exclude 1 → []
│           └── printSubsets([], 2)
│               ├── Include 2 → [2]
│               │   └── printSubsets([2], 3) → print [2]
│               └── Exclude 2 → []
│                   └── printSubsets([], 3) → print []

 */