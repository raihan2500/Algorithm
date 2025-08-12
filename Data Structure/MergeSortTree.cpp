#include<bits/stdc++.h>
using namespace std;

/*
  Find number of element greater than x in range [l, r];
*/


struct MST{
  using vec = vector<int>;
  int n; vec v;
  vector<vec> t;

  MST(vec v) : v(v){
    n = v.size() - 1; //1-based index
    t.resize(2 * n + 2);
    build();
  }

  inline void merge(vec &ans, vec &a, vec &b) {
    int i = 0, j = 0;
    while(i < a.size() && j < b.size()) {
      if(a[i] < b[j]) ans.push_back(a[i++]);
      else ans.push_back(b[j++]);
    }
    while(i < a.size()) ans.push_back(a[i++]);
    while(j < b.size()) ans.push_back(b[j++]);
  }

  void build(){
    for(int i = 1; i <= n; i++)t[i + n].push_back(v[i]);
    for(int i = n; i >= 1; i--){
      merge(t[i], t[i << 1], t[i << 1 | 1]);
    } 
  }

  bool flg = false;
  int count(const vec &v, int x){
    if(flg){
      return (int)(v.end() - upper_bound(v.begin(), v.end(), x));
    }else{
      return (int)(lower_bound(v.begin(), v.end(), x) - v.begin());
    }
  }

  int query(int l, int r, int x, bool f){
    flg = f; //flg = 0: strictly less then x ; flg = 1: strictly greater than x;
    l += n; r += n;
    int ans = 0;
    for(; l <= r; l >>= 1, r >>= 1){
      if(l % 2 == 1)ans += count(t[l++], x);
      if(r % 2 == 0)ans += count(t[r--], x);
    }//Try while loop if there is an issue
    return ans;
  }
};





int32_t main(){
  
}
