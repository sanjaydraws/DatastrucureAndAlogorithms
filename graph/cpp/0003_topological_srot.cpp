
//Topological Sort

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //  DFS APPROACH 
    void dfsHelper(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st) {
        visited[node] = true;
        for (int neigh : adj[node]) {
            if (!visited[neigh]) {
                dfsHelper(neigh, adj, visited, st);
            }
        }
        st.push(node); // Postorder push
    }

    vector<int> topoSortDFS(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsHelper(i, adj, visited, st);
            }
        }

        vector<int> topo;
        while (!st.empty()) {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }

    //BFS (Kahn's Algorithm) 
    vector<int> topoSortBFS(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);

        // Step 1: Calculate indegree
        for (int i = 0; i < V; i++) {
            for (int neigh : adj[i]) {
                indegree[neigh]++;
            }
        }

        // Step 2: Queue for nodes with indegree 0
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        // Step 3: Process queue
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        return topo;
    }
};

int main() {
    int V = 6;
    vector<int> adj[V];

    // Directed edges
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;

    // DFS-based Topological Sort
    vector<int> dfsOrder = obj.topoSortDFS(V, adj);
    cout << "Topological Order (DFS): ";
    for (int node : dfsOrder) cout << node << " ";
    cout << endl;

    // BFS-based Topological Sort (Kahn's Algorithm)
    vector<int> bfsOrder = obj.topoSortBFS(V, adj);
    cout << "Topological Order (BFS): ";
    for (int node : bfsOrder) cout << node << " ";
    cout << endl;

    return 0;
}

/*
------------------------- COMPLEXITY -------------------------

DFS Approach:
    Time Complexity: O(V + E)
        - Each vertex visited once.
        - Each edge explored once.
    Space Complexity: O(V) + O(V) recursion stack
        - visited array + recursion stack + output

BFS (Kahn's Algorithm):
    Time Complexity: O(V + E)
        - Each vertex enqueued/dequeued once.
        - Each edge processed once.
    Space Complexity: O(V)
        - indegree array + queue + output

