//BFS graph traversal 
// Its stands for breadth first traversal where we traverse all the nodes at the present level and then move on the next.

#include <bits/stdc++.h>
using namespace std ; 

void BFS(vector<vector <int>> &adj, vector <int> &vis, int node ){ 
    // queue is used to store the levels 
    queue <int> q ; 
    q.push(node) ; 
    vis [node] = 1 ; 
    while (!q.empty()){
        int curr_node = q.front() ; 
        q.pop() ; 
        cout << curr_node << " " ; // print the current node 
        for (auto it : adj[curr_node]){
            // we need to push it only if the node is not visited
            if (!vis[it]){
                vis[it] = 1 ; // marking the node as visited
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
// Time : O(V + 2E) , V as each vertex is checked once and 2E as each edge is traversed twice in an undirected graph
// Space : O(V) for queue and O(V) for vis array