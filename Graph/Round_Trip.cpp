#include<iostream>
#include<vector>
using namespace std;

const int N = 2e5 + 10;

int n, m;
vector<vector<int>> graph(N);

int parent[N], vis[N], source = -1, flg;

void dfs(int vertex, int par = -1){
    if(source != -1)return;
    if(vis[vertex]){
        source = par;
        flg = vertex;
        return;
    }
    vis[vertex] = 1;
    parent[vertex] = par;

    for(auto child : graph[vertex]){
        if(child == par)continue;
        dfs(child, vertex);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);


    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++){
        if(vis[i])continue;
        if(source != -1)break;
        dfs(i, 0);
    }

    if(source == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> path;
    path.push_back(flg);
    int v = source;
    while(v != flg){
        path.push_back(v);
        v = parent[v];
    }

    path.push_back(flg);
    cout << path.size() << endl;
    for(auto i : path) cout << i <<" "; cout << endl;
}