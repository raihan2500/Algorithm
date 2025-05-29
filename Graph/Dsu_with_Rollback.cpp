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



class Dsu_rollback{
    struct dsu_save{
        int u, v, ranku, rankv;
    };
    int cc;
    stack<dsu_save> op;
public:
    vector<int> par, rank;
    Dsu_rollback(int n = 2e5): par(n + 1), rank(n + 1){
        iota(par.begin(), par.end(), 0);
        cc = n;
    }
    int Find(int v){
        return par[v] = (par[v] == v) ? v : Find(par[v]);
    }
    void Union(int a, int b){
        a = Find(a);
        b = Find(b);
        if(a == b)return; 
        if(rank[a] < rank[b])swap(a, b);
        op.push({a, b, rank[a], rank[b]});
        if(rank[a] == rank[b])rank[a]++;
        par[b] = a;
        cc--;
    }
    
    void rollback(){
        if(op.empty())return;
        dsu_save x = op.top();
        op.pop();
        cc++;
        par[x.v] = x.v;
        rank[x.v] = x.rankv;
        par[x.u] = x.u;
        rank[x.u] = x.ranku;
    }
};

int32_t main(){
    Dsu_rollback dsu(10);
    dsu.Union(1, 2);
    dsu.Union(3, 4);
    dsu.Union(5, 6);
    dsu.Union(1, 5);

    print(dsu.rank);
    dsu.rollback();
    dsu.rollback();
    dsu.rollback();
    dsu.rollback();
    print(dsu.rank);
}