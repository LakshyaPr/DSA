#include<bits/stdc++.h>
using namespace std;

vector<int> djk(vector <vector <pair<int, int>>> adj, int V, int start){
    set<pair<int , int>> s ; 
    s.insert({0, start}) ; 
    vector<int> dist (V, 1e9 ) ;
    dist[start] = 0 ; 
    while (!s.empty()){
        auto it = *s.begin() ; 
        int node = it.second ; 
        int dis = it.first ; 
        s.erase(it) ; 
        for (auto i : adj[node]){
            int wt = i.second ; 
            int adnode = i.first ;  
            if (dist[adnode] > dis + wt){
                if (dist[adnode] != 1e9){
                    s.erase({dist[adnode], adnode}) ; 
                }
                dist[adnode] = dis + wt ; 
                s.insert({dist[adnode], adnode}) ; 
            }
        }
    } 
    return dist ; 
}

int main()
{   
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
    vector <int> dist = djk(adj, 7,6) ; 
    for (int i : dist ){
        cout << i << " " ; 
    }



    return 0;

}

// Time : 
// - set used is a red-black tree
// - Insertion : O(log V) 
// - Erase : O(logV)
// - Overall : Both done for all edges so O(E logV)
