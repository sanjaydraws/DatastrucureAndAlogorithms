#include <iostream>
#include <vector>
using namespace std;

//n elements, total recursive calls = 2ⁿ
// Time Complexity	O(2ⁿ)

// For each recursive call, we are making a copy of the subset vector, which takes O(n) time.
// Space Complexity	O(n)
void printSubsequencesWithSum(vector<int>& nums, vector<int>& subset, int index, int currentSum, int target) {
    if (index == nums.size()) {
        if (currentSum == target) {
            cout << "[ ";
            for (int num : subset) {
                cout << num << " ";
            }
            cout << "]" << endl;
        }
        return;
    }

    // Include current element
    subset.push_back(nums[index]);
    printSubsequencesWithSum(nums, subset, index + 1, currentSum + nums[index], target);

    // Exclude current element (backtrack)
    subset.pop_back();
    printSubsequencesWithSum(nums, subset, index + 1, currentSum, target);
}

int main() {
    vector<int> nums = {1, 2, 1}; 
    int target = 2;
    vector<int> subset;

    cout << "Subsequences with sum " << target << ":\n";
    printSubsequencesWithSum(nums, subset, 0, 0, target);

    return 0;
}
/*
Subsequences with sum 2:
[ 1 1 ]
[ 2 ]
*/