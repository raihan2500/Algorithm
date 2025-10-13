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

void prims(){
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> graph[n + 1];
  for(int i = 0; i < m; i++){
    int x, y, w;
    cin >> x >> y >> w;
    graph[x].push_back({y, w});
    graph[y].push_back({x, w});
  }

  set<pair<int, int>> s;
  s.insert({0, 1});
  vector<bool> vis(n + 1);

  int ans = 0;
  while(!s.empty()){
    auto [w, u] = *s.begin();
    s.erase(s.begin());
    if(vis[u])continue;
    vis[u] = true;
    ans += w;

    for(auto &[v, w] : graph[u]){
      if(!vis[v])s.insert({w, v});
    }
  }
  
  cout << ans << endl;
}

int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  prims();
  
}