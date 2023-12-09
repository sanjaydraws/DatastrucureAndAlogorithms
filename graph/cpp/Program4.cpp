// Traversal
//BFS: Breadth first search
//DFS: Depth First Search


//BFS: Breadth first search
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
    void bfs()



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

  
  return 0;
}


/**

*/
