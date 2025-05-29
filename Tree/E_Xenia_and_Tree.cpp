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
const int INF = 1e18 + 7;
const int M = 1e9 + 7;
const int N = 2e5 + 10;


struct Centroid{
    int n;
    vector<set<int>> graph;
    vector<int> sz, par, ans;
    vector<map<int, int>> dist;
    Centroid(vector<set<int>> &graph) : graph(graph){
        n = graph.size();
        sz.resize(n + 1);
        par.resize(n + 1);
        dist.resize(n + 1);
        ans.resize(n + 1, INF);
        build(1, 0);
    }

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

    void dfs(int u, int p, int c, int d){
        dist[u][c] = d;
        for(auto &v : graph[u])if(v != p){
            dfs(v, u, c, d + 1);
        }
    }

    void build(int u, int p = 0){
        int n = dfs(u, p);
        int c = cent(u, p, n);
        par[c] = p;
        dfs(c, p, c, 0);

        vector<int> temp(graph[c].begin(), graph[c].end());
        for(auto &v : temp){
            graph[c].erase(v);
            graph[v].erase(c);
            build(v, c);
        }
    }

    void update(int u){
        for(int v = u; v; v = par[v]){
            ans[v] = min(ans[v], dist[u][v]);
        } //update ancestor centroids
    }
    int query(int u){
        for(int v = u; v; v = par[v]){
            ans[u] = min(ans[u], ans[v] + dist[u][v]);
        }
        return ans[u];
    }
};

int32_t main(){
    int n, q;
    cin >> n >> q;
    vector<set<int>> graph(n + 1);
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    Centroid cd(graph);
    cd.update(1); 

    while(q--){
        int t, u;
        cin >> t >> u;
        if(t == 1)cd.update(u);
        else cout << cd.query(u) << endl;
    }
}