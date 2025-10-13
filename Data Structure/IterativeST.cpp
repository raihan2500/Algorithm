#include<bits/stdc++.h>
using namespace std;

#define int long long
#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define NB 420
#   define db(...) "" 
#endif

const int M = 1e9 + 7;
const int N = 2e5 + 10;


struct ST{
  int n; 
  vector<int> v, t;

  ST(vector<int> v) : v(v){
    n = v.size() - 1; //1-based index
    t.resize(2 * n + 2);
    build();
  }

  inline int pull(int a, int b){
    return a + b; //Sum query
  }

  void build(){
    for(int i = 1; i <= n; i++)t[i + n] = v[i];
    for(int i = n; i >= 1; i--){
      t[i] = pull(t[i << 1], t[i << 1 | 1]);
    } 
  }

  void update(int i, int val){
    i += n;
    t[i] = val;
    for(i >>= 1; i >= 1; i >>= 1){
      t[i] = pull(t[i << 1], t[i << 1 | 1]);
    }
  }

  int query(int l, int r){
    l += n; r += n;
    int ans = 0; //Sum query
    for(; l <= r; l >>= 1, r >>= 1){
      if(l % 2 == 1)ans = pull(ans, t[l++]);
      if(r % 2 == 0)ans = pull(ans, t[r--]);
    }
    return ans;
  }
};

int32_t main(){
  
}