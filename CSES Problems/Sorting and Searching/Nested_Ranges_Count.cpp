#include<bits/stdc++.h>
using namespace std;


#define ORDERED_SET_ON
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T>       using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; // less_equal


using ll = int64_t;
using ull = uint64_t;
//using u128 = __uint128_t;

#define int                 long long
#define double              long double

#define endl                "\n"
#define yes                 cout<<"YES\n"
#define no                  cout<<"NO\n"
#define nl                  cout<<"\n"
#define cnl                 clog<<"\n"

#define vin                 vector<int>
#define v2d                 vector<vector<int>> 
#define lin(n)              int n;cin>>n;
#define pii                 pair<int, int>
#define pb                  push_back
#define pp                  pop_back()
#define epb                 emplace_back
#define all(x)              x.begin(),x.end()
#define ppfr(v)             v.erase(v.begin());
#define sum_all(v)          accumulate(all(v), 0ll)
#define MAX_E               *max_element
#define MIN_E               *min_element 

#define forn(i,n)           for(int i = 0; i < n; i++)
#define Forn(i,n)           for(int i = 1; i <= n; i++)
#define rforn(i,n)          for(int i = n - 1; i >= 0; i--)
#define print(arr)          for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)          for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;

#define _log2(n)            63 - __builtin_clzll(n)
#define pop_count(n)        __builtin_popcountll(n)

mt19937                     rnd(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y)            uniform_int_distribution<int>(x,y)(rng)

#ifdef DEBUG
#include<algo/debug.h>
#else
#   define clog if (0) cerr
#   define NB 2500
#   define db(...) "" 
#endif

// const int M = 998244353;
const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 100;


struct Compress{
  vector<int> v;
  Compress(const vector<int>& vec) : v(vec){
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
  }
  int get_id(int x){
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
  }
  int size(){
    return v.size();
  }
  int get_org(int x){
    return v[--x];
  }
};





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




void _(){
  int n; cin >> n;
  struct node{
    int i, l, r;
    void show(){
      clog << i <<" " << l <<" " << r << endl;
    }
  };
  vin temp;
  vector<node> v(n);
  for(int i = 0; i < n; i++){
    auto &[id, l, r] = v[i];
    cin >> l >> r;
    id = i;
    temp.push_back(l);
    temp.push_back(r);
  }

  v.insert(v.begin(), {0, 0, 0});
  Compress cc(temp);
  for(auto &[i, l, r] : v){
    l = cc.get_id(l);
    r = cc.get_id(r);
  }

  sort(all(v), [&](auto a, auto b){
    if(a.l == b.l)return a.r < b.r;
    return a.l < b.l;
  });

  vin ms(n + 1);
  for(int i = 1; i <= n; i++)ms[i] = v[i].r;
  MST st(ms);

  vin in(n), out(n);
  vector<int> lef(2 * n + 1), rig(2 * n + 1);

  for(int i = 1; i <= n; i++){
    if(lef[v[i].l] == 0)lef[v[i].l] = i;
    rig[v[i].l] = i;
  }

  for(int i = 1; i <= n; i++){
    int l = lef[v[i].l];
    int r = rig[v[i].l];

    in[v[i].i] = st.query(l, n, ms[i] + 1, 0) - 1;
    out[v[i].i] = st.query(1, r, ms[i] - 1, 1) - 1;
  }



  print(in);
  print(out);
  
}

signed main(){
    
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int test = 1;  
  // cin>>test;
  for(int i = 1; i <= test; i++){
      // cout << "Case #" << i <<": ";
      _();
  }
  return 0;
}

