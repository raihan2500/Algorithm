#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18 + 100;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

vector<int> tree(4 * N), lazy(4 * N), v(N);


int query(int node, int lo, int hi, int &l, int &r){
    
    if(lazy[node] != 0){
        int dx = lazy[node];
        lazy[node] = 0;
        tree[node] += dx;

        if(lo != hi){
            lazy[2 * node] += dx;
            lazy[2 * node + 1] += dx;
        }
    }
    
    if(lo > r or hi < l)return INF;
    if(lo >= l and hi <= r)return tree[node];

    int mid = (lo + hi) / 2;
    int q1 = query(2 * node, lo, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, hi, l, r);

    return min(q1, q2);
}


void update(int node, int lo, int hi, int &l, int &r, int &val){
    
    if(lazy[node] != 0){
        int dx = lazy[node];
        lazy[node] = 0;
        tree[node] += dx;

        if(lo != hi){
            lazy[2 * node] += dx;
            lazy[2 * node + 1] += dx;
        }
    }
    

    if(lo > r or hi < l)return;
    if(lo >= l and hi <= r){
        tree[node] += val;

        if(hi != lo){
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }
        return;    
    }
    
    int mid = (lo + hi) / 2;
    update(2 * node, lo, mid, l, r, val);
    update(2 * node + 1, mid + 1, hi, l, r, val);

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

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}


int32_t main(){
    int n, q;
    cin >> n >> q;
    // build(1, 0, n - 1);
    
    // return 0;
    while(q--){
        int type, l, r, val;
        cin >> type;

        if(type == 1){
            cin >> l >> r >> val;
            update(1, 0, n - 1, l, --r, val);
        }else{
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, --r) << endl;
        }
    }

    // for(int i = 0; i < n; i++)cout << tree[i] <<" ";
    
}