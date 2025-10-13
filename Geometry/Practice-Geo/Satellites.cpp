#include<bits/stdc++.h>
using namespace std;

//using u128 = __uint128_t;
#define int                 long long

#define endl                "\n"
#define yes                 cout<<"YES\n"
#define no                  cout<<"NO\n"
#define nl                  cout<<"\n"
#define cnl                 clog<<"\n"

#define lin(n)              int n;cin>>n;
#define vin                 vector<int>
#define pr                  pair<int, int>
#define pp                  pop_back()
#define pb                  push_back
#define em_pb               emplace_back
#define all(x)              x.begin(),x.end()
#define ppfr(v)             v.erase(v.begin());
#define sum_all(v)          accumulate(all(v), 0ll)

#define forn(i,n)           for(int i = 0; i < n; i++)
#define Forn(i,n)           for(int i = 1; i <= n; i++)
#define rforn(i,n)          for(int i = n - 1; i >= 0; i--)
#define print(arr)          for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)          for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;

#define _log2(n)            31 - __builtin_clz(n)
#define pop_count(n)        __builtin_popcount(n)

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

const double PI = acos(-1);

double r = 6440;
double s, ang;
string t; 

void _(){
  double R = r + s;
  if(t == "min")ang /= 60.0;
  if(ang > 180) ang = 360 - ang;

  double theta = ang * PI / 180.0;
  double arc = R * theta;
  double chord = 2 * R * sin(theta / 2);

  cout << fixed << setprecision(6)  << arc << " " << chord << endl;
      
    
}

int32_t main(){
    
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  while(cin >> s >> ang >> t){
    _();
  }
 
  return 0;
}