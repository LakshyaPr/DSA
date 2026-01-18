bool  DFS(vector<vector<int>> &adj, vector <int> &vis , int node, int parent){
    vis[node] = 1 ; 
    cout << node << " " ; 
    for (auto it : adj[node]){
        if (!vis[it]){
            if (DFS(adj, vis, it, node)) return true  ; 
        }
        else if (it != parent){
            return true ; 
        }
    }
    return false ; 
}


bool checkcycle (int V , vector<vector<int>> &adj){
    vector <int> vis (V+1, 0) ; 
    for (int i = 0 ; i < V ; i++){
        if (!vis[i]){
            if (DFS(adj, vis, i, -1)) return true ; 
        }
    }
    return false ; 
}


// Time : O(V + 2E), same as DFS, the checkcycle for loop does not increase as it only runs for unvis nodes
// Space : O(V) for vis array and O(V) for recursion stack