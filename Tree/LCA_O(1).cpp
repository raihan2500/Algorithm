#include<bits/stdc++.h>
using namespace std;

#define int long long
#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define NB 420
#   define db(...) "" 
#endif

const int M = 1e9 + 7;
const int N = 2e5 + 10;


inline int Min(int a, int b){return min(a, b);}
template<typename T = int, T(*pull)(T, T) = Min>
struct SPT{
  int n; 
  vector<T> v;
  vector<vector<T>> t;
  SPT(){};
  SPT(vector<T> &v) : v(v){
    n = v.size() - 1; //1 Based index
    t.assign(n + 1, vector<T> (32 - __builtin_clz(n)));
    build();
  }
  void build(){
    for(int i = 1; i <= n; i++)t[i][0] = v[i];
    for(int j = 1; (1 << j) <= n; j++){
      for(int i = 1; i + (1 << j) - 1 <= n; i++){
        t[i][j] = pull(t[i][j - 1], t[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  T query(int l, int r){
    assert(l <= r);
    int j = 31 - __builtin_clz(r - l + 1);
    return pull(t[l][j], t[r - (1 << j) + 1][j]);
  }
};

struct LCA{
  #define pii pair<int, int>
  static pii Pull(pii a, pii b){return min(a, b);};
  vector<pii> linear;
  SPT<pii, Pull> spt;

  int n, timer = 0;
  vector<int> in, dep;
  vector<vector<int>> graph;
  LCA(){};
  LCA(int n) : n(n), in(n + 1, -1), dep(n + 1), graph(n + 1), linear(2 * n + 2){};
  
  void dfs(int u, int p){
    in[u] = ++timer;
    linear[timer] = {dep[u], u};
    for(auto &v : graph[u])if(v != p){
      dep[v] = dep[u] + 1;
      dfs(v, u);
      linear[++timer] = {dep[u], u};
    }
  }
  void addEdge(int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  void build(int root = 1){
    dfs(root, 0);
    spt = SPT<pii, Pull>(linear);
  }

  int lca(int a, int b){
    a = in[a], b = in[b];
    if(a > b)swap(a, b);
    return spt.query(a, b).second;    
  }
  int dist(int u, int v){
    int lc = lca(u, v);
    return dep[u] + dep[v] - 2 * dep[lc];
  }
  bool onPath(int u, int v, int x){
    return dist(u, x) + dist(v, x) == dist(u, v);
  }
};



int32_t main(){
  
}