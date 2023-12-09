

// Graph implementation
//2. By Adjaceancy list (using map,list,set)
// make generic type

#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>

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


};



   

int main() {
  Graph<char> g1;
  // undirected input
  g1.addEdge('a','b',0);
  g1.addEdge('b','c',0);//adding undirectional edge
  g1.addEdge('a','c',0);
  cout<<endl;
  g1.printAdjacencyList();
  cout<<endl;
  
  
  return 0;
}


/**
c->b, a, 
b->a, c, 
a->b, c, 
*/