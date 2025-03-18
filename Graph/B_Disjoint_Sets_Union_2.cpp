#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 5e5 + 10;
int n, m;
class grp{public: int par, mn, mx, sz; grp(){} grp(int a, int b, int c, int d){ par = a; mn = b; mx = c; sz = d; } void display(){cout << mn <<" " << mx <<" " << sz << endl; }};

vector<grp>par(N);

void make(){
    for(int i = 1; i <= N; i++){
        par[i] = grp(i, i, i, 1);
    }
}

grp Find(int v){
    if(par[v].par == v)return par[v];
    return par[v] = Find(par[v].par);
}

void Union(int u, int v){
    int a = Find(u).par;
    int b = Find(v).par;

    if(a != b){
        if(par[a].sz < par[b].sz)swap(a, b);
        par[b].par = a;
        par[a].sz += par[b].sz;

        par[a].mn = min(par[a].mn, par[b].mn);
        par[a].mx = max(par[a].mx, par[b].mx);        
    }
}


int32_t main(){
    cin >> n >> m;
    make();

    while(m--){
        string type; int u, v;
        cin >> type;

        if(type == "union"){
            cin >> u >> v;
            Union(u, v);
        }else{
            cin >> u;
            Find(u).display();            
        }
    }   
}