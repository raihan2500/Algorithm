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

int n, v[N];

struct Fenwick{
    int n;
    vector<int> tree;
    Fenwick(int n = 2e5) : n(n){
        tree.resize(n + 1);
    }
    int query(int i){
        int ans = 0;
        for(; i >= 1; i -= (i & -i))ans += tree[i];
        return ans;
    }
    int query(int l, int r){
        return query(r) - query(l - 1);
    }

    void update(int i, int val){
        for(; i <= n; i += (i & -i))tree[i] += val;
    }
    void update(int l, int r, int val){
        update(l, val);
        update(r + 1, -val);
    }
};



template <class T>
struct BIT { //1-indexed
  int n; vector<T> t;
  BIT() {}
  BIT(int _n) {
    n = _n; t.assign(n + 1, 0);
  }
  T query(int i) {
    T ans = 0;
    for (; i >= 1; i -= (i & -i)) ans += t[i];
    return ans;
  }
  void upd(int i, T val) {
    if (i <= 0) return;
    for (; i <= n; i += (i & -i)) t[i] += val;
  }
  void upd(int l, int r, T val) {
    upd(l, val);
    upd(r + 1, -val);
  }
  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

int32_t main(){
    cin >> n;
    // Fenwick bit(n);
    BIT<int> bit(n);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        bit.upd(i, v[i]);
    }
    print(bit.t);
    
    bit.upd(1, 4, 50);
    print(bit.t);
    cout << bit.query(1, 2) << endl;
    cout << bit.query(0) << endl;
}