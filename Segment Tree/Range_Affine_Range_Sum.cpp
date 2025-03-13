#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 998244353;
const int N = 8e5 + 100;

int n, q, l, r, b, c;
int v[N], tree[4 * N];

struct grp{
    int b, c;
};

vector<vector<grp>> lazy(4 * N);

void lazyUpdate(int node, int hi, int lo){
    vector<grp> temp = lazy[node];
    lazy[node].clear();
    for(auto g : temp){
        tree[node] = (__uint128_t)(tree[node] * g.b) % M;
        tree[node] = (__uint128_t)(tree[node] + g.c) % M;
    }
    if(hi != lo){
        for(auto g : temp){
            lazy[2 * node].push_back(g);
            lazy[2 * node + 1].push_back(g);
        }
    }
}


int query(int node, int lo, int hi){

    if(!lazy[node].empty()){
        lazyUpdate(node, lo, hi);
    }

    if(hi < l or lo > r)return 0;
    if(lo >= l and hi <= r)return tree[node];

    int mid = (lo + hi) / 2;
    int q1 = query(2 * node, lo, mid);
    int q2 = query(2 * node + 1, mid + 1, hi);

    return (q1 + q2) % M;
}


void update(int node, int lo, int hi){

    if(!lazy[node].empty()){
        lazyUpdate(node, lo, hi);
    }

    if(hi < l or lo > r)return;
    if(lo >= l and hi <= r){
        grp g = {b, c};
        tree[node] = (__uint128_t)(tree[node] * g.b) % M;
        tree[node] = (__uint128_t)(tree[node] + g.c) % M;

        if(hi != lo){
            lazy[2 * node].push_back(g);
            lazy[2 * node + 1].push_back(g);
        }
        return;
    }

    int mid = (lo + hi) / 2;
    update(2 * node, lo, mid);
    update(2 * node + 1, mid + 1, hi);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    tree[node] %= M;

}

void build(int node, int lo, int hi){
    if(hi == lo){
        tree[node] = v[lo];
        return;
    }
    int mid = (lo + hi) / 2;
    build(2 * node, lo, mid);
    build(2 * node + 1, mid + 1, hi);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    tree[node] %= M;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for(int i = 0; i < n; i++)cin >> v[i];
    build(1, 0, n - 1);
    while(q--){
        int typ; cin >> typ;
        cin >> l >> r; r--;
        if(typ == 1){
            cout << query(1, 0, n - 1) << endl;
        }else{
            cin >> b >> c;
            update(1, 0, n - 1);
        }
    }

}