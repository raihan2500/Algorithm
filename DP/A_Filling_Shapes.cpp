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


int32_t main(){
    int m;
    cin >> m;
    int ans = 1;
    ans <<= m / 2;
    if(m & 1)ans = 0;
    cout << ans << endl;
}