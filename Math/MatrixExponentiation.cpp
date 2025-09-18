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

struct Mat{
  int n, m;
  vector<vector<int>> v;
  Mat(){}
  Mat(int n, int m) : n(n), m(m){v.assign(n, vector<int>(m, 0));}
  Mat(vector<vector<int>> v) : v(v){
    n = v.size();
    n ? m = v[0].size() : 0;
  }
  inline void make_unit(){
    assert(n == m);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        v[i][j] = (i == j);
      }
    }
  }
  inline Mat operator + (const Mat &b){
    assert(n == b.n and m == b.m);
    Mat ans = Mat(n, m);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        ans.v[i][j] = (v[i][j] + b.v[i][j]) % M;
      }
    }
    return ans;
  }
  inline Mat operator - (const Mat &b){
    assert(n == b.n and m == b.m);
    Mat ans = Mat(n, m);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        ans.v[i][j] = (v[i][j] - b.v[i][j] + M) % M;
      }
    }
    return ans;
  }
  inline Mat operator * (const Mat &b){
    assert(m == b.n);
    Mat ans = Mat(n, b.m);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < b.m; j++){
        for(int k = 0; k < m; k++){
          ans.v[i][j] = (ans.v[i][j] + 1LL * v[i][k] * b.v[k][j] % M) % M;
        }
      }
    }
    return ans;
  }
  inline Mat operator ^ (int k){
    assert(n == m);
    Mat ans(n, n), t = *this; ans.make_unit();
    while(k){
      if(k & 1)ans = ans * t;
      t = t * t;
      k >>= 1;
    }
    return ans;
  }

  inline Mat& operator += (const Mat& b){return *this = (*this + b);}
  inline Mat& operator -= (const Mat& b){return *this = (*this - b);}
  inline Mat& operator *= (const Mat& b){return *this = (*this * b);}
  inline Mat& operator ^= (const int& k){return *this = (*this ^ k);}
  inline bool operator == (const Mat& b){return v == b.v;}
  inline bool operator != (const Mat& b){return v != b.v;}

  friend std::ostream& operator <<(std::ostream &os, const Mat& a){
    for(int i = 0; i < a.v.size(); i++){
      for(int j = 0; j < a.v[0].size(); j++){
        os << a.v[i][j] << " ";
      }
      os << "\n";
    }
    return os;
  }
};


int32_t main(){
  Mat a({{1, 1}, {1, 0}});

  cout << a << endl;
  
  a ^= 500;

  cout << a << endl;  
}