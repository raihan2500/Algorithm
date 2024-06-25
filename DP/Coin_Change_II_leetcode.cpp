//Bottom-up approach

#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long

int dp[5001];

int change(int amount, vector<int>& coins) {
    
    dp[0] = 1;
    for(int i = 0; i < coins.size(); i++){
        for(int j = 0; j <= amount; j++){
            if(coins[i] > j)continue;
            dp[j] += dp[j - coins[i]];
        }
    }     
    return dp[amount];
}

int32_t main(){
    int n, x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin>>v[i];

    cout<<change(x, v);
    
    
}
