#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;
int n, m;
vector<int> par(N);

void make(){
    for(int i = 1; i <= n; i++){
        par[i] = i;
    }
}

int Find(int v){
    if(par[v] == v)return v;
    return par[v] = Find(par[v]);
}

void Union(int u, int v){
    u = Find(u);
    v = Find(v);

    par[v] = u;
}

int32_t main(){
    cin >> n >> m;
    make();
    while(m--){
        string type; int u, v;
        cin >> type >> u >> v;

        if(type == "union")Union(u, v);
        else{
            if(Find(u) == Find(v))cout <<"YES\n";
            else cout <<"NO\n";
        }
    }
}