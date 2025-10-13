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
  int x, y;
  point(){x = 0, y = 0;}
  point(int x, int y) : x(x), y(y){}
  point(const point &p) : x(p.x), y(p.y){};

  inline point operator + (const point &a)const {return point(x + a.x, y + a.y);}
  inline point operator - (const point &a)const {return point(x - a.x, y - a.y);}
  inline point operator * (const int a)const {return point(x * a, y * a);}
  inline point operator / (const int a)const {return point(x / a, y / a);}

  inline point & operator += (const point &a){x += a.x, y += a.y; return *this;}
  inline point & operator -= (const point &a){x -= a.x, y -= a.y; return *this;}

  inline bool operator == (const point &a) const{return sign(a.x - x) == 0 and sign(a.y - y) == 0;}
  inline bool operator != (const point &a) const{return !(*this == a);}
  inline bool operator < (const point &a)const{ return sign(a.x - x) == 0 ? y < a.y : x < a.x;}
  inline bool operator > (const point &a)const{ return sign(a.x - x) == 0 ? y > a.y : x > a.x;}

  int norm(){return sqrt(x * x + y * y);}
  int norm2(){return x * x + y * y;}
  point perp(){return point(-y, x);} //Perpendicular vector
  int arg(){return atan2(y, x); } //Angle in radian: tan-1(y / x); range: -PI to PI
  point truncate(int r){
    int k = norm();
    if(!sign(k))return *this;
    r /= k;
    return point(x * r, y * r);
  }

  friend std::ostream& operator<<(std::ostream &os, const point &a){return os <<"(" << a.x <<", " << a.y <<")";}
  friend std::istream& operator >>(std::istream &is, point &a){return is >> a.x >> a.y;}
} p0;


int orient(point a, point b, point c){
  int cross = (c.y - a.y)*(b.x - a.x) - (b.y - a.y)*(c.x - a.x);
  if(cross == 0)return 0;   //same line
  return cross > 0 ? 1 : -1; // left (+1) : right (-1)
}

/************* point c lies on ab line or not **************/
bool on_segment(point a, point b, point c){ 
  if(orient(a, b, c))return false;
  return (c.x >= min(a.x, b.x) and c.x <= max(a.x, b.x)) and (c.y >= min(a.y, b.y) and c.y <= max(a.y, b.y));
}

/************* ab and cd lines are intersecting or not ***************/
bool line_intersect(point a, point b, point c, point d){
  int o1 = orient(a, b, c);
  int o2 = orient(a, b, d);
  int o3 = orient(c, d, a);
  int o4 = orient(c, d, b);

  if(o1 != o2 and o3 != o4)return true;
  else if(!o1 and on_segment(a, b, c))return true;
  else if(!o2 and on_segment(a, b, d))return true;
  else if(!o3 and on_segment(c, d, a))return true;
  else if(!o4 and on_segment(c, d, b))return true;
  else return false;
}

/************* area of a polygon of v[0], v[1],...v[n - 1] points *************/
int polygon_area(vector<point> &v){
  int n = v.size();
  int ans = 0;
  for(int i = 0; i < n; i++){
    point p1 = v[i];
    point p2 = v[(i + 1) % n];
    ans += (p1.x*p2.y) - (p2.x*p1.y); 
  }
  return abs(ans / 2.0);
}

/************** point wrt a polygon is inside: -1, boundary: 0, outside: 1 **************/
int point_in_polygon(vector<point> &v, point p){
  int n = v.size(); assert(n >= 3);
  int a = orient(v[0], v[1], p), b = orient(v[0], v[n - 1], p);
  if(a < 0 or b > 0)return 1;
  int lo = 1, hi = n - 1;
  while(hi > lo + 1){
    int mid = (hi + lo) >> 1;
    if(orient(v[0], v[mid], p) >= 0)lo = mid;
    else hi = mid;
  }
  int k = orient(v[lo], v[hi], p);
  if(k <= 0)return -k;
  if(lo == 1 and a == 0)return 0;
  if(hi == n - 1 and b == 0)return 0;
  return -1;
}


void _(){
  int n, m;
  cin >> n >> m;
  vector<point> v(n);
  forn(i,n)cin >> v[i];

  while(m--){
    point p;  cin >> p;
    int q = point_in_polygon(v, p);
    if(q == -1)cout << "INSIDE\n";
    else if(q == 0)cout << "BOUNDARY\n";
    else cout << "OUTSIDE\n";
    continue;
  }
  
  
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