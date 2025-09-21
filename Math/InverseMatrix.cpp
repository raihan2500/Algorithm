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


struct mint{
    int32_t x;
    inline mint(int x = 0) : x(x % M){};
    inline mint & operator = (int n){return x = n, *this;}
    inline mint & operator += (mint a){return (x += a.x) >= M && (x -= M), *this;}
    inline mint & operator -= (mint a){return (x -= a.x) < 0 && (x += M), *this;}
    inline mint & operator *= (mint a){return x = (uint64_t) x * a.x % M, *this;}
    inline mint & operator %= (mint a){return (x %= a.x), *this;}
    inline mint & operator ++(int32_t){return (*this += 1), *this;}
    inline mint & operator --(int32_t){return (*this -= 1), *this;}
    inline mint & operator ++(){return (*this += 1), *this;}
    inline mint & operator --(){return (*this -= 1), *this;}
    inline mint & operator ^= (int p){
        mint ans = 1, w = *this;
        for(; p; p >>= 1, w *= w)if(p & 1)ans *= w;
        return x = ans.x, *this;
    };

    inline mint & operator /= (mint a){return *this *= (a ^= (M - 2)); }
    friend inline mint operator + (mint a, mint b){return a += b;}
    friend inline mint operator - (mint a, mint b){return a -= b;}
    friend inline mint operator * (mint a, mint b){return a *= b;}
    friend inline mint operator / (mint a, mint b){return a /= b;}
    friend inline mint operator % (mint a, mint b){return a %= b;}
    friend inline mint operator ^ (mint a, mint b){return a ^= b.x;}
    friend inline mint operator ^ (mint a, int b){return a ^= b;}
    friend inline mint operator & (mint a, mint b){return a.x & b.x;}
    friend inline mint operator | (mint a, mint b){return a.x | b.x;}

    friend inline bool operator < (const mint &a, const mint &b){return a.x < b.x;}
    friend inline bool operator > (const mint &a, const mint &b){return a.x > b.x;}
    friend inline bool operator <= (const mint &a, const mint &b){return a.x <= b.x;}
    friend inline bool operator >= (const mint &a, const mint &b){return a.x >= b.x;}
    friend inline bool operator == (const mint &a, const mint &b){return a.x == b.x;}
    friend inline bool operator != (const mint &a, const mint &b){return a.x != b.x;}
    explicit operator bool() const { return x != 0; }


    friend std::ostream& operator<<(std::ostream& os, mint const& a) {return os << a.x;}
    friend std::istream& operator>>(std::istream &is, mint& a){
        int y; is >> y; (y %= M) < 0 && (y += M); 
        return a.x = y, is;        
    }
};


int flag = 1;
vector<vector<mint>> Inverse(vector<vector<mint>> a){
  int n = a.size(); 
  vector<int> col(n); flag = 1;
  vector<vector<mint>> ans(n, vector<mint>(n));
  for(int i = 0; i < n; i++)ans[i][i] = 1, col[i] = i;

  for(int i = 0; i < n; i++){
    int r = i, c = i;
    for(; r < n ; r++){
      for(c = i; c < n; c++){
        if(a[r][c] != 0){
          goto found;
        }
      }
    }
    flag = 0;
    return {};
    found:
    a[i].swap(a[r]); ans[i].swap(ans[r]);
    for(int j = 0; j < n; j++){
      swap(a[j][i], a[j][c]);
      swap(ans[j][i], ans[j][c]);
    }
    swap(col[i], col[c]);

    mint div = 1 /a[i][i];
    for(int j = 0; j < n; j++)a[i][j] *= div;
    for(int j = 0; j < n; j++)ans[i][j] *= div;

    for(int j = i + 1; j < n; j++){
      mint f = a[j][i];
      for(int k = 0; k < n; k++)a[j][k] -= f * a[i][k];
      for(int k = 0; k < n; k++)ans[j][k] -= f * ans[i][k];
    }
  }
  for(int i = n - 1; i > 0; i--){
    for(int j = 0; j < i; j++){
      mint f = a[j][i];
      for(int k = 0; k < n; k++){
        ans[j][k] -= ans[i][k] * f;
      }
    }
  }
  return ans;
}


int32_t main(){
  vector<vector<mint>> ans, v = {{2, 3}, {1, 4}};
  ans = Inverse(v);
  
}