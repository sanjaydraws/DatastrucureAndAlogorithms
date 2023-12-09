

// Graph implementation

#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>

using namespace std;
template <typename T>
class Graph{
public:
   unordered_map<T,list<T>> adjList;
   void addEdge(T u, T v, bool direction){
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



    //T.C : O(V + E)
    //S.C : O(V)
    // linear T.C
    void bfs(T src,unordered_map<T,bool>& visited){
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            T frontNode = q.front();
            q.pop();
            cout<<frontNode<<", ";

            // insert neighbours
            for(auto neighbour: adjList[frontNode]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void dfs(T src,unordered_map<T,bool>& visited){
        cout<<src<<", ";
        visited[src] = true;
        for(auto neighbour:adjList[src]){
            if(!visited[neighbour]){
                dfs(neighbour,visited);
            }
        }
    }

};



   

int main() {
  Graph<int> g1;

//   int n = 8;  
//   g1.addEdge(0,1,0);
//   g1.addEdge(1,2,0);
//   g1.addEdge(1,3,0);
//   g1.addEdge(3,5,0);
//   g1.addEdge(3,7,0);
//   g1.addEdge(7,6,0);
//   g1.addEdge(7,4,0);

  // another graph example 
  int n = 5;  
  g1.addEdge(0,1,0);
  g1.addEdge(1,3,0);
  g1.addEdge(0,2,0);
  g1.addEdge(2,4,0);
  
  g1.printAdjacencyList();

  cout<<endl;
  cout << "Printing BFS traversal" << std::endl;
  unordered_map<int,bool> visited1;
  //   g1.bfs(0);
  for(int i = 0; i<n;i++){
      if(!visited1[i]){
          g1.bfs(i, visited1);
      }
  }

  // DFS
  cout<<endl<<"Printing DFS traversal: "<<endl;
  unordered_map<int,bool> visited2;
  for(int i = 0; i<n; i++){
      if(!visited2[i]){
          g1.dfs(i, visited2);
      }
  }
  return 0;
}


/**
4->7, 
6->7, 
7->3, 6, 4, 
5->3, 
3->1, 5, 7, 
2->1, 
1->0, 2, 3, 
0->1, 

BFS starting from vertex 0:
0, 1, 2, 3, 5, 7, 6, 4, 

Printing DFS traversal:
0, 1, 2, 3, 5, 7, 6, 4,
*/

/**
 Output of second example
 4->2, 
2->0, 4, 
3->1, 
1->0, 3, 
0->1, 2, 

BFS starting from vertex 0:
0, 1, 2, 3, 4, 
Printing DFS traversal: 
0, 1, 3, 2, 4, 

*/