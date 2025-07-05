#include<bits/stdc++.h>
using namespace std;

/*
  Given an array and some query; n, q <= 2e5;
  query(l, r, k) = kth smallest element in range [l, r];
*/

const int N = 2e5 + 100;

struct PST{
  #define lc t[cur].l
  #define rc t[cur].r
  struct node{
    int l = 0, r = 0, val = 0;
  };
  int n, T = 0;
  vector<node> t;
  PST(int n = 2e5) : n(n){
    t.resize(20 * n);
  }

  int build(int lo, int hi){
    int cur = ++T;
    if(lo == hi)return cur;
    int mid = lo + hi >> 1;
    lc = build(lo, mid);
    rc = build(mid + 1, hi);
    return cur;
  }
  int update(int pre, int lo, int hi, int i, int val){
    int cur = ++T;
    t[cur] = t[pre];
    if(hi == lo){
      t[cur].val += val;
      return cur;
    }
    int mid = lo + hi >> 1;
    if(i <= mid){
      lc = update(t[pre].l, lo, mid, i, val);
    }else{
      rc = update(t[pre].r, mid + 1, hi, i, val);
    }
    t[cur].val = t[lc].val + t[rc].val;
    return cur;
  }

  int query(int l, int r, int lo, int hi, int k){
    if(lo == hi)return lo;
    int cnt = t[t[r].l].val - t[t[l].l].val;
    int mid = hi + lo >> 1;
    if(cnt >= k){
      return query(t[l].l, t[r].l, lo, mid, k);
    }else{
      return query(t[l].r, t[r].r, mid + 1, hi, k - cnt);
    }
  }
};

/*Coordinate Compression*/
struct Compress{
    vector<int> v;
    Compress(const vector<int>& vec) : v(vec){
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }
    int get_id(int x){
        return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
    }
    int get_real(int i){
      return v[i - 1];
    }
    int size(){
        return v.size();
    }
};


int n, q, v[N], root[N];
/*root[i] = segment tree for ith update */

int32_t main(){    
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  
  cin >> n >> q;
  vector<int> temp;
  for(int i = 1; i <= n; i++){
    cin >> v[i];
    temp.push_back(v[i]);
  }  
  Compress cc(temp);
  for(int i = 1; i <= n; i++)v[i] = cc.get_id(v[i]);

  PST pst(n);
  root[0] = pst.build(1, n);

  for(int i = 1; i <= n; i++){
    root[i] = pst.update(root[i - 1], 1, n, v[i], 1);
  }

  while(q--){
    int l, r, k;
    cin >> l >> r >> k;
    int id = pst.query(root[l - 1], root[r], 1, n, k);
    cout << cc.get_real(id) << endl;
  }
}
