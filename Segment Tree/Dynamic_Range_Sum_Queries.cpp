#include<bits/stdc++.h>
using namespace std;
#define int      long long

const int N = 2e5 + 10;
int v[N], tree[4 * N];

int query(int node, int start, int end, int l, int r){
    if(start > r || end < l){
        return 0;
    }

    if(start >= l && end <= r){
        return tree[node];
    }

    int mid = (start + end) / 2;
    int q1 = query(2 * node, start, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, end, l, r);
    
    return q1 + q2;
}

void update(int node, int st, int en, int l){
    if(st > l || en < l)return;
    if(st == en){
        tree[node] = v[st];
        return;
    }

    int mid = (st + en) / 2;
    update(2 * node, st, mid, l);
    update(2 * node + 1, mid + 1, en, l);

    tree[node] = tree[2 * node] + tree[2 * node + 1]; 
}

void build(int node, int start, int end){
    if(start == end){
        tree[node] = v[start];
        return;
    }
    int mid = (start + end) / 2;

    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] + tree[2 * node + 1];

}

int32_t main(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)cin >> v[i];
    build(1, 0, n - 1);

    while(q--){
        int type, l, r;
        cin >> type >> l >> r;
        l--; 

        if(type == 2){
            r--;
            cout << query(1, 0, n - 1, l, r) << endl;
        }else{
            v[l] = r;
            update(1, 0, n - 1, l);
        }
    }
}