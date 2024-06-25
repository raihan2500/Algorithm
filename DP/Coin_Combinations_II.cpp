#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
const int N = 1e6 + 10;
int dp[N];

int32_t main(){
    int n, x;
    cin>>n>>x;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    dp[0] = 1;
    
    for(int i = 0; i < n; i++){
        for(int j =1; j <= x; j++){
            if(v[i] > j)continue;
            dp[j] += dp[j - v[i]];
            dp[j] %= M;
        }
    }
    cout<<dp[x]<<endl;
    
}

//Credit: https://www.youtube.com/watch?v=xhyDRO9DPgA