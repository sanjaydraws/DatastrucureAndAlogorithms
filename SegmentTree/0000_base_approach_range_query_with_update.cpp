#include <bits/stdc++.h>
using namespace std;

// ------------------ Approach 1: Naive ------------------
// Query(l..r): O(n) in worst case (r-l+1)
// Update: O(1)
// Space: O(1)
int queryNaive(vector<int>& arr, int l, int r) {
    int sum = 0;
    for (int i = l; i <= r; i++) {
        sum += arr[i];
    }
    return sum;
}
void updateNaive(vector<int>& arr, int idx, int val) {
    arr[idx] += val;
}

// ------------------ Approach 2: Prefix Sum ------------------
// Build Prefix: O(n)
// Query(l..r): O(1)
// Update: O(n) (need to rebuild prefix array)
// Space: O(n)
vector<int> buildPrefix(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }
    return prefix;
}
int queryPrefix(vector<int>& prefix, int l, int r) {
    if (l == 0) return prefix[r];
    return prefix[r] - prefix[l-1];
}
void updatePrefix(vector<int>& arr, vector<int>& prefix, int idx, int val) {
    arr[idx] += val;
    // rebuild prefix (O(n))
    prefix[0] = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }
}

// ------------------ Approach 3: Update + Prefix (Naive Update + Rebuild Prefix) ------------------
// Essentially same as Approach 2 but highlighting update cost
// Build Prefix: O(n)
// Query: O(1)
// Update: O(n)
// Space: O(n)

// ------------------ MAIN ------------------
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "---- Approach 1: Naive ----" << endl;
    cout << "Sum [1..3] = " << queryNaive(arr, 1, 3) << endl; // 2+3+4 = 9
    updateNaive(arr, 2, 2); // arr[2] += 2
    cout << "After update, Sum [1..3] = " << queryNaive(arr, 1, 3) << endl; // 2+5+4 = 11

    // reset array
    arr = {1, 2, 3, 4, 5};

    cout << "\n---- Approach 2: Prefix ----" << endl;
    vector<int> prefix = buildPrefix(arr);
    cout << "Sum [1..3] = " << queryPrefix(prefix, 1, 3) << endl; // 9
    updatePrefix(arr, prefix, 2, 2);
    cout << "After update, Sum [1..3] = " << queryPrefix(prefix, 1, 3) << endl; // 11

    // reset array
    arr = {1, 2, 3, 4, 5};
    prefix = buildPrefix(arr);

    cout << "\n---- Approach 3: Update + Prefix ----" << endl;
    cout << "Sum [1..3] = " << queryPrefix(prefix, 1, 3) << endl; // 9
    updatePrefix(arr, prefix, 2, 2);
    cout << "After update, Sum [1..3] = " << queryPrefix(prefix, 1, 3) << endl; // 11

    return 0;
}
