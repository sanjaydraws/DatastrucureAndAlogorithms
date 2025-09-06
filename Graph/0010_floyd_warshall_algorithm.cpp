/*
Floyd–Warshall Algorithm works for:
 -to find All-Pairs Shortest Path (APSP)
 -Handles Negative Edges
 -works for both Directed / Undirected
 -Negative cycle detection possible by checking diagonal | dist[i][i] < 0 → negative cycle exists.
*/

//T.C = O(n³)

// S.C = O(n² + V + E) ≈ O(n²)
#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int,int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction = 1) {
        adjList[u].push_back({v, wt});
        if(direction == 0) {
            adjList[v].push_back({u, wt});
        }
    }

    void floydWarshal(int n) {
        // Step 1: Initialize dist matrix with INF
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        // Step 2: Diagonal = 0
        for(int i=0; i<n; i++) {
            dist[i][i] = 0;
        }

        // Step 3: Fill initial graph edges
        for(auto a: adjList) {
            for(auto b: a.second) {
                int u = a.first;
                int v = b.first;
                int wt = b.second;
                dist[u][v] = wt;
            }
        }

        // Step 4: Main logic (triple loop)
        for(int helper = 0; helper < n; helper++) {
            for(int src = 0; src < n; src++) {
                for(int dest = 0; dest < n; dest++) {
                    if(dist[src][helper] != 1e9 && dist[helper][dest] != 1e9) {
                        dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                    }
                }
            }
        }

        // Step 5: Print result
        cout << "All Pairs Shortest Path Matrix:\n";
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(dist[i][j] == 1e9) cout << "INF ";
                else cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;

    g.addEdge(0,1,5,1);
    g.addEdge(0,3,10,1);
    g.addEdge(1,2,3,1);
    g.addEdge(2,3,1,1);

    g.floydWarshal(4);  // n = number of vertices

    return 0;
}
