#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
const int N = 1e6 + 10;
int n, x;
vector<int> v, dp(N, -1);

int recur(int m){
    int ans = INT_MAX;

    if(m < 0 )return -100000;
    if(m == 0)return 0;

    for(int i = 0; i < n; i++){

        if(v[i] > m)continue;
        if(dp[m - v[i]] == -1)dp[m - v[i]] = recur(m - v[i]);
        int sum = dp[m - v[i]];

        if(sum >= 0)ans = min(ans, sum + 1);
    }

    return ans;

}


int32_t main(){    
    cin>>n>>x;
    for(int i = 0; i < n; i++){
        int c; cin>>c;
        v.push_back(c);
    }
    sort(v.rbegin(), v.rend());
    int ans = recur(x);
    if(ans == INT_MAX)cout<<-1<<endl;
    else cout<<recur(x)<<endl;
    
}