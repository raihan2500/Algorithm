#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;
using ull = uint64_t;
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
#define pb(n)               push_back(n)
#define all(x)              x.begin(),x.end()
#define ppfr(v)             v.erase(v.begin());
#define sum_all(v)          accumulate(all(v), 0ll)

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


const double eps = 1e-9;
const double PI = acos(-1.0);
int sign(double x){return (x > eps) - (x < -eps);}

struct point{
  double x, y;
  point(){x = 0, y = 0;}
  point(double x, double y) : x(x), y(y){}
  point(const point &p) : x(p.x), y(p.y){};

  inline point operator + (const point &a)const {return point(x + a.x, y + a.y);}
  inline point operator - (const point &a)const {return point(x - a.x, y - a.y);}
  inline point operator * (const double a)const {return point(x * a, y * a);}
  inline point operator / (const double a)const {return point(x / a, y / a);}

  inline point & operator += (const point &a){x += a.x, y += a.y; return *this;}
  inline point & operator -= (const point &a){x -= a.x, y -= a.y; return *this;}

  inline bool operator == (const point &a) const{return sign(a.x - x) == 0 and sign(a.y - y) == 0;}
  inline bool operator != (const point &a) const{return !(*this == a);}
  inline bool operator < (const point &a)const{ return sign(a.x - x) == 0 ? y < a.y : x < a.x;}
  inline bool operator > (const point &a)const{ return sign(a.x - x) == 0 ? y > a.y : x > a.x;}

  double norm(){return sqrt(x * x + y * y);}
  double norm2(){return x * x + y * y;}
  point perp(){return point(-y, x);} //Perpendicular vector
  double arg(){return atan2(y, x); } //Angle in radian: tan-1(y / x); range: -PI to PI
  point truncate(double r){
    double k = norm();
    if(!sign(k))return *this;
    r /= k;
    return point(x * r, y * r);
  }

  friend std::ostream& operator<<(std::ostream &os, const point &a){return os <<"(" << a.x <<", " << a.y <<")";}
  friend std::istream& operator >>(std::istream &is, point &a){return is >> a.x >> a.y;}
} p0;


void _(){
  lin(n);
  vector<point> v(n);
  forn(i,n)cin >> v[i];
  map<pr, int> mp;

  int ans = 0;

  for(int i = 0; i < n; i++){
    for(int j = i + 1; j < n; j++){
      pr p(v[i].x + v[j].x, v[j].y + v[i].y);
      ans += mp[p];
      mp[p]++;
    }
  }
  
  cout << ans << endl;
  
}

int32_t main(){
    
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int test = 1;  
  // cin>>test;
  for(int i = 1; i <= test; i++){
      // cout << "Case " << i <<": ";
      _();
  }
  return 0;
}
