#include <bits/stdc++.h>
using namespace std;

// Every number should be at its correct index:
// For range 1 to n → number x should be at index x-1.
// For range 0 to n-1 → number x should be at index x.
void cyclicSort(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
        int correctIndex = nums[i] - 1; 
        if (nums[i] != nums[correctIndex]) {
            swap(nums[i], nums[correctIndex]);
        } else {
            i++;
        }
    }
}

int main() {
    vector<int> arr = {3, 1, 5, 4, 2};
    cyclicSort(arr);

    for (int x : arr) cout << x << " ";
}
