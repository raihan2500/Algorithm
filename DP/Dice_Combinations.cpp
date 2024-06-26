#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
const int N = 1e6 + 1;
int dp[N];

int recur(int n){
    if(dp[n] > 0)return dp[n];

    if(n == 0)return 1;

    int ans = 0;
    for(int i = 1; i <=6 && i <= n; i++){
        ans += recur(n - i);
        ans %= M;
    }

    return dp[n] = ans;
}


int32_t main(){
    int n;
    cin>>n;
    cout<<recur(n)<<endl;
    
}