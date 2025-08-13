// 763. Partition Labels
//https://leetcode.com/problems/partition-labels/description/
#include <bits/stdc++.h>
using namespace std;

/*
     Greedy + Last Occurrence Map

     Step 1: Build a map of last occurrence index for each character.
     Step 2: Traverse the string, and for each character:
        - Extend the current partition’s end to max of all last positions seen so far.
        - When current index == end, it means all chars till now are included.
          Push size of this partition to result.
*/
// Time & Space Complexity:
// Time: O(n) — One pass to build last, one pass to traverse string

// Space: O(1) — Since character set is fixed (only lowercase letters, max 26 entries in map)


vector<int> partitionLabels(string s) {
    unordered_map<char, int> last;

    // Step 1: Store last index of each character
    for (int i = 0; i < s.size(); ++i) {
        last[s[i]] = i;
    }

    vector<int> result;
    int start = 0, end = 0;

    // Step 2: Traverse string and create partitions
    for (int i = 0; i < s.size(); ++i) {
        end = max(end, last[s[i]]); // update current partition's end

        // If we reached the end of current partition
        if (i == end) {
            result.push_back(end - start + 1); // size of current partition
            start = i + 1; // start new partition
        }
    }

    return result;
}

int main() {
    string s = "ababcbacadefegdehijhklij";

    vector<int> res = partitionLabels(s);

    for (int len : res) {
        cout << len << " ";
    }

    return 0;
}
