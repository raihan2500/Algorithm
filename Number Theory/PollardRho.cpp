#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;


int mult(int a, int b, int mod){
    return (__uint128_t) a * b % mod;
}
int f(int x, int c, int mod){
    return (mult(x, x, mod) + c) % mod;
}

int rho(int n){
    mt19937 mt(time(0));
    int c = 1 + mt() % (n - 1);
    int x = 2 + mt() % (n - 2);
    int y = x;
    int d = 1;
    int cpu = 0;
    while(d == 1){cpu++;
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        d = gcd(abs(x - y), n);
    }
    cerr << cpu << endl;
    return d;
}

int32_t main(){
    int n;
    cin >> n;
    n = M * M;

    cout << rho(n) <<endl;
  
}