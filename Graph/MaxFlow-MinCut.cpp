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
const int INF = 1e9 + 7;

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


int32_t main(){
  
}