#include <bits/stdc++.h>
using namespace std ; 

void DFS(vector<vector<int>> &adj, vector <int> &vis , int node ){
    vis[node] = 1 ; 
    cout << node << " " ; 
    for (auto it : adj[node]){
        if (!vis[it]){
            DFS(adj, vis, it) ; 
        }
    }
}


// Time : O(V + 2E) , V as each vertex is checked once and 2E as each edge is traversed twice in an undirected graph
// Space : O(V) for queue and O(V) for vis array