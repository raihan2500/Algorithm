#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, dp[50];

int recur(int i){
    if(i == n)return 1;
    if(i > n)return 0;
    if(dp[i] != -1)return dp[i];
    
    return dp[i] = recur(i + 1) + recur(i + 2) + recur(i + 3);
}

int32_t main(){
    memset(dp, -1, sizeof(dp));
    cin >> n;
    cout << recur(0) << endl;
  
}