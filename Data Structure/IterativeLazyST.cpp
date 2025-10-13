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
  vector<int> v, t, lz;
  ST(vector<int> v) : v(v){
    n = v.size() - 1;
    t.assign(2 * n, 0);
    lz.assign(2 * n, 0);
  };

  inline int pull(int a, int b){
    return a + b;
  }
  void build(){
    for(int i = 1; i <= n; i++)t[i + n] = v[i];
    for(int i = n; i >= 1; i--){
      t[i] = pull(t[i << 1], t[i << 1 | 1]);
    }
  }

  void update(int l, int r, int val){
    
  }

};

int32_t main(){
  
}