//https://leetcode.com/problems/course-schedule/description/
//207. Course Schedule

#include <bits/stdc++.h>
using namespace std;

//Approach A: Kahn’s Algorithm (BFS / Indegree)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        for (auto &p : prerequisites) {
            int a = p[0], b = p[1];   // b → a (to take 'a', you need 'b' first)
            adj[b].push_back(a);
            indeg[a]++;  // increase indegree of 'a'
        }

        // Push all courses with no prerequisites (indegree 0) into queue
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (indeg[i] == 0) q.push(i);

        int taken = 0; // number of courses we are able to take
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            taken++;

            // Reduce indegree of all neighbors (dependent courses)
            for (int v : adj[u]) {
                if (--indeg[v] == 0) // if indegree becomes 0, push into queue
                    q.push(v);
            }
        }

        // If we are able to take all courses → return true
        // Otherwise → there is a cycle
        return taken == numCourses;
    }
};

/*
Time Complexity: O(V + E)
    - Building the adjacency list: O(E)
    - BFS traversal over all nodes and edges: O(V + E)
    where V = numCourses, E = prerequisites.size()

Space Complexity: O(V + E)
    - Adjacency list: O(E)
    - Indegree array: O(V)
    - Queue storage: up to O(V)
*/

//Approach B: DFS + Recursion Stack (Cycle Detection)
/*
class Solution {
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& st) {
        st[u] = 1; // visiting
        for (int v : adj[u]) {
            if (st[v] == 1) return true;          // cycle
            if (st[v] == 0 && dfs(v, adj, st)) return true;
        }
        st[u] = 2; // done
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites) adj[p[1]].push_back(p[0]);
        vector<int> st(numCourses, 0);
        for (int i = 0; i < numCourses; ++i)
            if (st[i] == 0 && dfs(i, adj, st)) return false;
        return true;
    }
};

*/