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

int n, m;
vector<pair<int, int>> g[N];

const int LG = 20;
int depth[N], par[N][LG + 1], mx[N][LG + 1];

void init(int u = 1, int p = 0, int w = -1e18){
  par[u][0] = p;
  mx[u][0] = w;

  for(int i = 1; i <= LG; i++){
    par[u][i] = par[par[u][i - 1]][i - 1];
    mx[u][i] = max(mx[u][i - 1], mx[par[u][i - 1]][i - 1]);
  }
  for(auto &[v, w] : g[u])if(v != p){
    depth[v] = depth[u] + 1;
    init(v, u, w);
  }
}

int maxEdge(int u, int v){
  if(depth[u] < depth[v])swap(u, v);
  int dif = depth[u] - depth[v];
  int res = -1e18;

  for(int i = LG; i >= 0; i--){
    if(dif & (1 << i)){
      res = max(res, mx[u][i]);
      u = par[u][i];
    }
  }
  if(u == v)return res;

  for(int i = LG; i >= 0; i--){
    if(par[u][i] == par[v][i])continue;
    res = max({res, mx[u][i], mx[v][i]});
    u = par[u][i];
    v = par[v][i];
  }
  res = max({res, mx[u][0], mx[v][0]});
  return res;
}


struct edge{
  int x, y, w;
  edge(int x = 0, int y = 0, int w = 0) : x(x), y(y), w(w){}
  inline bool operator<(const edge &o){return w < o.w;}
  void show(){clog << x <<" " << y <<" " << w << endl;}
};

struct Dsu{
  vector<int> par, rank, sz;
  Dsu(int n = 2e5): par(n + 1), rank(n + 1), sz(n + 1, 1){
    iota(par.begin(), par.end(), 0);
  }
  int Find(int v){
    return par[v] = (par[v] == v) ? v : Find(par[v]);
  }
  void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a == b)return;
    if(rank[a] < rank[b])swap(a, b);
    if(rank[a] == rank[b])rank[a]++;
    par[b] = a;  sz[a] += sz[b];
  }
};


void reset(){
  for(int i = 1; i <= n; i++){
    g[i].clear();
    depth[i] = 0;
    for(int j = 0; j <= LG; j++){
      par[i][j] = 0;
      mx[i][j] = -1e18;
    }
  }
}

void _(){
  cin >> n >> m;
  reset();
  vector<edge> v(m);
  for(int i = 0; i < m; i++){
    cin >> v[i].x >> v[i].y >> v[i].w;
  }
  sort(v.begin(), v.end());

  Dsu dsu(n);
  int mst = 0;
  vector<int> used(m, 0);

  for(int i = 0; i < m; i++){
    auto [x, y, w] = v[i];
    if(dsu.Find(x) == dsu.Find(y))continue;
    dsu.Union(x, y);
    mst += w;
    used[i] = 1;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }

  depth[1] = 0;
  init(1, 0, 0);

  int ans = 1e18;
  for(int i = 0; i < m; i++){
    if(used[i])continue;
    auto [x, y, w] = v[i];
    int mxEdge = maxEdge(x, y);
    int cur = mst + w - mxEdge;
    ans = min(ans, cur);
  }

  //Second best MST
  cout << ans << endl;
}



int32_t main(){
  
}