// 943. Find the Shortest Superstring
//https://leetcode.com/problems/find-the-shortest-superstring/description/


// APPROACH 1
// Brute Force (Permutations) + Greedy Merge
/*
1.For every pair of strings, calculate overlap (suffix of one = prefix of another).
2. Pick the pair with the maximum overlap.
3. Merge them into one string.
4.Replace the two with the merged string → now list size reduces by 1.
5.Repeat steps 1–4 until only one string is left.
*/
/**

Time: O(n! * n * L²)

Space: O(n * L) */

class Solution1 {
public:
    // Function to calculate overlap between s1 suffix and s2 prefix
    int calcOverlap(const string &s1, const string &s2) {
        int maxOverlap = 0;
        int minLen = min(s1.size(), s2.size());

        for (int len = 1; len <= minLen; len++) {
            if (s1.substr(s1.size() - len) == s2.substr(0, len)) {
                maxOverlap = len;
            }
        }
        return maxOverlap;
    }

    // Merge s1 and s2 with maximum overlap
    string mergeStrings(const string &s1, const string &s2) {
        int overlap = calcOverlap(s1, s2);
        return s1 + s2.substr(overlap);
    }

    // Find shortest superstring
    string shortestSuperstring(vector<string> &words) {
        int n = words.size();
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 0); // [0,1,2,...,n-1]

        string best = "";
        int bestLen = INT_MAX;

        do {
            string cur = words[perm[0]];
            cout << "curr ->>> " << cur << endl;

            for (int i = 1; i < n; i++) {
                cur = mergeStrings(cur, words[perm[i]]);
            }

            if ((int)cur.size() < bestLen) {
                bestLen = cur.size();
                best = cur;
            }
        } while (next_permutation(perm.begin(), perm.end()));

        return best;
    }
};



/*
Bruteforce recursion/backtracking → possible (same as generating permutations).

DP (bitmask + memoization) → recursion + memo, then tabulation.

Greedy → pure heuristic, no recursion.
*/


// Approach : 2 recursion Backtracking
// Time Complexity: O(n! × n × L²)

// Space Complexity: O(n × L)
class Solution2 {
public:
    // 🔹 Calculate maximum overlap between s1 suffix and s2 prefix
    int calcOverlap(const string & s1, const string & s2){
        int maxOverlap = 0;
        int minLen = min(s1.size(), s2.size());

        // check all possible overlap lengths
        for(int len = 1; len <= minLen; len++){
            // suffix of s1 == prefix of s2 ?
            if(s1.substr(s1.size() - len) == s2.substr(0, len)){
                maxOverlap = len;
            }
        }
        return maxOverlap;
    }

    // 🔹 Merge two strings using maximum overlap
    string mergeStrings(const string &s1, const string &s2) {
        int overlap = calcOverlap(s1, s2);
        // s2 ka non-overlapping part hi add karna hai
        return s1 + s2.substr(overlap);
    }

    // 🔹 Backtracking function
    // cur   → current superstring being built
    // used  → tracks which words are already included
    // best  → stores best (shortest) superstring found so far
    // bestLen → stores length of best
    void backtrack(vector<string> & words, vector<bool>& used, string cur, string& best, int & bestLen){
        int n = words.size();

        // ✅ Check base case: if all words are used
        bool allUsed = true;
        for(int i = 0; i < n; i++){
            if(!used[i]){ 
                allUsed = false; 
                break; 
            }
        }

        // If all words included → update best answer
        if(allUsed){
            if((int) cur.size() < bestLen){
                bestLen = cur.size();
                best = cur;
            }
            return;
        }

        // 🔁 Try adding every unused word next
        for(int i = 0; i < n; i++){
            if(!used[i]){
                used[i] = true;

                string nextStr;
                if(cur.empty()){
                    // first word → directly take it
                    nextStr = words[i];
                } else {
                    // merge with current using overlap
                    nextStr = mergeStrings(cur, words[i]);
                }

                // 🔽 Go deeper in recursion
                backtrack(words, used, nextStr, best, bestLen);

                // 🔙 Undo choice for next possibility
                used[i] = false;
            }
        }
    }

    // 🔹 Main function: returns shortest superstring
    string shortestSuperstring(vector<string> &words) {
        int n = words.size();
        vector<bool> used(n, false);

        string best = "";          // store final best string
        int bestLen = INT_MAX;     // store its length

        // start backtracking with empty string
        backtrack(words, used, "", best, bestLen);

        return best;
    }
};
