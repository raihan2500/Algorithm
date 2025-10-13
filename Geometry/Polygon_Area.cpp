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
  return ans;
}

int32_t main(){
  int n; cin >> n;
  vector<point> v(n);
  for(int i = 0; i < n; i++)cin >> v[i];
  int ans = polygon_area(v);
  cout << abs(ans) << endl;
  

}