//https://leetcode.com/problems/restore-ip-addresses/
//93. Restore IP Addresses

class Solution {
public:
    vector<string> result;

    // Main function to start the backtracking
    vector<string> restoreIpAddresses(string s) {
        solve(s, 0, 0, "");
        return result;
    }

    // Recursive function to explore all valid IP combinations
    void solve(string& s, int index, int parts, string current) {
        // Base case: 4 parts formed and full string used
        if (parts == 4 && index == s.length()) {
            current.pop_back(); // remove last dot
            result.push_back(current);
            return;
        }

        // Try parts of size 1 to 3
        for (int len = 1; len <= 3 && index + len <= s.length(); len++) {
            string part = s.substr(index, len);

            if (!isValid(part)) continue; // Validate this segment

            solve(s, index + len, parts + 1, current + part + ".");
        }
    }

    // Helper to check if a part is a valid IP segment
    bool isValid(string& part) {
        if (part.length() > 1 && part[0] == '0') return false;
        int value = stoi(part);
        return value >= 0 && value <= 255;
    }
};

/*
Time Complexity (T.C.):
- here  try up to 3 segments at each of the 4 positions (1 to 3 digits long)
- So max recursive calls: O(3^4) = O(81)
- Each valid IP is at most 15 characters, so string operations are O(1)
- Final T.C. = O(1), constant for fixed input length (s.length() ≤ 12)

Space Complexity (S.C.):
- Recursion depth = 4 → O(1)
- Temporary strings at each level → O(1)
- Result vector stores at most a few dozen IPs (bounded) → O(1)
- Total auxiliary space: O(1)
*/
