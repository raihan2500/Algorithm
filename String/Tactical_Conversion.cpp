#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;
using ull = uint64_t;
//using u128 = __uint128_t;

#define int                 long long
#define double              long double

#define endl                "\n"
#define yes                 cout<<"Yes\n"
#define no                  cout<<"No\n"
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

void _(){
  lin(n);
  string str; cin >> str;
  int cc = 0, mx = 0;
  for(int i = 0; i < n; i++){
    if(str[i] == '0')continue;
    while(i < n and str[i] == '1')mx++,i++; i--;
    cc++;
  }
  if(cc == 1){
    mx < 4 and mx > 1 ? no : yes;
  }else yes;   
  
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