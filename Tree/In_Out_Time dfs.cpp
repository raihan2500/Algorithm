#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, m;
vector<int> graph[N], vis(N);
int in[N], out[N], tme = 1;

void dfs(int vertex = 1, int par = 0){
    if(vis[vertex])return;
    vis[vertex] = true;
    in[vertex] = tme++;

    for(auto child : graph[vertex]){
        if(child == par)continue;
        dfs(child, vertex);
    }
    out[vertex] = tme++;
}


int32_t main(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    dfs();

    for(int i = 1; i <= n; i++)cout << in[i] <<" ";cout << endl;
    for(int i = 1; i <= n; i++)cout << out[i] <<" ";cout << endl;



  
}