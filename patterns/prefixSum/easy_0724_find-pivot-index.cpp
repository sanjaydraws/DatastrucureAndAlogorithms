// https://leetcode.com/problems/find-pivot-index/description/
// 724. Find Pivot Index

//find pivot index
// midle index se right ka sum and left ka sum equal

// total = leftSum + nums[i] + rightSum
// rightSum = total - leftSum - nums[i]
// We want
// leftSum == rightSum  -> its Pivot
//leftSum == total - leftSum - nums[i])


// prefix Sum (i to j) in array
 #include <iostream>
#include <vector>
#include <numeric> 
using namespace std;
//Time Complexity: O(n)
//Space Complexity: O(1)
int pivotIndex(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0;
    for(int i =0;i<nums.size();i++){
        if(leftSum == total - leftSum - nums[i]) return i;
        leftSum += nums[i];
    }
    return -1;
}
int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int result = pivotIndex(nums); // 
    cout << "Pivot Index: " << result ;
    return 0;
}



/*
🔥 Follow-up Variations:
Find Middle Index – same but rightmost pivot index.

Weighted pivot – where elements are multiplied by index.

2D matrix pivot (more advanced).

*/