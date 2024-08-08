#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
const int N = 1e6 + 10;

vector<int> dp(N);

int32_t main(){
    int n, x ;
    cin >> n >> x;
    vector<int> coins(n);
    for(auto &a : coins)cin >> a;

    dp[0] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= x; j++){
            dp[j + coins[i]] += dp[j];
            dp[j] %= M;
        }
    }

    cout<<dp[x]<<endl;   
}