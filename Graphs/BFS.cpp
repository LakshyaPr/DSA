//BFS graph traversal 

#include <bits/stdc++.h>
using namespace std ; 

void BFS(vector<vector <int>> &adj, vector <int> &vis, int node ){ 
    queue <int> q ; 
    q.push(node) ; 
    vis [node] = 1 ; 
    while (!q.empty()){
        int curr_node = q.front() ; 
        q.pop() ; 
        cout << curr_node << " " ; 
        for (auto it : adj[curr_node]){
            if (!vis[it]){
                vis[it] = 1 ; 
                q.push(it) ; 
                

            }
        }
    }
}


int main (){
    
    int V = 7 ; 
    vector<vector<int>> adj = {
        {1, 2},       
        {0, 3},        
        {0, 3, 4},     
        {1, 2, 5},     
        {2, 6},      
        {3},           
        {4}            
    };
    vector <int> vis(V+1, 0) ; 
    BFS(adj, vis, 0) ; 


    return 0 ; 
}