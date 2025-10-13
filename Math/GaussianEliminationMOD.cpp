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
vector<mint> gauss(vector<vector<mint>> a){
  int n = a.size();
  int m = a[0].size() - 1;
  flag = 1;
  vector<int> pos(m, -1);
  
  for(int i = 0, r = 0; i < m and r < n; i++){
    int p = r;
    for(int j = r; j < n; j++){
      if(a[j][i] != 0){
        p = j; break;
      }
    }
    if(a[p][i] == 0)continue;
    swap(a[p], a[r]);
    pos[i] = r;

    mint div = a[r][i];
    for(int k = i; k <= m; k++)a[r][k] /= div;

    for(int j = r + 1; j < n ; j++){
      mint sub = a[j][i];
      if(sub == 0)continue;
      for(int k = i; k <= m; k++){
        a[j][k] -= sub * a[r][k];
      }
    }
    r++;
  }
  vector<mint> ans(m, 0);
  for(int i = m - 1; i >= 0; i--){
    if(pos[i] == -1){flag = 2; continue;}
    ans[i] = a[pos[i]][m];
    for(int j = i + 1; j < m; j++){
      ans[i] -= a[pos[i]][j] * ans[j];
    }
  }
  if(flag == 2)return ans;

  for(int i = 0; i < n; i++){
    mint sum(-a[i][m].x);
    for(int j = 0; j < m; j++)sum += a[i][j] * ans[j];
    if(sum != 0){
      flag = -1;
      return {};
    }
  }
  return ans;
}

int32_t main(){
  
}