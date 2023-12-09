

// Graph implementation
//2. By Adjaceancy list (using map,list,set)

// SC
// O(V+E) - A.C
// O(V2) - w.c
#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

class Graph{
public:
   unordered_map<int,list<int>> adjList;
   unordered_map<int, list<pair<int,int>>> adjList2;
   void addEdge(int u, int v, bool direction){
       // direction  0  -> undirected graph
       // direction 1 -> directed graph
       adjList[u].push_back(v);
       if(direction ==0){
           // undirected edge
           // create an edge from v to u
           adjList[v].push_back(u);
        }
    }

    void printAdjacencyList(){
        for(auto node:adjList){
            cout<<node.first<<"->";
            for(auto neighbour:node.second){
                  cout<<neighbour<<", ";
            }
            cout<<endl;
        }
    }

    void addEdgWithWeight(int u, int v,int weight,bool direction){
        adjList2[u].push_back({v,weight});
        // create an edge from v to u
        if(direction == 0){
            // create an edge from u to v
            adjList2[v].push_back({u,weight});
        }
    }
    void printAdjacencyList2(){
        for(auto node:adjList2){
            cout<<node.first<<"->";
            for(auto neighbour:node.second){
                  cout<<"{"<<neighbour.first<<", "<<neighbour.first<<"}";
            }
            cout<<endl;
        }
    }


};



   

int main() {
  Graph g1;
  // undirected input
  g1.addEdge(0,1,0);
  g1.addEdge(1,2,0);//adding undirectional edge
  g1.addEdge(0,2,0);
  cout<<endl;
  g1.printAdjacencyList();
  cout<<endl;
  
  // directed input
  Graph g2;
  g2.addEdge(0,1,1);
  g2.addEdge(1,2,1); // adding directional edge
  g2.addEdge(0,2,1);
  cout<<endl;
  g2.printAdjacencyList();  

  // directed weighted graph

    Graph g3;
    g3.addEdgWithWeight(0,1,5,1);
    g3.addEdgWithWeight(1,2,8,1);
    g3.addEdgWithWeight(0,2,6,1);
    cout<<endl;
    g3.printAdjacencyList2();
  
  return 0;
}


/**
 2->1, 0, 
1->0, 2, 
0->1, 2, 


1->2, 
0->1, 2,


*/
