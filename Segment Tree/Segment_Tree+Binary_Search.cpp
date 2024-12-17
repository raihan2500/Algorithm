#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 1e5 + 10;

int n, q;
int tree[4 * N], v[N];


int query(int node, int lo, int hi, int &l, int &r){
    if(lo > r or hi < l)return -M; //***
    if(lo >= l and hi <= r)return tree[node];

    int mid = (lo + hi) / 2;
    int q1 = query(2 * node, lo, mid, l, r);
    int q2 = query(2 * node + 1, mid + 1, hi, l, r);

    return max(q1, q2); //***
}


void update(int node, int lo, int hi, int pos, int val){
    if(lo > pos or hi < pos)return;
    if(lo >= pos and hi <= pos){
        tree[node] = val;
        return;
    }

    int mid = (lo + hi) / 2;
    update(2 * node, lo, mid, pos, val);
    update(2 * node + 1, mid + 1, hi, pos, val);

    tree[node] = max(tree[2 * node], tree[2 * node + 1]); //***
}


void build(int node, int lo, int hi){
    if(lo == hi){
        tree[node] = v[lo];
        return;
    }

    int mid = (lo + hi) / 2;
    build(2 * node, lo, mid);
    build(2 * node + 1, mid + 1, hi);

    tree[node] = max(tree[2 * node], tree[2 * node + 1]); //***
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> q;
    for(int i = 0; i < n; i++)cin >> v[i];
    build(1, 0, n - 1);

    while(q--){
        int typ, ind, val, ans = n;
        int lo = 0, hi = n, mid;
        cin >> typ;

        if(typ == 1){
            cin >> ind >> val;
            update(1, 0, n - 1, ind, val);
            continue;        
        }else{
            cin >> val;
            while(hi > lo){
                mid = (lo + hi) / 2;
                if(query(1, 0, n - 1, lo, mid) < val){
                    lo = mid + 1;
                }else{
                    hi = mid;
                }
            }
        }
        cout << (lo == n ? -1 : lo) << endl;
    }
}

// Problem link: https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/C