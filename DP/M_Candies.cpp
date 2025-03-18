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
const int N = 1e5 + 10;

int n, k, v[105], dp[105][N];


int recur(int i, int k){
    if(k == 0)return 1;
    if(i > n)return k == 0;
    if(dp[i][k] != -1)return dp[i][k];
    int ans = 0;
    for(int j = 0; j <= min(v[i], k); j++){
        ans += recur(i + 1, k - j);
        ans %= M;
    }
    return dp[i][k] = ans;
}

int32_t main(){
    cin >> n >> k;
    for(int i = 1; i<= n; i++)cin >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << recur(1, k) << endl;
}