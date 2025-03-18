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

void reset(bool flg = true){
    for(int i = 0; i <= n; i++){
        if(flg)graph[i].clear();
    }
}

void sukuna(){
    cin >> n >> m;
    reset();
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

}


namespace Lca{
    const int MX = 25;
    int depth[N], lca[N][MX];

    void dfs(int v = 1, int p = 0){
        lca[v][0] = p;
        for(int i = 1; i < MX; i++){
            lca[v][i] = lca[lca[v][i - 1]][i - 1];
        }

        for(auto &u : graph[v]){
            if(u == p)continue;
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }

    int get(int x, int y){
        if(depth[x] < depth[y])swap(x, y);
        int dif = depth[x] - depth[y];

        while(dif){
            int lg = log2(dif);
            x = lca[x][lg];
            dif -= (1 << lg);
        }
        if(x == y)return x;
        
        for(int i = MX - 1; i >= 0; i--){
            if(lca[x][i] == lca[y][i])continue;
            x = lca[x][i];
            y = lca[y][i];
        }

        return lca[x][0];
    }
}

class Dsu{
    int n;
    vector<int> par, sz;
public:
    Dsu(int n){
        this->n = n;
        sz = vector<int> (n + 1, 1);
        par = vector<int> (n + 1);
        for(int i = 1; i <= n; i++)par[i] = i;
    }
    int Find(int v){
        return par[v] = (par[v] == v) ? v : Find(par[v]);
    }
    void Union(int a, int b){
        a = Find(a);
        b = Find(b);
        if(a == b)return;
        if(sz[a] < sz[b])swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
    }
};

int32_t main(){
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    Lca::dfs();
    cout << Lca::get(4, 6) << endl;
    
    return 0;
}