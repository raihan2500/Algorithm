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
const int N = 1e6 + 15;

int n, dp[N];

int32_t main(){
    
    cin >> n;
    memset(dp, ((1 << 5) - 1), sizeof(dp)); dp[n] = 0;

    for(int j = n; j >= 0; j--){
        int x = j;
        while(x > 0){
            dp[j - (x % 10)] = min(dp[j - (x % 10)], 1 + dp[j]);
            x /= 10;
        }
    }
    
    cout << dp[0] << endl;
}