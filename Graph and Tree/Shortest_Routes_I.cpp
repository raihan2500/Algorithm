#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 10;
int n, m;
vector<pair<int, int>> graph[N];
vector<int> weight(N, INF);
int vis[N];

void dijkstra(int vertex = 1){

    set<pair<int, int>> s;
    s.insert({0, vertex});
    weight[vertex] = 0;

    while(!s.empty()){
        vertex =(*s.begin()).second;
        s.erase(s.begin());
        if(vis[vertex])continue;
        vis[vertex] = true;
        for(auto child : graph[vertex]){
            int v = child.first;
            int wt = child.second;

            if(weight[vertex] + wt < weight[v]){
                weight[v] = weight[vertex] + wt;
                s.insert({weight[v], v});
            }
        }
    }
}

int32_t main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back({y, z});
    }
    dijkstra(1);
    
    for(int i = 1; i <= n; i++)cout << weight[i] <<" ";
}