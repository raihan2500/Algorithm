#include<bits/stdc++.h>
using namespace std;

#define int long long

#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define DB(...)
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

  friend inline ostream & operator << (ostream &os, const frac &x){ if(x.a == 0){return os << "0  ";} return os << x.a << "/" << x.b; }
  friend inline istream & operator >> (istream &is, frac &x){ return is >> x.a;}
};

#define double frac

const double eps = 1e-9;

frac fabs(frac a){
  float x = a.a * 1.0 / a.b;
  return fabs(x);
}

void show(vector<vector<double>> a){
  int n = a.size();
  int m = a[0].size() - 1;
  forn(i,n){
    forn(j,m){
      clog << a[i][j] <<" ";
    }
    cnl;
  }
  cnl;
}

vector<double> gauss(vector<vector<double>> a){
  int n = a.size();
  int m = a[0].size() - 1;

  for(int i = 0, r = 0; i < m and r < n; i++){
    int p = r;
    for(int j = r; j < n; j++){
      if(fabs(a[j][i]) > fabs(a[p][i])){
        p = j;
      }
    }
    if(fabs(a[p][i]) < eps)continue;
    swap(a[p], a[r]);

    double div = a[r][i];
    for(int k = i; k <= m; k++){
      a[r][k] /= div;
    }

    for(int j = r + 1; j < n; j++){
      double sub = a[j][i];
      if(fabs(sub) < eps)continue;
      for(int k = i; k <= m; k++){
        a[j][k] -= sub * a[r][k];
      }
    }
    show(a);
    r++;
  }

  vector<double> ans(m, 0);
  for(int i = m - 1; i >= 0; i--){
    ans[i] = a[i][m];
    for(int j = i + 1; j < m; j++){
      ans[i] -= a[i][j] * ans[j];
    }
  }

  return ans;
}


int32_t main(){
  int n, m;
  cin >> n >> m;
  vector<vector<double>> v(n, vector<double> (m + 1));
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= m; j++){
      cin >> v[i][j];
    }
  }

  print(gauss(v));

}