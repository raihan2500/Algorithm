#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n;
vector<vector<int>> dp;

int recur(int sum, int st, vector<int> &coins){

    if(sum == 0)return 1;
    if(sum < 0)return 0;
    if(st >= n)return 0;
    if(dp[sum][st] != -1)return dp[sum][st];
    
    int ans = 0;
    for(int i = 0; coins[st] * i <= sum; i++){
        ans += recur(sum - i * coins[st], st + 1, coins);
    }
    return dp[sum][st] = ans;
}

int change(int amount, vector<int>& coins) {
    n = coins.size();
    dp = vector<vector<int>> (amount + 1, vector<int> (n + 1, -1));
    return recur(amount, 0, coins);
}


int32_t main(){
    int amount;
    cin >> n >> amount;
    vector<int> coins(n);
    sort(coins.begin(), coins.end());
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    cout << change(amount, coins) << endl;
}