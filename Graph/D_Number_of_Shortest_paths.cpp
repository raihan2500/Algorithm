#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, m;
vector<vector<int>> graph(N);

int bfs(int v = 1){
    queue<int> q;
    q.push(v);
    vector<int> dist(N, M), num(N, 0), vis(N);
    dist[v] = 0, num[v] = 1;
    
    while(!q.empty()){
        v = q.front();
        q.pop();
            
        for(auto child : graph[v]){
            if(dist[child] > dist[v] + 1){
                dist[child] = dist[v] + 1;
                num[child] = num[v];
                q.push(child);
            }else if(dist[child] == dist[v] + 1){
                num[child] = (num[child] + num[v]) % M;
            }
        }
    }

    return num[n];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    cout << bfs(1) << endl;
}