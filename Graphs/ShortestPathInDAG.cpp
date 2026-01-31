#include <bits/stdc++.h>
using namespace std ; 

// assuming the topo sort is given as input else get the topo sort using kahn's algo or dfs method
vector <int> shorty(vector <int> topo, int V , vector <vector <pair<int, int>> > adj){
    vector<int> dist(V, 1e9) ; 
    dist[6] = 0 ; 
    for (int i : topo ){
        for (auto it : adj[i] ){
            int node = it.first ; 
            int wt = it.second ;
            if (dist[i] != 1e9 && dist[node] > dist[i] + wt){
                dist[node ] = wt + dist[i] ; 
            } 
        }
    }
    return dist ; 
}

int main (){
    vector <int> topo = {6,5,4,2,0,1,3} ; 
    vector <vector <pair<int, int>>> adj = 
    {
        {{1,2}},
        {{3,1}},
        {{3,3}}, 
        {},
        {{0,3},{2,1}},
        {{4,1}},
        {{4,2},{5,3}}
        
    } ; 
    vector <int> dist = shorty(topo, 7,adj) ; 
    for (int i : dist){
        cout << i << " " ; 
    }
    return 0 ; 
}


//Time : O(V+E) v= nodes E = edges
//Space : O(V) for dist array