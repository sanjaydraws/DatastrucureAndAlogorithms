#include <bits/stdc++.h>

using namespace std;

void shortestPathBFS(int src, int dest, vector<vector<int>>& adj, int n) {
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]){
            if(dist[v] == INT_MAX){
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    if(dist[dest] == INT_MAX){
        cout<<"No Path Exist from" << src << "to"<< dest;
        return;
    }
    vector<int> path;
    for(int at = dest; at!=-1; at = parent[at]){
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    cout<<"shortest path length "<<dist[dest]<<"\n";
    cout<<"path : ";
    for(int node: path) cout<<node<< " ";

}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    adj[0] = {1, 4};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {2, 5};
    adj[4] = {0, 5};
    adj[5] = {3, 4};

    int src = 0, dest = 5;
    shortestPathBFS(src, dest, adj, n);
}
