
// prefix Sum range (i to j) in array
 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// prefix Sum array
// if array doesn't change
// T.c O(n)
// s.c O(n)
vector<int> prefixSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];

    for(int i =1; i<n; i++){
        prefix[i] = prefix[i -1] + arr[i];
    }
    return prefix;
}

// prefix Sum array in place
// if array can change
// T.c O(n)
// s.c O(1) //(no extra array used)
void prefixSumInPlace(vector<int> &arr){
    int n = arr.size();
    for(int i = 1; i<n; i++){
        arr[i] += arr[i -1];
    }
}

// In-place prefix sum build: O(n)
// Range sum query: O(1)
// T.c O(n)
// s.c O(1) //(no extra array used)
int rangeSum(vector<int> &arr, int i, int j){
    if(i ==0) return arr[j];
    return arr[j] - arr[i -1];
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> result = prefixSum(nums); // 1 3 6 10 15

    // Print the prefix sum array
    cout << "Prefix Sum: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> nums2 = {2, 4, 6, 10, 5};

    prefixSumInPlace(nums2);
    cout << "Prefix Sum In Place: ";
    for (int val : nums2) {
        cout << val << " ";
    }
    cout << endl;
    cout << "Total sum from index 1 to 3: " << rangeSum(nums2, 1, 3) ;

    return 0;
}
