#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e6 + 10;

int n, x;
int dp[N];
vector<int> v;

int recur(int sum){
    if(sum == x)return 1;
    if(dp[sum] != -1)return dp[sum];
    int ans = 0;
    for(auto i : v){
        if(sum + i > x)break;
        ans += recur(sum + i);
        ans %= M;
    }
    return dp[sum] = ans;
}

int32_t main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        int t; cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());

    cout << recur(0) << endl;
}