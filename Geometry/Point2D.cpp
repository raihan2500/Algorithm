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



int32_t main(){
  point a, b;
  cin >> a >> b;
  cout << a <<" " << b << endl;
  
}