#include <bits/stdc++.h>
using namespace std ; 

void DFS(vector<vector<int> &adj, vector <int> &vis , int node ){
    vis[node] = 1 ; 
    cout << node << " " ; 
    for (auto it : adj[node]){
        if (!vis[it]){
            dfs(adj, vis, it) ; 
        }
    }
}