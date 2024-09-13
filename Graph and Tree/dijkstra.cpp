#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
const int N = 1e3 + 10;

vector<pair<int, int>> graph[N];

void dijsktra(int source){
    vector<int> dist(N, INF), vis(N);

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
            }
        }        
    }


}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y, wt});
    }

    dijsktra(1);
}