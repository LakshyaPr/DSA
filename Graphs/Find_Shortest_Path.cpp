#include<bits/stdc++.h>
using namespace std;
void reverseVector(vector<int> & v){
    int s =  0 ; int e = v.size() - 1; 
    while (s < e){
        swap(v[s++], v[e--]) ; 
        
    }
}
vector<int> printShortestPath(vector <vector <pair<int, int>>> adj, int V , int src, int target){
    set<pair<int, int>> st ; 
    vector<int> dist(V, 1e9) ; 
    vector<int> parent(V) ; 
    for (int i = 0 ; i < V ; i++){
        parent[i] = i ; 
    }
    st.insert({0, src}) ; 
    dist[src] = 0 ; 
    while (!st.empty()){
        auto currnode = *st.begin() ; 
        int node = currnode.second ; 
        int dis = currnode.first ; 
        st.erase(currnode) ; 
        for (auto it : adj[node]){
            int adnode = it.first ; 
            int wt = it.second ; 
            if (dist[adnode] > dis+ wt){
                if (dist[adnode] != 1e9){
                    st.erase({dist[adnode], adnode}) ; 
                }
                dist[adnode] = dis + wt ; 
                st.insert({dist[adnode], adnode}) ; 
                parent[adnode] = node ; 
            }
        }
    }
    if (parent[target] == target) return {-1} ; 
    vector <int> res ; 
    int node = target ; 
    while (parent[node] != node){
        res.push_back(node) ; 
        node = parent[node] ; 
    }
    res.push_back(src) ; 
    reverseVector(res) ; 
    return res ; 
}

int main()
{   
vector<vector<pair<int,int>>> adj = {
    {},                        
    { {2,2}, {4,1} },          
    { {1,2}, {3,4}, {5,5} },    
    { {4,3}, {2,4}, {5,1} },    
    { {1,1}, {3,3} },           
    { {2,5}, {3,1} }            
};
    vector <int> dist = printShortestPath(adj, 6,1,5) ; 
    for (int i : dist ){
        cout << i << " " ; 
    }



    return 0;

}


// Time : O(E logV)