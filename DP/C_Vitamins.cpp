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

int n, cost[N], vit[N];

int32_t main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        string str;
        cin >> cost[i] >> str;
        int v = 0;
        for(auto c : str)v |= (1 << (c - 'A'));
        vit[i] = v;
    }

    int dp[n + 1][8];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= 7; j++){
            dp[i][j] = (i == n and j == 7) ? 0 : M;
        }
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = 7; j >= 0; j--)
        dp[i][j] = min(dp[i + 1][j], cost[i] + dp[i + 1][j | vit[i]]);
    }
    
    cout << (dp[0][0] == M ? -1 : dp[0][0]) << endl;
}