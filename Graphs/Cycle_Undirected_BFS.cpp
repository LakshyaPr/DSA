bool BFS(vector<vector <int>> &adj, vector <int> &vis, int node ){ 
    // queue is used to store the levels 
    queue <pair<int, int>> q ; 
    q.push({node, -1 }) ; 
    vis [node] = 1 ; 
    while (!q.empty()){
       auto curr_node = q.front() ; 
        int cnode = curr_node.front ; 
        int parent = curr_node.second ; 
        q.pop() ; 
        
        for (auto it : adj[cnode]){
            // we need to push it only if the node is not visited
            if (!vis[it]){
                vis[it] = 1 ; // marking the node as visited
                q.push({it, cnode}) ;           
            }
            else if (it != parent) return true ; 
        }
    }
    return false ; 
}


bool checkcycle (vector<vector <int>> &adj, int V){
    vector <int> vis (V, 0) ; 
    for (int i = 0 ; i < V ; i++){
        if (!vis[i]){
            if (BFS (adj, vis, i)) return true ; 
        }
    }
    return false ; 
}


// Time : O(V + 2E), same as DFS, the checkcycle for loop does not increase as it only runs for unvis nodes
// Space : O(V) for vis array and O(V) for recursion stack