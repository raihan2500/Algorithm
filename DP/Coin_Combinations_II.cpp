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

int n, x, v[101], dp[2][N];

int32_t main(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++)cin >> v[i];
    
    dp[(n + 1) & 1][0] = 1;
    for(int i = n; i >= 1; i--){
        for(int j = 0; j <= x; j++){
            int pos = i & 1;
            dp[pos][j] = dp[!pos][j];
            if(j >= v[i])dp[pos][j] += dp[pos][j - v[i]];
            dp[pos][j] %= M;
        }
    }
    
    cout << dp[1][x] << endl;
}