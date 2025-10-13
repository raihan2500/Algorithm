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

#define double long double

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
double polygon_area(vector<point> &v){
  int n = v.size();
  double ans = 0;
  for(int i = 0; i < n; i++){
    point p1 = v[i];
    point p2 = v[(i + 1) % n];
    ans += (p1.x*p2.y) - (p2.x*p1.y); 
  }
  return abs(ans / 2.0);
}

/************ Lattice point on a line excluding endpoints *****************/
int lattice_points_on_seg(point a, point b){
  int dx = abs(b.x - a.x);
  int dy = abs(b.y - a.y);
  return __gcd(dx, dy) - 1;
}


/*
  Pick's Theroem: A = i + (b / 2) - 1
  A = area of polygon
  i = lattice point inside polygon
  b = lattice point on the boundary
*/

void _(){
  lin(n);
  vector<point> v(n);
  forn(i,n)cin >> v[i];

  int area = polygon_area(v);
  int bound = n;

  for(int i = 0; i < n; i++){
    point a = v[i];
    point b = v[(i+1)%n];
    bound += lattice_points_on_seg(a, b);
  }
  
  int i = area + 1 - bound / 2;

  cout << i << " " << bound << endl;
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