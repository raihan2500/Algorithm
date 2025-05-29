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
int sz[N];
vector<int> graph[N];

int dfs(int u, int p){
    sz[u] = 1;
    for(auto &v : graph[u])if(v != p){
        sz[u] += dfs(v, u);
    }
    return sz[u];
}

int cent(int u, int p){
    for(auto &v : graph[u])if(v != p){
        if(sz[v] > n / 2)return cent(v, u);
    }
    return u;
}

int32_t main(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1, 0);
    cout << cent(1, 0) << endl;
}