//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
//Undirected Graph Cycle


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // BFS approach
    // T.C. → O(V + E)  (har vertex aur har edge ek baar visit hota hai)
    // S.C. → O(V + E)  (adjacency list space) + O(V) (visited array) + O(V) (queue) ≈ O(V + E)
    bool bfs(int start, vector<int> adj[], vector<bool> &visited) {
        queue<pair<int,int>> q; // {node, parent}
        visited[start] = true;
        q.push({start, -1});

        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            for (int neigh : adj[node]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    q.push({neigh, node});
                }
                else if (neigh != parent) { // visited and not parent → cycle
                    return true;
                }
            }
        }
        return false;
    }

    // DFS approach
    // T.C. → O(V + E)  (har vertex aur har edge ek baar visit hota hai)
    // S.C. → O(V + E)  (adjacency list space) + O(V) (visited array) + O(H) (recursion stack, worst case H = V) ≈ O(V + E)
    bool dfs(int node, int parent, vector<int> adj[], vector<bool> &visited) {
        visited[node] = true;

        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                if (dfs(neigh, node, adj, visited))
                    return true;
            }
            else if (neigh != parent) { // visited and not parent → cycle
                return true;
            }
        }
        return false;
    }

    // BFS cycle detection
    bool isCycleBFS(int V, vector<vector<int>> &edges) {
        vector<int> adj[V];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfs(i, adj, visited))
                    return true;
            }
        }
        return false;
    }

    // DFS cycle detection
    bool isCycleDFS(int V, vector<vector<int>> &edges) {
        vector<int> adj[V];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges1 = {{0,1}, {1,2}, {2,0}, {2,3}};
    int V1 = 4;

    cout << "BFS Cycle Detection: " 
         << (sol.isCycleBFS(V1, edges1) ? "Cycle Found" : "No Cycle") << "\n";

    cout << "DFS Cycle Detection: " 
         << (sol.isCycleDFS(V1, edges1) ? "Cycle Found" : "No Cycle") << "\n";

    return 0;
}
