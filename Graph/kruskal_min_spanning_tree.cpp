#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;


struct grp{ int x, y, z; grp(){}grp(int a, int b, int c){x = a; y = b; z = c;}};
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

void kruskal(){
  int n, m;
  cin >> n >> m;
  vector<grp> graph;
  for(int i = 0; i < m; i++){
    int x, y, z;
    cin >> x >> y >> z;
    graph.push_back({x, y, z});
  }
  sort(graph.begin(), graph.end(),[](grp a, grp b){return a.z < b.z;});

  int total_cost = 0;
  Dsu dsu(n);

  for(auto edge : graph){
    int x = edge.x;
    int y = edge.y;
    int z = edge.z;

    if(dsu.Find(x) == dsu.Find(y))continue;
    dsu.Union(x, y);
    total_cost += z;
  }

  cout << total_cost << endl;
}


int32_t main(){
    kruskal();  
}