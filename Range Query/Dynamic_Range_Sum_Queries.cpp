#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 100;
vector<int> input(N), tree(4 * N);

int query(int node, int lo, int hi, int l, int r){
    
    if(lo > r or hi < l)return 0;
    if(lo >= l and hi <= r)return tree[node];

    int mid = (lo + hi) / 2;
    int q1 = query(2 * node, lo, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, hi, l, r);

    return (q1 + q2);
}

void update(int node, int lo, int hi, int l, int r){
    if(lo > l or hi < l)return;
    if(lo == hi){
        tree[node] = r;
        return;
    }
    int mid = (lo + hi) / 2;
    update(2 * node, lo, mid, l, r);
    update(2 * node + 1, mid + 1, hi, l, r);

    tree[node] = (tree[2 * node] + tree[2 * node + 1]);
}

void build(int node, int lo, int hi){
    if(lo == hi){
        tree[node] = input[lo];
        return;
    }
    int mid = (lo + hi) / 2;
    build(2 * node, lo, mid);
    build(2 * node + 1, mid + 1, hi);

    tree[node] = (tree[2 * node] + tree[2 * node + 1]);
}

int32_t main(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)cin >> input[i];
    build(1, 0, n - 1);

    while(q--){
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 2){
            cout << query(1, 0, n - 1, --l, --r)<< endl;
        }else{
            update(1, 0, n - 1, --l, r);
        }
    }
}