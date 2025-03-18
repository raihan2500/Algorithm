#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define DB(...)
#   define db(...) "" 
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, m;
vector<vector<int>> graph(N);

int timer;
set<int> art_point;
vector<int> in(N), low(N), vis(N);

void dfs(int v, int p = -1){
    vis[v] = true;
    in[v] = low[v] = timer++;
    int children = 0;

    for(auto child : graph[v]){
        if(child == p)continue;
        if(vis[child]){
            low[v] = min(low[v], in[child]);
        }else{
            dfs(child, v);
            if(low[child] >= in[v] and p != -1){
                art_point.insert(v);
            }
            children++;
        }
        low[v] = min(low[v], low[child]);
    }
    if(p == -1 and children > 1){
        art_point.insert(v);
    }
}
void find_cutpoints(){
    timer = 0;
    in.assign(n + 1, 0);
    low.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    art_point.clear();
    
    for(int i = 1; i <= n; i++){
        if(!vis[i])dfs(i);
    }
}

int32_t main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    find_cutpoints();
    print(art_point);
  
}