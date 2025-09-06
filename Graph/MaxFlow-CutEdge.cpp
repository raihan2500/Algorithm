#include<bits/stdc++.h>
using namespace std;
 
//using u128 = __uint128_t;
#define int                 long long
 
#define endl                "\n"
#define yes                 cout<<"YES\n"
#define no                  cout<<"NO\n"
#define nl                  cout<<"\n"
#define cnl                 clog<<"\n"
 
#define lin(n)              int n;cin>>n;
#define vin                 vector<int>
#define pr                  pair<int, int>
#define pp                  pop_back()
#define pb                  push_back
#define em_pb               emplace_back
#define all(x)              x.begin(),x.end()
#define ppfr(v)             v.erase(v.begin());
#define sum_all(v)          accumulate(all(v), 0ll)
 
#define forn(i,n)           for(int i = 0; i < n; i++)
#define Forn(i,n)           for(int i = 1; i <= n; i++)
#define rforn(i,n)          for(int i = n - 1; i >= 0; i--)
#define print(arr)          for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)          for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;
 
#define _log2(n)            31 - __builtin_clz(n)
#define pop_count(n)        __builtin_popcount(n)
 
mt19937                     rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y)            uniform_int_distribution<int>(x,y)(rng)
 
#ifdef DEBUG
#include<algo/debug.h>
#else
#   define clog if (0) cerr
#   define NB 2500
#   define db(...) "" 
#endif
 
// const int M = 998244353;
const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 100;
 
struct edge{
  int u, v;
  int cap = 0, flow = 0;
  edge(int u = 0, int v = 0, int cap = 0) : u(u), v(v), cap(cap){}
 
  int flowFrom(int x){return x == u ? flow : -flow;}
  int other(int x){return x == u ? v : u;}
  int rescap(int x){return x == u ? cap - flow : flow;}
  void sendFlow(int x, int f){flow += (x == u) ? f : -f;}
};
 
vector<edge> E;
vector<int> adj[N];
 
inline void addEdge(int u, int v, int cap){
  E.emplace_back(u, v, cap);
  adj[u].push_back(E.size() - 1);
  adj[v].push_back(E.size() - 1);
}
 
int level[N];
int vis[N], clk;
int ptr[N];
 
bool bfs(int s, int t){
  clk++;
  queue<int> q;
  q.push(s);
  level[s] = 0;
  vis[s] = clk;
 
  while(!q.empty()){
    s = q.front(); q.pop();
    if(s == t)break;
    ptr[s] = 0;
    for(auto i : adj[s]){
      int v = E[i].other(s);
      if(vis[v] == clk or E[i].rescap(s) == 0)continue;
      vis[v] = clk;
      level[v] = level[s] + 1;
      q.push(v);
    }
  }
  return vis[t] == clk;
}
 
int augment(int u, int flow, int t){
  if(u == t or !flow)return flow;
 
  for(int &i = ptr[u]; i < adj[u].size(); i++){
    edge &e = E[adj[u][i]];
    int v = e.other(u);
    if(vis[v] != clk)continue;
    if(e.rescap(u) == 0)continue;
    if(level[v] != (level[u] + 1))continue;
    int sent = augment(v, min(flow, e.rescap(u)), t);
    if(sent){
      e.sendFlow(u, sent);
      return sent;
    }
  }
  level[u] = -1;
  return 0;
}
 
int maxFlow(int s, int t){
  int res = 0;
  while(bfs(s, t)){
    while(int temp = augment(s, INF, t)){
      res += temp;
    }
  }
  return res;
}
 
int seen[N];
void dfs(int u){
  seen[u] = 1;
  for(auto i : adj[u]){
    auto &e = E[i];
    int v = e.other(u);
    if(seen[v])continue;
    if(e.rescap(u) > 0){
      dfs(v);
    }
  }
}
 
void _(){
  int n, m;
  cin >> n >> m;
  for(int i = 1, x, y; i <= m; i++){
    cin >> x >> y;
    addEdge(x, y, 1);
    addEdge(y, x, 1);
  }      
  cout << maxFlow(1, n) << endl;
  dfs(1);
  vector<pr> ans;
  for(auto i : E){
    if(i.cap == 0)continue;
    if(seen[i.u] and !seen[i.v]){
      ans.push_back({i.u, i.v});
    }
  }
  mprint(ans);
 
}
 
int32_t main(){
    
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
 
  int test = 1;  
  // cin>>test;
  for(int i = 1; i <= test; i++){
      // cout << "Case " << i <<": ";
      _();
  }
  return 0;
}

//https://cses.fi/problemset/task/1695