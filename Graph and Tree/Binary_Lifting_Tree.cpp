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

int n;
vector<vector<int>> graph(N);

int lgMx = 20;
int lca[N][25];
int levl[N], par[N];

void dfs(int v = 1, int p = 0){
    par[v] = p;
    for(auto child : graph[v]){
        if(child == p)continue;
        levl[child] = levl[v] + 1;
        dfs(child, v);
    }
}

void binLift(int v = 1, int p = 0){
    lca[v][0] = p;

    for(int i = 1; i <= lgMx; i++){
        lca[v][i] = lca[lca[v][i - 1]][i - 1];
    }

    for(auto child : graph[v]){
        if(child == p)continue;
        binLift(child, v);
    }
}

int getLca(int a, int b){
    if(levl[a] < levl[b])swap(a, b);
    int d = levl[a] - levl[b];
    
    //To make levl[a] == levl[b]
    while(d > 0){
        int i = log2(d);
        a = lca[a][i];
        d -= (1 << i);
    }
    
    if(a == b)return a;

    //To get their loweset LCA
    for(int i = lgMx; i >= 0; i--){
        if(lca[a][i] == 0)continue;
        if(lca[a][i] == lca[b][i])continue;
        
        a = lca[a][i];
        b = lca[b][i];
    }

    return lca[a][0]; // or you can return par[a]
}


int32_t main(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(); binLift();
    int x, y;
    cin >> x >> y;
    cout << getLca(x, y) << endl;
}