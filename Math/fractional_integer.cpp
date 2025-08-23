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


struct frac {
  int a = 1, b = 1;
  void norm(int &x, int &y){
    int g = gcd(x, y);
    x /= g; y /= g;
    if(y < 0){ x = -x; y = -y; }
  }

  frac(int a = 1, int b = 1) : a(a), b(b) {
    norm(this->a, this->b);
  }

  inline frac & operator *= (const frac &i){
    a *= i.a; b *= i.b;
    norm(a, b);
    return *this;
  }

  inline frac & operator /= (const frac &i){
    a *= i.b; b *= i.a;
    norm(a, b);
    return *this;
  }

  inline frac & operator += (const frac &i){
    int d = lcm(b, i.b);
    a = a * (d / b) + i.a * (d / i.b);
    b = d;
    norm(a, b);
    return *this;
  }

  inline frac & operator -= (const frac &i){
    int d = lcm(b, i.b);
    a = a * (d / b) - i.a * (d / i.b);
    b = d;
    norm(a, b);
    return *this;
  }

  friend inline frac operator + (frac a, const frac &b){ return a += b; }
  friend inline frac operator - (frac a, const frac &b){ return a -= b; }
  friend inline frac operator * (frac a, const frac &b){ return a *= b; }
  friend inline frac operator / (frac a, const frac &b){ return a /= b; }

  friend inline bool operator < (const frac &x, const frac &y){ return (int64_t)x.a * y.b < (int64_t)y.a * x.b; }
  friend inline bool operator <= (const frac &x, const frac &y){ return (int64_t)x.a * y.b <= (int64_t)y.a * x.b; }
  friend inline bool operator > (const frac &x, const frac &y){ return (int64_t)x.a * y.b > (int64_t)y.a * x.b; }
  friend inline bool operator >= (const frac &x, const frac &y){ return (int64_t)x.a * y.b >= (int64_t)y.a * x.b; }
  friend inline bool operator == (const frac &x, const frac &y){ return (x.a == y.a && x.b == y.b); }
  friend inline bool operator != (const frac &x, const frac &y){ return !(x == y); }

  friend inline ostream & operator << (ostream &os, const frac &x){ return os << x.a << "/" << x.b; }
  friend inline istream & operator >> (istream &is, frac &x){ return is >> x.a;}
};

int32_t main(){
  frac x(5, 4), y(5, 6);
  cout << x <<" " << y << endl;
  cout << x + y << endl;
}