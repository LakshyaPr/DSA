// Checking if the graph has a cycle using BFS (Kahn's Algo)

#include <bits/stdc++.h>
using namespace std ; 

bool toposort(vector <vector <int>> adj, int V){
    
    queue<int> q ; 
    vector <int> indegree(V, 0) ; 
    vector <int> topo ; 
    for (int i = 0 ; i < V ; i++){
        for (auto it : adj[i]){
            indegree[it] ++ ; 
        }
    }
    for (int i =0 ; i < V ; i ++){
        if (indegree[i] == 0 ){
            q.push(i) ; 
        }
    }
    
    while(!q.empty()){
        int node = q.front() ; 
        q.pop() ; 
        topo.push_back(node) ; 
        for (auto it : adj[node]){
            indegree[it ] -- ; 
            if (indegree[it] == 0){
                q.push(it) ; 
            }
        }
    }
    return (topo.size() == V? false : true ) ; 
}

// works only for DAGs - Directed Acyclic Graphs
// Time : O(V + E)
// Space : ~ O(V)