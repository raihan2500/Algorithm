#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;

int dp[5001][301];

int recur(vector<int> &v, int x, int n){

    int ans = 0;
    if(x < 0)return 0;
    if(x == 0)return 1;

    for(int i = 0; i <= n; i++){
        if(i > x)continue;
        if(dp[x - v[i]][i] == -1){
            dp[x - v[i]][i] = recur(v, x- v[i], i);
        }

        ans += dp[x - v[i]][i];
    }

    return ans;
}


int change(int amount, vector<int>& coins) {
    int dp[amount +  1] = {0};
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