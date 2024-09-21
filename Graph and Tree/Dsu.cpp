#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int par[N];
int Size[N];

int Find(int v){
    if(par[v] == v)return v;
    return par[v] = Find(par[v]);
}

void make(int v){
    par[v] = v;
    Size[v] = 1;
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    
    if(a != b){
        //Union by size
        if(Size[a] < Size[b])swap(a, b);

        par[b] = a;
        Size[a] += Size[b];
    }
}

int32_t main(){
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)make(i);

    for(int i = 0; i < k; i++){
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }

    int cc = 0;
    for(int i = 1; i <= n; i++){
        if(par[i] == i)cc++;
    }

    cout << cc << endl;

}