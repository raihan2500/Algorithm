#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N], tree[4 * N];

int query(int node, int st, int en, int l, int r){
    
    //No overleap
    if(st > r || en < l)return 0;

    //Complete overleap
    if(st >= l && en <= r)return tree[node];

    int mid = (st + en) / 2;

    int q1 = query(2 * node, st, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, en, l, r);

    return q1 + q2;

}

void build(int node, int st, int en){
    if(st == en){
        tree[node] = a[st];
        return;
    }
    int mid = (st + en) / 2;
    
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int32_t main(){
    int n;
    cin >> n ;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    build(1, 0, n - 1);
    
    int l, r;
    cin >> l >> r;l--; r--;
    cout << query(1, 0, n - 1, l, r) <<endl;
    
}