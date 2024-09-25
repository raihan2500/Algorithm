#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int M = 1e9 + 7;
const int N = 5e5 + 10;

vector<pair<int, int>> graph[N];
vector<int> dist(N, INF), vis(N), par(N);

void dijsktra(int source){

    set<pair<int, int>> s;
    s.insert({0, source});
    dist[source] = 0;

    while(!s.empty()){
        auto node = * s.begin();
        int v = node.second;
        int d = node.first;
        s.erase(s.begin());

        if(vis[v])continue;
        vis[v] = 1;

        for(auto child : graph[v]){
            int child_v = child.first;
            int wt = child.second;

            if(dist[v] + wt <  dist[child_v]){
                dist[child_v] = dist[v] + wt;
                s.insert({dist[child_v], child_v});
                par[child_v] = v;
            }
        }        
    }
}

int32_t main(){
    int n, m, s, d;
    cin >> n >> m >> s >> d;

    for(int i = 0; i < m; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y, wt});
    }

    dijsktra(s);
    if(dist[d] == INF){
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans;
    int src = d;

    while(src != s){
        ans.push_back(src);
        src = par[src];
    }
    ans.push_back(s);
    reverse(ans.begin(), ans.end());

    cout << dist[d] << " " << ans.size() - 1 << endl;

    for(int i = 0; i < ans.size() - 1; i++){
        cout << ans[i] <<" " << ans[i + 1] << endl;
    }
}