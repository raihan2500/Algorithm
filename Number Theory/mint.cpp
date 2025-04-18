#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define DB(...)
#   define db(...) "" 
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

struct mint{
    int x;
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



int32_t main(){
    mint a = 6, b = 2;
    cout << a / b << endl; //Modular division here 6 / 2 = 3
    cout << (a ^ b) << endl; // 6 power 2 = 36
}