// Dijkstra's algo is used to find the shortest distance from src node to all other nodes 
// Only used in weighted graphs with non -ve weights
// Using Priority Queue 
#include<bits/stdc++.h>
using namespace std;
vector <int> djk(vector <vector<pair<int, int>>> adj, int start, int V){
    priority_queue<
    pair<int,int>,
    vector<pair<int,int>>,
    greater<pair<int,int>>
> pq;

    vector<int> dist(V, 1e9) ; 
    dist[start] = 0 ;
    pq.push({0, start}) ; 
    while (!pq.empty()){
        int dis = pq.top().first; 
        int node = pq.top().second; 
        pq.pop() ; 
        for (auto it : adj[node]){
            int wt = it.second ; 
            int neighbour = it.first ; 
            if (dis + wt < dist[neighbour]){
                dist[neighbour] = dis + wt ;
                pq.push({dist[neighbour ], neighbour}) ; 
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
    vector <int> dist = djk(adj, 6, 7) ; 
    for (int i : dist ){
        cout << i << " " ; 
    }



 return 0;

}
// Time Complexity:
// - Push into min-heap: O(log V), done at most E times → O(E log V)
// - Pop (extract-min): O(log V), done at most E times → O(E log V)
// - Edge relaxation: each edge processed once → O(E)
// - Overall Time Complexity: O(E log V)

