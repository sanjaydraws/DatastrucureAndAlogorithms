//Prim's Algo

/*
Spanning Tree (ST)

For a connected graph, undirected graph, a spanning tree is a subgraph that:
should not be disconnected grpah
1. Includes all the nodes

2. Has no cycles (so it’s a tree)

 -> In other words: if there are n nodes → it has exactly n-1 edges and all nodes are connected.

Minimum Spanning Tree (MST)

If the graph has weights on edges, an MST is a spanning tree with the smallest total edge weight.

Example applications: connecting computers, laying cables, building roads at minimum cost.
*/
//Applications: Network design, wiring, road/railway optimization, clustering, etc.


/**
 * 
 * 
 * Nodes = {1,2,3}
Edges = {(1-2, 5), (2-3, 2), (1-3, 4)}
Possible spanning trees:

{(1-2), (2-3)} → total weight = 5+2 = 7

{(1-3), (2-3)} → total weight = 4+2 = 6 ✅ (MST)

{(1-2), (1-3)} → total weight = 5+4 = 9


 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m;
    cin >> n >> m;

    // Adjacency list: adj[u] = vector of (neighbor, weight)
    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u , v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // undirected graph
    }

    // Track if node is included in MST
    vector<bool> inMST(n + 1, false);

    // Distance array: minimum edge weight to connect a node to MST
    vector<long long> dist(n + 1, 1e18); 

    // Min-heap priority queue: (weight, node)
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    int start = 1;  // starting node for Prim's algorithm
    pq.push({0, start});  // start node with edge weight 0
    dist[start] = 0;

    long long total = 0; // total weight of MST

    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();

        if(inMST[u]) continue; // skip if node already in MST

        inMST[u] = true;   // include node in MST
        total += d;        // add edge weight to total MST cost

        // iterate over all neighbors of u
        for(auto [v, w] : adj[u]){
            // if neighbor not in MST and edge weight is smaller than current
            if(!inMST[v] && w < dist[v]){
                dist[v] = w;       // update minimum edge weight
                pq.push({dist[v], v}); // push into priority queue
            }
        }
    }

    cout << "MST total weight: " << total << "\n";

    return 0;
}

/*
Sample Input:
4 5
1 2 1
1 3 4
2 3 2
2 4 6
3 4 3

Expected Output:
MST total weight: 6

Explanation of MST edges:
1-2 (weight 1)
2-3 (weight 2)
3-4 (weight 3)

Time Complexity (T.C):
- Each edge can be pushed into the priority queue at most once.
- Pushing/popping from priority queue takes O(log n)
- Total complexity: O((n + m) * log n)

Space Complexity (S.C):
- Adjacency list: O(n + m)
- dist array: O(n)
- inMST array: O(n)
- Priority queue: O(n)
- Total space: O(n + m)
*/
