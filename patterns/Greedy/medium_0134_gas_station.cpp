//https://leetcode.com/problems/gas-station/description/
//134. Gas Station


#include <iostream>
#include <vector>
using namespace std;

/*
    Greedy Approach:
    -------------------
    - If total gas < total cost → cannot complete circuit → return -1
    - Else, we find the starting index from where tank never goes negative
*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalTank = 0;    // Tracks total net gas (gas - cost)
    int currTank = 0;     // Tracks current tank on the current path
    int start = 0;        // Stores current starting index candidate

    for (int i = 0; i < gas.size(); i++) {
        int diff = gas[i] - cost[i];  // Gain/loss at station i
        totalTank += diff;            // Accumulate overall gas status
        currTank += diff;             // Simulate tank while travelling

        // If tank goes negative, restart from next index
        if (currTank < 0) {
            start = i + 1;            // Next station becomes new start
            currTank = 0;             // Reset current tank
        }
    }

    //  Check if total gas is sufficient to cover total cost
    return (totalTank >= 0) ? start : -1;
}

int main() {
    vector<int> gas  = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    int result = canCompleteCircuit(gas, cost);

    if (result != -1)
        cout << "Start at station: " << result << endl;
    else
        cout << "Circuit cannot be completed." << endl;

    return 0;
}
