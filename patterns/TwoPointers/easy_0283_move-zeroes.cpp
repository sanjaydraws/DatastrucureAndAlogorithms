// 283. Move Zeroes
// https://leetcode.com/problems/move-zeroes/description/

// move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//  do this in-place without making a copy of the array.






#include <iostream>
#include <vector>
using namespace std;

// Function to move all zeroes to the end while maintaining the order of non-zero elements
void moveZeroes(vector<int>& nums) {
    int j = 0; // Pointer to place the next non-zero
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Before moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    moveZeroes(nums);

    cout << "After moving zeroes:  ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
