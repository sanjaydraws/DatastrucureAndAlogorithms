


/**
 * 
 * Bellman–Ford works for:

Negative edge weights ✅ (Dijkstra fails here)

Directed & Undirected graphs ✅ (but negative edge in undirected → always negative cycle)

Single Source Shortest Path ✅ (one source → shortest distance to all nodes)

 */
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <limits.h>
using namespace std;


/**
 * 
 * Time: O(V × E)
(V = vertices, E = edges)

Space: O(V)
 */
class Graph {
public:
    unordered_map<int, list<pair<int,int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction = 1) {
        adjList[u].push_back({v, wt});
        if(direction == 0) {
            adjList[v].push_back({u, wt});
        }
    }

    void bellmanFord(int n, int src) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Relax all edges (n-1) times
        for(int i = 1; i < n; i++) {
            for(auto &edge : adjList) {
                int u = edge.first;
                for(auto &nbr : edge.second) {
                    int v = nbr.first, wt = nbr.second;
                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        // Check for negative weight cycle
        for(auto &edge : adjList) {
            int u = edge.first;
            for(auto &nbr : edge.second) {
                int v = nbr.first, wt = nbr.second;
                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                    cout << "Negative Cycle Present\n";
                    return;
                }
            }
        }

        cout << "Shortest Distances from source " << src << ":\n";
        for(int i = 0; i < n; i++) {
            if(dist[i] == INT_MAX) cout << i << " : INF\n";
            else cout << i << " : " << dist[i] << "\n";
        }
    }
};

int main() {
    Graph g;
    g.addEdge(0,1,-1,1);
    g.addEdge(0,2,4,1);
    g.addEdge(1,2,3,1);
    g.addEdge(1,3,2,1);
    g.addEdge(1,4,2,1);
    g.addEdge(3,2,5,1);
    g.addEdge(3,1,1,1);
    g.addEdge(4,3,-3,1);

    g.bellmanFord(5, 0);  // source = 0

    /**
    g.addEdge(0, 1, 1, 1);
g.addEdge(1, 2, -1, 1);
g.addEdge(2, 3, -1, 1);
g.addEdge(3, 1, -1, 1);  // Negative cycle

    */
    return 0;
}
