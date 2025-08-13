/*
    Problem: Minimum Cost of Ropes (Greedy + Min Heap)

    You are given an array of ropes with different lengths.
    The task is to connect all ropes into one. The cost to connect 
    two ropes is equal to the sum of their lengths. 
    Your goal is to **minimize the total cost**.

    📥 Input:
      - A list of integers representing the lengths of the ropes.

    📤 Output:
      - Minimum total cost required to connect all ropes into one.

     Approach:
      - Use a min heap (priority_queue with min comparator).
      - Always connect the two smallest ropes first to keep cost minimal.
      - Push the resulting rope back into the heap and continue.

     Time Complexity: O(n log n)
     Space Complexity: O(n)

     Similar to: Huffman Encoding Tree
*/

#include <iostream>
#include <vector>
#include <queue> // for priority_queue
using namespace std;

int minCostToConnectRopes(vector<int>& ropes) {
    // Min heap to store ropes by length
    priority_queue<int, vector<int>, greater<int>> minHeap(ropes.begin(), ropes.end());

    int totalCost = 0;

    // While more than one rope remains
    while (minHeap.size() > 1) {
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();

        int cost = first + second;
        totalCost += cost;

        // Push the new rope back to the heap
        minHeap.push(cost);
    }

    return totalCost;
}

int main() {
    vector<int> ropes = {4, 3, 2, 6};

    int result = minCostToConnectRopes(ropes);
    cout << "Minimum cost to connect all ropes = " << result << endl;

    return 0;
}
