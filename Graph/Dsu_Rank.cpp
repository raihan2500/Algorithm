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

class Dsuu{
public:
    vector<int> par, rank;
    Dsuu(int n): par(n + 1), rank(n + 1){
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
        par[b] = a;
    }
};


int32_t main(){
    Dsuu dsu(10);

    dsu.Union(1, 2);
    dsu.Union(2, 3);
    dsu.Union(3, 4);

    dsu.Union(5, 6);
    dsu.Union(1, 5);
    print(dsu.rank);
  
}