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
const int N = 1e6 + 10;

int n, dp[N];

int32_t main(){
    cin >> n;
    dp[n] = 1;
    for(int j = n; j >= 0; j--){
        for(int i = 1; i <= 6; i++){
            dp[j] += dp[j + i];
            dp[j] %= M;
        }
    }
    cout << dp[0] << endl;
}