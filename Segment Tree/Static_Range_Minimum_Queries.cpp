#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int N = 2e5 + 10;
int v[N], tree[4 * N];

int query(int node, int lo, int hi, int l, int r){
    if(l > hi || r < lo)return INF;
    if(lo >= l && hi <= r)return tree[node];

    int mid = (lo + hi) / 2;

    int q1 = query(2 * node, lo, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, hi, l, r);

    return min(q1, q2);
}

void update(int node, int lo, int hi, int l){
    if(l > hi || l < lo)return;
    if(lo == hi){
        tree[node] = v[lo];
        return;
    }

    int mid = (lo + hi) / 2;
    
    update(2 * node, lo, mid, l);
    update(2 * node +  1, mid + 1, hi, l);

    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}



void build(int node, int lo, int hi){
    if(lo == hi){
        tree[node] = v[lo];
        return;
    }

    int mid = (lo + hi) / 2;
    
    build(2 * node, lo, mid);
    build(2 * node + 1, mid + 1, hi);

    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int32_t main(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)cin >> v[i];

    build(1, 0, n - 1);

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(1, 0, n - 1, --l, --r) << endl;
    }    
}