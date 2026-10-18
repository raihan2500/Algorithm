#include<bits/stdc++.h>
using namespace std;

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
#define lin(n)              int n;cin>>n;
#define pr                  pair<int, int>
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

mt19937                     rng(chrono::steady_clock::now().time_since_epoch().count());
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


int func(vin a, vin b){
  int n = a.size(); 
  int m = b.size();
  map<int, int> mb;
  multiset<int> sa, sb;

  forn(i,n)sa.insert(a[i]);
  forn(i,m)mb[b[i]]++, sb.insert(b[i]);
  
  int ans = 0;
  int baki = m;

  while(sa.size()){
    map<int, int> ma;
    int cnt = min(baki, n);
    if(sa.size())
    for(auto i = sa.rbegin(); i != sa.rend() and cnt--; i++){
      ma[*i]++;
    }
    vector<pr> v;
    for(auto i : ma)v.push_back(i);
    sort(all(v), [&](auto a, auto b){
      return a.second < b.second;
    });
    clog << db(v);
    
    for(auto it = mb.rbegin(); it != mb.rend(); it++){
      auto &[x, cnt] = *it;
      vin rem;
      for(; cnt > 0 and v.size(); ){
        if(v.back().first != x){
          int mn = min(cnt, v.back().second);
          forn(xx, mn)sa.erase(sa.find(v.back().first));
          ans += mn * x + mn * v.back().first;

          cnt -= mn;
          v.back().second -= mn;

          baki -= mn; 
          n -= mn;

          if(v.back().second == 0)v.pop_back();
          
        }else if(v.size() == 1)break;
        else {
          swap(v[v.size() - 1], v[v.size() - 2]);
        }
      }
    }
    for(auto i : v)sa.erase(i.first);
  }

  return ans;
}

void _(){
  int n, m;
  cin >> n >> m;
  vin a(n), b(m);
  if(n > m){
    swap(n, m);
    swap(a, b);
  }
  forn(i,n)cin >> a[i];
  forn(i,m)cin >> b[i];
  
  // int ans = max(func(a, b), func(b, a));
  int ans = func(a, b);
  cout << ans << endl;
  
}

int32_t main(){
    
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int test = 1;  
  cin>>test;
  for(int i = 1; i <= test; i++){
      // cout << "Case #" << i <<": ";
      _();
  }
  return 0;
}