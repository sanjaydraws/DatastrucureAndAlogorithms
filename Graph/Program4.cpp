

// Graph implementation
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

template <typename T>
class Graph {
public:
    unordered_map<T, vector<T>> adjList;

    void addEdge(T u, T v, bool direction) {
        // direction 0 -> undirected
        // direction 1 -> directed
        adjList[u].push_back(v);
        if (direction == 0) {
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList() {
        for (auto node : adjList) {
            cout << node.first << "-> ";
            for (auto neighbour : node.second) {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    // BFS - T.C: O(V + E), S.C: O(V)
    void bfs(T src, unordered_map<T, bool>& visited) {
        queue<T> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            T frontNode = q.front();
            q.pop();
            cout << frontNode << ", ";

            for (auto neighbour : adjList[frontNode]) {
                if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    // DFS
    void dfs(T src, unordered_map<T, bool>& visited) {
        cout << src << ", ";
        visited[src] = true;

        for (auto neighbour : adjList[src]) {
            if (!visited[neighbour]) {
                dfs(neighbour, visited);
            }
        }
    }
};

int main() {
    Graph<int> g1;

    int n = 5;
    g1.addEdge(0, 1, 0);
    g1.addEdge(1, 3, 0);
    g1.addEdge(0, 2, 0);
    g1.addEdge(2, 4, 0);

    g1.printAdjacencyList();

    cout << "\nPrinting BFS traversal:\n";
    unordered_map<int, bool> visited1;
    for (int i = 0; i < n; i++) {
        if (!visited1[i]) {
            g1.bfs(i, visited1);
        }
    }

    cout << "\nPrinting DFS traversal:\n";
    unordered_map<int, bool> visited2;
    for (int i = 0; i < n; i++) {
        if (!visited2[i]) {
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
/*
| Representation       | Algorithm | **Time Complexity** | **Extra Space (Traversal)**         | **Graph Storage** | **Total Space Complexity** |
| -------------------- | --------- | ------------------- | ----------------------------------- | ----------------- | -------------------------- |
| **Adjacency List**   | BFS       | O(V + E)            | O(V) – queue + visited\[]           | O(V + E)          | **O(V + E)**               |
| **Adjacency List**   | DFS       | O(V + E)            | O(V) – stack/recursion + visited\[] | O(V + E)          | **O(V + E)**               |
| **Adjacency Matrix** | BFS       | O(V²)               | O(V) – queue + visited\[]           | O(V²)             | **O(V²)**                  |
| **Adjacency Matrix** | DFS       | O(V²)               | O(V) – stack/recursion + visited\[] | O(V²)             | **O(V²)**                  |

*/