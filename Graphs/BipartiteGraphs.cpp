#include <bits/stdc++.h>
using namespace std ; 

// this is the BFS method to check if the graph is bipartite or not
bool bipart(vector<vector<int>>& adj, int V) {
    vector<int> col(V, -1);
    queue<int> q;

    for (int start = 0; start < V; start++) {
        if (col[start] != -1) continue;

        col[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int cnode = q.front();
            q.pop();

            for (auto it : adj[cnode]) {
                if (col[it] == -1) {
                    col[it] = !col[cnode];
                    q.push(it);
                }
                else if (col[it] == col[cnode]) {
                    return false;
                }
            }
        }
    }
    return true;
}

// Time : O(V + E) 
