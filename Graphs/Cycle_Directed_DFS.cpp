// To Check is there is a cycle present in a Cyclic graph using DFS

#include <bits/stdc++.h>
using namespace std ; 

bool DFS(vector <vector<int>> &adj, vector <int> &vis, int node ){
    vis[node] = 2 ; // using value of vis 2 instead of making a new path vis vector
    for (auto it : adj[node]){
        if (!vis[it]){
            if (DFS(adj, vis, it)){
                return true ; 
            }
        }
        else if (vis[it] == 2){
            return true ; // cycle found !!
        }
    }
    vis[node] = 1 ; 
    return false ; // no cycle here !!
}

bool checkCycle(vector <vector<int>> &adj, int V){
    vector <int> vis(V, 0) ; 
    for (int i = 0 ; i < V; i++){
        if (!vis[i]){
            if (DFS(adj, vis , i)) return true ; 
        }
    }
    return false ; 
}


// TIME : O( V + E) not 2E as its a directed graph
// SPACE : O(V) just a vector vis with size V