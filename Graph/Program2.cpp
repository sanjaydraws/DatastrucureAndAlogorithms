

// Graph implementation
//2. By Adjaceancy list (using map,list,set)

// SC
// O(V+E) - A. 
// O(V2) - w.c

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Graph {
public:
    unordered_map<int, vector<int>> adjList;
    unordered_map<int, vector<pair<int, int>>> adjList2;

    // For unweighted graph
    void addEdge(int u, int v, bool direction) {
        adjList[u].push_back(v);
        if (direction == 0) {
            adjList[v].push_back(u);
        }
    }

    void printAdjacencyList() {
        for (auto node : adjList) {
            cout << node.first << " -> ";
            for (auto neighbour : node.second) {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    // For weighted graph
    void addEdgeWithWeight(int u, int v, int weight, bool direction) {
        adjList2[u].push_back({v, weight});
        if (direction == 0) {
            adjList2[v].push_back({u, weight});
        }
    }

    void printAdjacencyList2() {
        for (auto node : adjList2) {
            cout << node.first << " -> ";
            for (auto neighbour : node.second) {
                cout << "{" << neighbour.first << ", " << neighbour.second << "} ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g1;
    g1.addEdge(0, 1, 0);
    g1.addEdge(1, 2, 0);
    g1.addEdge(0, 2, 0);
    cout << "\nUndirected Unweighted Graph:\n";
    g1.printAdjacencyList();

    Graph g2;
    g2.addEdge(0, 1, 1);
    g2.addEdge(1, 2, 1);
    g2.addEdge(0, 2, 1);
    cout << "\nDirected Unweighted Graph:\n";
    g2.printAdjacencyList();

    Graph g3;
    g3.addEdgeWithWeight(0, 1, 5, 1);
    g3.addEdgeWithWeight(1, 2, 8, 1);
    g3.addEdgeWithWeight(0, 2, 6, 1);
    cout << "\nDirected Weighted Graph:\n";
    g3.printAdjacencyList2();

    return 0;
}



/**
2->1, 0, 
1->0, 2, 
0->1, 2, 


1->2, 
0->1, 2, 

1->{2, 2}
0->{1, 1}{2, 2}
*/
