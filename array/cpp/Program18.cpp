
//https://leetcode.com/problems/sort-colors/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int index = 0 ;
        while(index <= right){
            if(nums[index] == 0){
                swap(nums[index], nums[left]);
                left++;
                index++;
            }else if(nums[index] == 2){
                swap(nums[index], nums[right]);
                right--;
            }else{
                index++;
            }
        }
    }
};


int main() {
    Solution solution;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    solution.sortColors(nums);

    // Print the sorted array
    for(int num : nums) {
        cout << num << " ";
    }

    return 0;
}

//Output
//0 0 1 1 2 2