#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;
vector<int> input(N), tree(4 * N);

int query(int node, int lo, int hi, int l, int r){
    
    if(lo > r or hi < l)return 1e9;
    if(lo >= l and hi <= r)return tree[node];

    int mid = (lo + hi) / 2;
    int q1 = query(2 * node, lo, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, hi, l, r);

    return min(q1, q2);
}

void build(int node, int lo, int hi){
    if(lo == hi){
        tree[node] = input[lo];
        return;
    }
    int mid = (lo + hi) / 2;
    build(2 * node, lo, mid);
    build(2 * node + 1, mid + 1, hi);

    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)cin >> input[i];
    build(1, 0, n - 1);

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(1, 0, n - 1, --l, --r)<< endl;
    }
}