

// Graph implementation
//1. By Adjaceany Matrix
//2. By Adjaceancy list


//1. By Adjaceany Matrix
// space comp : (O(n2)) //Avg case // because created 2d array
// O(v2) : AC
#include <iostream>
#include<vector>
using namespace std;

int main() {
  int n;
  cout<<"Enter the number of nodes"<<endl;
  cin>>n;
 
  vector<vector<int>> adj(n,vector<int>(n,0));
  int e;
  cout<<"Enter the number of edges"<<endl;
  cin>>e;
  for(int i = 0;i<e;i++){
    int u,v; 
    cin >> u >> v;
    // mark 1 in adjaceancy matrix
    adj[u][v] = 1;
  }
    // printing
    for(int i = 0;i<n;i++){
      for(int j = 0;j<n;j++){
        cout<<adj[i][j]<<" ";
      }
      cout<<endl;
    }
  
  return 0;
}


/**
 Enter the number of nodes
3
Enter the number of edges
6
0 1
1 0
2 1
1 2
0 2
2 0

0 1 1
1 0 1
1 1 0
*/