#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int N = 2e5 + 10;

int n, q;
int v[N], tree[N];
vector<pair<int,int>> lazy(N);

void lazyUpdate(int &node, int &lo, int &hi){
    if(lazy[node].first == 0)return;

    int val = lazy[node].second;
    lazy[node] = {0, 0};
    
    if(lazy[node].first == 1){
        tree[node] += (hi - lo + 1) * val;

        if(hi != lo){
            if(lazy[2 * node].first == 0)lazy[2 * node] = {1, val};
            else lazy[2 * node].second += val;

            if(lazy[2 * node + 1].first == 0)lazy[2 * node + 1] = {1, val};
            else lazy[2 * node + 1].second += val;
        }
    }else{
        tree[node] = (hi - lo + 1) * val;    
        if(hi != lo){
            lazy[2 * node] = {2, val};
            lazy[2 * node + 1] = {2, val}; 
        }
    }
}


int query(int node, int lo, int hi, int l, int r){
    lazyUpdate(node, lo, hi);

    if(lo > r or hi < l)return 0;
    if(lo >= l and hi <= r)return tree[node];

    int mid = (lo + hi) / 2;
    int q1 = query(2 * node, lo, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, hi, l, r);

    return q1 + q2;
}

void update(int node, int lo, int hi, int l, int r, int typ, int val){

    lazyUpdate(node, lo, hi);

    if(lo > r or hi < l)return;
    if(lo >= l and hi <= r){ 
        if(typ == 1){
            tree[node] += (hi - lo + 1) * val;

            if(hi != lo){
                if(lazy[2 * node].first == 0)lazy[2 * node] = {1, val};
                else lazy[2 * node].second += val;

                if(lazy[2 * node + 1].first == 0)lazy[2 * node + 1] = {1, val};
                else lazy[2 * node + 1].second += val;
            }
        }else{
            tree[node] = (hi - lo + 1) * val;    
            if(hi != lo){
                lazy[2 * node] = {2, val};
                lazy[2 * node + 1] = {2, val}; 
            }
        }
        return;
    }

    int mid = (lo + hi) / 2;
    update(2 * node, lo, mid, l, r, typ, val);
    update(2 * node + 1, mid + 1, hi, l, r, typ, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
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
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    for(int i = 0; i < n; i++)cin >> v[i];
    build(1, 0, n - 1);

    while(q--){
        int typ, l, r, val;
        cin >> typ >> l >> r; l--, r--;

        if(typ == 3){
            cout << query(1, 0, n - 1, l, r) << endl;
        }else{
            cin >> val;
            update(1, 0, n - 1, l, r, typ, val);
        }
    }
}