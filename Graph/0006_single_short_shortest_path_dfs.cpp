
// single short shortest distance in directed graph
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Graph{
  public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u , int v, int wt, bool direction){
        if(direction == 1){
            // directed
            adj[u].push_back({v,wt});
        }else{
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
    }
    void printAdjList(){
        for(auto i : adj){
            cout<< i.first<<" : {";
            for(auto j: i.second){
                cout<<"("<<j.first<<" ,"<<j.second<<"), ";
            }
            cout<<"} "<<endl;
        }
    }
    void topoOrderDfs(int src, stack<int>& topo,unordered_map<int, bool> & visited){
        visited[src] = true;

        for(auto nbrPair: adj[src]){
            int nbrNode = nbrPair.first;
            // int nbrDist = nbrPair.second;
            if(!visited[nbrNode]){
                topoOrderDfs(nbrNode, topo,visited);
            }
        }
        topo.push(src);
    }

    void shortestPathDfs( stack<int>& topoOrder, int n){
         vector<int> dist(n, INT_MAX);
        // initially set dist for src  
        int src = topoOrder.top(); // src is independent
        topoOrder.pop();
        dist[src] = 0;

        // update neighbor for this src
        for(auto nbrPair: adj[src]){
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;
            if(dist[src] + nbrDist < dist[nbrNode]){
                dist[nbrNode] = dist[src] + nbrDist;
            }
        }
        // apply the same for remaining node
        while(!topoOrder.empty()){
            int src = topoOrder.top();
            topoOrder.pop();
            for(auto nbrPair: adj[src]){
                int nbrNode = nbrPair.first;
                int nbrDist = nbrPair.second;
                if(dist[src] + nbrDist < dist[nbrNode]){
                    dist[nbrNode] = dist[src] + nbrDist;
                }
            }
        }
        // print dist array
        cout<<"Printing distance array " <<endl;
        for(auto i:dist){
            cout<< i << " ";
        }
        
    }
    
};
int main(){
    Graph g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(2, 1, 2, 1);
    g.addEdge(1, 3, 3, 1);
    g.addEdge(2, 3, 5, 1);
    g.addEdge(2, 4, 6, 1);
    g.addEdge(4, 3, 1, 1);

    g.printAdjList();
    stack<int> topoOrder;
    int src = 0;
    unordered_map<int, bool> visited;
    g.topoOrderDfs(src, topoOrder, visited);

    /*
    cout<<"Printing topo order" <<endl;
    while(!topoOrder.empty()){
        cout<<topoOrder.top()<< " ";
        topoOrder.pop();
    }
    */
    int n = 5;
    g.shortestPathDfs(topoOrder, n);
}