

// Graph implementation
//1. By Adjaceany Matrix
//2. By Adjaceancy list


//1. By Adjaceany Matrix
// Measure	Complexity
// Time Complexity	O(n^2)
// Space Complexity	O(n^2)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int isUndirected = 1;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    // Creating an n x n matrix initialized with 0
    vector<vector<int>> adj(n, vector<int>(n, 0));

    int e;
    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        // Mark 1 for the given edge
        adj[u][v] = 1;

        // If undirected, also mark reverse
        if (isUndirected) {
            adj[v][u] = 1;
        }
    }

    // Printing the adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


/**
 Enter the number of nodes
3
Enter the number of edges
6
0 1
1 0
2 1
1 2
0 2
2 0

0 1 1
1 0 1
1 1 0
*/