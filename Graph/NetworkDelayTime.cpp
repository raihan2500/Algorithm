#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int N = 1e3 + 10;

int dijsktra(int source, int n, vector<pair<int, int>> graph[]){
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

    int ans = 0;

    for(int i = 1; i <= n; i++){
        if(dist[i] == INF)return -1;
        ans = max(ans, dist[i]);
    }

    return ans;  
}

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<pair<int, int>> graph[N];
    for(auto vec : times){
        graph[vec[0]].push_back({vec[1], vec[2]});
    } 
    return dijsktra(k, n, graph);
}


int main(){
    

}