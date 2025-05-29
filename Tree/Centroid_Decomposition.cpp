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


struct Centroid{
    int n;
    vector<set<int>> graph;
    vector<int> sz, par;
    Centroid(vector<set<int>> &graph) : graph(graph){
        n = graph.size();
        sz.resize(n + 1);
        par.resize(n + 1);
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

    void build(int u, int p = 0){
        int n = dfs(u, p);
        int c = cent(u, p, n);
        if(!p)p = c;
        par[c] = p;

        vector<int> temp(graph[c].begin(), graph[c].end());
        for(auto &v : temp){
            graph[c].erase(v);
            graph[v].erase(c);
            build(v, c);
        }
    }
};

int32_t main(){
    int n;
    cin >> n;
    vector<set<int>> graph(n + 1);
    for(int i = 0; i < n - 1; i ++){
        int x, y;
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    Centroid cd(graph);
    for(int i = 1; i <= n; i++)cout << cd.par[i] <<" ";


}