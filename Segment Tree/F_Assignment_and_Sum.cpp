#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define DB(...)
#   define db(...) "" 
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, q, v[N];

struct ST{
    #define lc  2 * node
    #define rc  2 * node + 1
    
    vector<int> tree, lazy;
    ST(int N = 2e5 + 10){
        tree = lazy = vector<int>(4 * N);
    }

    inline void pull(int node){
        tree[node] = tree[lc] + tree[rc]; /*********/
    }
    inline void push(int node, int lo, int hi){ /*************/
        if(lazy[node] == 0)return;
        
        int val = lazy[node]; 
        tree[node] += (hi - lo + 1) * val;
        lazy[node] = 0;
        
        if(lo == hi)return;
        lazy[lc] = lazy[lc] + val;
        lazy[rc] = lazy[rc] + val;
    }

    void build(int node, int lo, int hi){
        if(lo == hi){
            tree[node] = v[node];
            return;
        }
        int mid = (lo + hi) / 2;
        build(lc, lo, mid);
        build(rc, mid + 1, hi);
        pull(node);
    }

    void update(int node, int lo, int hi, int l, int r, int val){
        push(node, lo, hi);
        if(r < lo or l > hi)return;
        if(lo >= l and hi <= r){
            lazy[node] += val;    /************/
            push(node, lo, hi);
            return;
        }
        int mid = (lo + hi) / 2;
        update(lc, lo, mid, l, r, val);
        update(rc, mid + 1, hi, l, r, val);
        pull(node);
    }

    int query(int node, int lo, int hi, int l, int r){
        push(node, lo, hi);
        if(r < lo or l > hi)return 0;  /************/
        if(lo >= l and hi <= r)return tree[node];
        int mid = (lo + hi) / 2;
        int q1 = query(lc, lo, mid, l, r);
        int q2 = query(rc, mid + 1, hi, l, r);

        return q1 + q2; /********/
    }
} st;

int32_t main(){
    int n, q;
    cin >> n >> q;

    while(q--){
        int t, l, r;
        cin >> t >> l >> r; 
        r--;

        if(t == 1){
            int val; 
            cin >> val;
            st.update(1, 0, n - 1, l, r, val);
        }else{
            cout << st.query(1, 0, n - 1, l, r) << endl;
        }
    }
}