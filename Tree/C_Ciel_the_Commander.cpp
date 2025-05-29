#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n; 
set<int> graph[N];
int sz[N], par[N];

int dfs(int u, int p){
    sz[u] = 1;
    for(auto &v : graph[u])if(v != p){
        sz[u] += dfs(v, u);
    }
    return sz[u];
}
int cent(int u, int p, int n){
    for(auto &v : graph[u])if(v != p){
        if(sz[v] > n / 2)return cent(v, u, n);
    }
    return u;
}
int cen = 1;
void build(int u, int p = 0){
    int n = dfs(u, p);
    int c = cent(u, p, n);
    if(!p){
        cen = c;
        p = c;
    }
    par[c] = p;

    vector<int> temp(graph[c].begin(), graph[c].end());
    for(auto v : temp){
        graph[c].erase(v);
        graph[v].erase(c);
        build(v, c);
    }
}

vector<int> tree[N];
char ans[N];
void dfs(int u, int p, char x){
    ans[u] = x++;
    for(auto &v : tree[u]){
        dfs(v, u, x);
    }
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }

    build(1, 0);

    for(int i = 1; i <= n; i++){
        if(i == cen)continue;
        tree[par[i]].push_back(i);
    }
    dfs(cen, 0, 'A');
    for(int i = 1; i <= n; i++)cout << ans[i] << " ";
}