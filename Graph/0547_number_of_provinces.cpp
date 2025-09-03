//547. Number of Provinces
//https://leetcode.com/problems/number-of-provinces/description/


class Solution {
public:
    // DFS function: explore all cities connected with city 'i'
    void dfs(int i, vector<int>& vis, vector<vector<int>>& isConnected) {
        vis[i] = 1; // mark current city as visited
        for (int j = 0; j < isConnected.size(); j++) {
            // if there is a connection from i -> j and j is not visited
            if (isConnected[i][j] == 1 && !vis[j]) {
                dfs(j, vis, isConnected); // visit city j
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0); // visited array, initially all unvisited
        int count = 0;         // number of provinces

        // check every city
        for (int i = 0; i < n; i++) {
            // if this city is not visited, it belongs to a new province
            if (!vis[i]) {
                count++;                // new province found
                dfs(i, vis, isConnected); // mark all connected cities
            }
        }
        return count; // total number of provinces
    }
};
