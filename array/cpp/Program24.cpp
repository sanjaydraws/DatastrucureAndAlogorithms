// https://practice.geeksforgeeks.org/problems/key-pair5616/1
// Key Pair / Two Sum 
/**
N = 6, X = 16
Arr[] = {1, 4, 45, 6, 10, 8}
Output: Yes
Explanation: Arr[3] + Arr[4] = 6 + 10 = 16
*/

#include <algorithm>
#include <iostream>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    sort(arr, arr + n);
	    int low = 0;
	    int high = n -1;
	    while(low < high){
	        int sum = arr[low] + arr[high];
	        if(sum == x){
	            return true;
	        }else if(sum > x){
	            high--;
	        }else{
	            low++;
	        }
	    }
	    return false;
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

// } Driver Code Ends






/**
For Input: 
6 16
1 4 45 6 10 8
Your Output: 
Yes
**/