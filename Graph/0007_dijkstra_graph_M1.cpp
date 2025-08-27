
// Dijkstra Algo


/*
🔹 Limitations of Dijkstra

1.  Does not work with negative weights
  ->If graph has negative edge, Dijkstra gives wrong answer.
  ->Use Bellman-Ford instead.

2  Cannot handle negative weight cycles
  ->If a cycle reduces cost again and again, Dijkstra fails.

3.  Single source only
   ->Works from one start node.
   ->For all-pairs shortest path → use Floyd-Warshall.

4.  Slow for dense graphs
   -> Too many edges → time becomes O(V²).

5.  Not good for dynamic graphs
    -> If edge weights keep changing, you must run it again.
*/
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
    // Function: Dijkstra's Algorithm to find shortest distance from src to dest
    // Time Complexity: O((V + E) * logV)  [because of set operations]
    // Space Complexity: O(V + E) [adj list + dist array + set]

    void dijkstraShortestDistance(int n , int src, int dest){
        // Step 1: Distance array initialize with infinity
        // n+1 size because nodes start from 1 (1-based indexing)
        vector<int> dist(n + 1, INT_MAX);

        // Step 2: Min-heap like behavior using set (distance, node)
        // set keeps the smallest distance node at begin()
        set<pair<int, int>> st; // {distance, node}

        // Step 3: Source distance = 0
        dist[src] = 0;
        st.insert({0, src}); // initially only src in set

        // Step 4: Process nodes until set becomes empty
        while(!st.empty()){
            // extract the node with minimum distance
            auto topElement = st.begin(); 
            pair<int, int> topPair = *topElement;
            int topDist = topPair.first;   // current known shortest distance
            int topNode = topPair.second;  // current node
            st.erase(st.begin());          // remove this node from set

            // Step 5: Relaxation of all neighbors
            // iterate over all adjacent nodes of current node
            for(pair<int, int> nbrPair: adj[topNode]){
                int nbrNode = nbrPair.first;   // neighbor node
                int nbrDist = nbrPair.second;  // edge weight

                // if going via topNode gives shorter distance to nbrNode
                if(topDist + nbrDist < dist[nbrNode]){

                    // Step 5a: If nbrNode already has an entry in set with old dist, remove it
                    auto previousEntry = st.find({dist[nbrNode], nbrNode});
                    if(previousEntry != st.end()){
                        st.erase(previousEntry);
                    }

                    // Step 5b: Update shortest distance
                    dist[nbrNode] = topDist + nbrDist;

                    // Step 5c: Push new pair into set
                    st.insert({dist[nbrNode], nbrNode});
                }
            }
        }

        // Step 6: Print final answer
        cout << endl;
        cout << "Shortest Distance from " << src 
             << " Node to " << dest 
             << " Node = " << dist[dest];
    }

    
};
int main(){
    Graph g;
    g.addEdge(1, 6, 14, 0);
    g.addEdge(1, 3, 9, 0);
    g.addEdge(1, 2, 7, 0);
    g.addEdge(2, 3, 10, 0);
    g.addEdge(2, 4, 15, 0);
    g.addEdge(3, 4, 11, 0);
    g.addEdge(6, 3, 2, 0);
    g.addEdge(6, 5, 9, 0);
    g.addEdge(5, 4, 6, 0);

    // g.printAdjList();
    

    /*
    cout<<"Printing topo order" <<endl;
    while(!topoOrder.empty()){
        cout<<topoOrder.top()<< " ";
        topoOrder.pop();
    }
    */
    int n = 6;
    int src = 6;
    int dest = 4;
    g.dijkstraShortestDistance(n, src, dest);
}