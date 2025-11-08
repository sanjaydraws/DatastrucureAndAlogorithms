class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int, int>>> adj(n);

        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j++){
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1]- points[j][1]);
                adj[i].push_back({j, w});
                adj[j].push_back({i, w});
            }
        }
        return prim(n, adj);
    }
    long long prim(int n, vector<vector<pair<int, int>>>& adj){
        vector<bool> inMST(n, false);
        vector<long long> dist(n, LLONG_MAX);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        dist[0] = 0;
        pq.push({0, 0});
        long long total = 0;
        while(!pq.empty()){
            auto [cost, u]  = pq.top();
            pq.pop();
            if(inMST[u]) continue;
            inMST[u] = true;
            total += cost;
            for(auto &[v, w]: adj[u]){
                if(!inMST[v] && w < dist[v]){
                    dist[v] = w;
                    pq.push({w, v});
                }
            }
        }
        return total;
    }
};