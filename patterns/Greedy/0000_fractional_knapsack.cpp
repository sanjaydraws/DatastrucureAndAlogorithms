//  Fractional Knapsack Problem
/*
 Question:
You are given weights and values of N items. 
Your knapsack has a capacity W. 
You can break items to maximize the total value in knapsack.

Return the **maximum value** you can obtain.

Input:
    N = 3
    values[] = {60, 100, 120}
    weights[] = {10, 20, 30}
    W = 50

 Output:
    240.0

Explanation:
    - Pick item 0 (10kg, value 60) → fully
    - Pick item 1 (20kg, value 100) → fully
    - Pick 20kg from item 2 (value 120 for 30kg → 80 for 20kg)
    - Total = 60 + 100 + 80 = 240
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double fractionalKnapsack(int W, vector<int>& weight, vector<int>& value) {
    int n = weight.size();

    // Step 1: Create index array [0, 1, 2, ..., n-1]
    vector<int> index(n);
    for (int i = 0; i < n; i++) index[i] = i;

    // Step 2: Sort indices by value/weight ratio in descending order
    sort(index.begin(), index.end(), [&](int a, int b) {
        double r1 = (double)value[a] / weight[a];
        double r2 = (double)value[b] / weight[b];
        return r1 > r2;
    });

    double totalValue = 0.0;

    // Step 3: Pick items in sorted order
    for (int i = 0; i < n; i++) {
        int idx = index[i];

        if (W >= weight[idx]) {
            // Pick full item
            totalValue += value[idx];
            W -= weight[idx];
        } else {
            // Pick fractional part
            double ratio = (double)value[idx] / weight[idx];
            totalValue += ratio * W;
            break;  // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    vector<int> value = {60, 100, 120};
    vector<int> weight = {10, 20, 30};
    int W = 50;

    double ans = fractionalKnapsack(W, weight, value);
    cout << "Maximum Value in Knapsack = " << ans << endl;

    return 0;
}

/*
Time Complexity:
    - Sorting: O(n log n)
    - Picking: O(n)
    => Total: O(n log n)

 Space Complexity:
    - Extra space for index array: O(n)
    => Total: O(n)
*/
