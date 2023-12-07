

// Graph implementation
//2. By Adjaceancy list (using map,list,set)

#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;

class Graph{
public:
   unordered_map<int,list<int>> adjList;
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


};



   

int main() {
  Graph g1;
  // undirected input
  g1.addEdge(0,1,0);
  g1.addEdge(1,2,0);
  g1.addEdge(0,2,0);
  cout<<endl;
  g1.printAdjacencyList();
  cout<<endl;
  
  // directed input
  Graph g2;
  g2.addEdge(0,1,1);
  g2.addEdge(1,2,1);
  g2.addEdge(0,2,1);
  cout<<endl;
  g2.printAdjacencyList();  
  
  return 0;
}


/**
 2->1, 0, 
1->0, 2, 
0->1, 2, 


1->2, 
0->1, 2,
*/