

// Time Complexity:  O((V + E) log V)
// Space Complexity: O(V + E)
//
#include <bits/stdc++.h>
using namespace std;

void dijkstra(int n, vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src}); // {distance, node}

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue; // Skip outdated entries

        for (auto [v, wt] : adj[u]) {
            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    // Print final distance array
    cout << "Distance array from source " << src << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "dist[" << i << "] = ";
        if (dist[i] == INT_MAX) cout << "INF";
        else cout << dist[i];
        cout << "\n";
    }
}

int main() {
    int n = 6;
    vector<vector<pair<int, int>>> adj(n);

    // Directed weighted graph
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});
    adj[3].push_back({4, 3});

    int src = 0;
    dijkstra(n, adj, src);

    return 0;
}
/*
to 1: 0 → 1 (cost 2)

to 2: 0 → 2 (cost 2)

to 3: 0 → 1 → 3 (2 + 5 = 7)

to 4: 0 → 2 → 4 (2 + 6 = 8)

to 7: 0 → 2 → 4 → 7 (2 + 6 + 1 = 9)

to 6: 0 → 2 → 4 → 7 → 6 (2 + 6 + 1 + 2 = 11)

to 5: 0 → 1 → 3 → 5 (2 + 5 + 4 = 11)
*/