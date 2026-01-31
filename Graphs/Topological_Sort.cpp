// Implementing Topological Sort using Kahn's Algorithm

#include <bits/stdc++.h>
using namespace std ; 

vector <int> toposort(vector <vector <int>> adj, int V){
    
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
    return topo ; 
}

// works only for DAGs - Directed Acyclic Graphs
// Time : O(V + E)
// Space : ~ O(V)


// Intiution : 
// for a DG 1 -> 2 -> 3 -> 4 -> 5 the topo sort is  1 2 3 4 5 
// when dfs for a node is complete push it in the stack this way the node visited at last whose dfs is completed first, here 5, is stored at the bottom of the stack 
// now the stack contains 5 4 3 2 1 with 1 on top . now print the stack from top to bottom and we get 1 2 3 4 5 the topo sort