// cycle detection in undirected graph





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

bool checkCyclicUsingBfs(int src, unordered_map<int,bool>& visited) {
		queue<int> q;
		unordered_map<int,int> parent;
		
		q.push(src);
		visited[src] = true;
		parent[src] = -1;

		while(!q.empty()) {
			int frontNode = q.front();
			q.pop();

			for(auto nbr: adjList[frontNode]) {
				if(!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
					parent[nbr]=frontNode;
				}
				if(visited[nbr] && nbr != parent[frontNode]) {
						//cycle present
						return true;
				}
			}
		}
		return false;
	}
    //undirectional 
    bool checkCyclicUsingDfs(int src, unordered_map<int,bool>& visited, int parent) {
		visited[src] = true;

		for(auto nbr: adjList[src]) {
			if(!visited[nbr]) {
				bool checkNextAns = checkCyclicUsingDfs(nbr, visited, src);
				if(checkNextAns == true)
					return true;
			}
			if(visited[nbr] && nbr != parent) {
				//cycle present
				return true;
			}
		}
		return false;
	}
};



   

int main() {
  Graph<int> g1;
 
  int n = 5;

  // acyclic example  
  //   g1.addEdge(0,1,0);
  //   g1.addEdge(1,3,0);
  //   g1.addEdge(0,2,0);
  //   g1.addEdge(2,4,0);
  
  //cyclic example
  g1.addEdge(0,1,0);
  g1.addEdge(1,2,0);
  g1.addEdge(2,3,0);
  g1.addEdge(3,4,0);
  g1.addEdge(4,0,0);

  g1.printAdjacencyList();
  cout<<endl;

  bool ans = false;
  unordered_map<int, bool> visited;
  for(int i=0; i<n; i++) {
		if(!visited[i]) {
			 ans = g1.checkCyclicUsingBfs(i,visited);
			if(ans == true)
				break;
		}
	}

	if(ans == true) 
		cout << "Cycle is Present" << endl;
	else
		cout << "Cycle Absent" << endl;

    bool ansDfs = false;
    unordered_map<int, bool> visitedDfs;
    for(int i=0; i<n; i++) {
		if(!visited[i]) {
			 ansDfs = g1.checkCyclicUsingDfs(i,visitedDfs,-1);
			if(ansDfs == true)
				break;
		}
	}

	if(ansDfs == true) 
		cout << "Cycle is Present" << endl;
	else
		cout << "Cycle Absent" << endl;

 
  return 0;
}

/**
 4->3, 0, 
3->2, 4, 
2->1, 3, 
1->0, 2, 
0->1, 4, 

Cycle is Present
Cycle is Present
 
*/