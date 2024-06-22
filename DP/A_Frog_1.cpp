#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
const int N = 4e5 + 10;
vector<int> v, dp(N, -1);

int frog(int n){
    if(n <= 0)return 0;

    if(dp[n - 2] == -1)
        dp[n - 2] = frog(n - 2);
    if(dp[n - 1] == -1)
        dp[n - 1] = frog(n - 1);

    return dp[n] = min((abs(v[n] - v[n - 1]) + dp[n - 1]), (abs(v[n] - v[n - 2]) + dp[n - 2]));    

}

int32_t main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    dp[1] = abs(v[0] - v[1]);
    if(n >= 2)
        cout<<frog(n - 1)<<endl;
    else cout<<dp[n - 1]<<endl;
    
}