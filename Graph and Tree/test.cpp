#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUGd
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

class Dsu{
    int n;
    vector<int> par, sz;
    void make(){
        for(int i = 0; i <= n; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }
    public:
    Dsu(int n = 100){
        this->n = n;
        par = sz = vector<int> (n + 1);
        make();
    }

    int Find(int v){
        if(par[v] == v)return v;
        return par[v] = Find(par[v]);
    }

    void Union(int a, int b){
        a = Find(a);
        b = Find(b);
        
        if(a != b){
            if(sz[a] < sz[b])swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
        }
    }
};


int32_t main(){
    int n, m;
    cin >> n >> m;
    set<pair<int, pair<int, int>>> s;
    for(int i = 0; i < m; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        s.insert({wt, {x, y}});
    }
    Dsu dsu(n);

    int cost = 0;
    while(!s.empty()){
        int x = s.begin()->second.first;
        int y = s.begin()->second.second;
        int wt = s.begin()->first;
        s.erase(s.begin());

        if(dsu.Find(x) == dsu.Find(y))continue;
        cost += wt;
        dsu.Union(x, y);
    }
    cout << cost << endl;
  
}