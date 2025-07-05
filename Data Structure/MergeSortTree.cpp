#include<bits/stdc++.h>
using namespace std;

/*
  Find number of element greater than x in range [l, r];
*/

struct MergeST{
  #define lc node << 1
  #define rc node << 1 | 1

  int n;
  vector<int> v;
  vector<vector<int>> t;
  MergeST(vector<int> v) : v(v){
    n = v.size() - 1;
    t.resize(4 * n);
    build(1, 1, n);
  }
  inline void merge(vector<int> &ans, vector<int> &a, vector<int> &b){
    int n = a.size();
    int m = b.size();
    int i = 0, j = 0;
    for(; i < n and j < m;){
      if(a[i] < b[j])ans.push_back(a[i++]);
      else ans.push_back(b[j++]);
    }
    while(i < n)ans.push_back(a[i++]);
    while(j < m)ans.push_back(b[j++]);
  }

  int query(int node, int lo, int hi, int l, int r, int x){
    if(hi < l or lo > r)return 0;
    if(lo >= l and hi <= r){
      const auto &vec = t[node];
      return vec.end() - upper_bound(vec.begin(), vec.end(), x);
    }

    int mid = (lo + hi) >> 1;
    int q1 = query(lc, lo, mid, l, r, x);
    int q2 = query(rc, mid + 1, hi, l, r, x);
    return q1 + q2;
  }

  void build(int node, int lo, int hi){
    if(hi == lo){
      t[node] = {v[lo]};
      return;
    }
    int mid = (hi + lo) >> 1;
    build(lc, lo, mid);
    build(rc, mid + 1, hi);
    merge(t[node], t[lc], t[rc]);
  }
};



int32_t main(){
  
}
