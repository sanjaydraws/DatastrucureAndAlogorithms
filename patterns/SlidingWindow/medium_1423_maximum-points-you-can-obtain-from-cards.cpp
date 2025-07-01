// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
// 1423. Maximum Points You Can Obtain from Cards
// pick from front or back and concecutive , not from Middle



#include <iostream>
#include <vector>
#include <algorithm> // for max()
using namespace std;


// O(k) + O(k) -> O(k) T.c
// O(1) S.c
// Function to calculate max score by picking k cards
int maxScore(vector<int>& cardPoints, int k) {
    int leftSum = 0;
    int rightSum = 0;
    int maxSum = 0;
    int rightIndex = cardPoints.size() - 1;

    // O(k)
    // Calculate the sum of the first k elements from the left
    for (int i = 0; i < k; i++) {
        leftSum += cardPoints[i];
    }

    maxSum = leftSum;

    // O(k)
    // Slide the window: move one card from left to right each time
    for (int i = k - 1; i >= 0; i--) {
        leftSum -= cardPoints[i];              // remove left card
        rightSum += cardPoints[rightIndex];    // add right card
        rightIndex--;
        maxSum = max(maxSum, leftSum + rightSum);
    }

    return maxSum;
}

int main() {
    // Example test case
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    // Function call
    int result = maxScore(cardPoints, k);

    // Output the result
    cout << "Maximum score you can obtain: " << result << endl;

    return 0;
}
