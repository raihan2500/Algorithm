#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, m;
bool vis[N];
vector<int> dist(N, INF), par(N);
vector<vector<pair<int, int>>> graph(N);

void bfs(int src = 1){
    
    set<pair<int, int>> q;
    q.insert({0, src});
    dist[src] = 1;
    
    while(!q.empty()){
        src = q.begin()->second;
        q.erase(q.begin());

        if(vis[src])continue;
        vis[src] = true;

        for(auto child : graph[src]){
            int cv = child.first;
            int wt = child.second;

            if(dist[src] + wt < dist[cv]){
                dist[cv] = dist[cv] + wt;
                q.insert({dist[cv], cv});
                par[cv] = src;
            }
        }
    }
}

int32_t main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y, wt});
        graph[y].push_back({x, wt});
    }
    bfs();

    int x;
    while(cin >> x){
        while(x != 1){
            cout << x <<" ";
            x = par[x];
        }
        cout << 1 << endl;
    }
}