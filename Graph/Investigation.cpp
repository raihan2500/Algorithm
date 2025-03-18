#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, m;
vector<vector<pair<int, int>>> graph(N);

void bfs(int v = 1){
    set<pair<int, int>> s;
    s.insert({0, v});
    vector<int> dist(N, INF), num(N), mn(N), mx(N), vis(N);
    dist[v] = 0; num[v] = 1;


    while(!s.empty()){
        v = s.begin()->second;
        s.erase(s.begin());
        if(vis[v])continue;
        vis[v] = true;

        for(auto &[child, wt] : graph[v]){
            
            if(dist[child] > dist[v] + wt){
                dist[child] = dist[v] + wt;
                s.insert({dist[child], child});
                
                num[child] = num[v];
                mx[child] = mx[v] + 1;
                mn[child] = mn[v] + 1;

            }else if(dist[child] == dist[v] + wt){
                num[child] = (num[child] + num[v]) % M;

                mx[child] = max(mx[child], mx[v] + 1);
                mn[child] = min(mn[child], mn[v] + 1);
            }
        }
    }
    cout << dist[n] <<" " << num[n] << " " << mn[n] << " " << mx[n] << endl;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, c;
        cin >> x >> y >> c;
        graph[x].push_back({y, c});
    }
    bfs();
}