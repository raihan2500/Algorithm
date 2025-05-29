#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 1e6 + 1;

int n, x, v[101], dp[N];

int32_t main(){

    cin >> n >> x;
    for(int i = 1; i <= n; i++)cin >> v[i];  dp[x] = 1;

    for(int j = x; j >= 0; j--){
        for(int i = 1; i <= n; i++){
            if(j + v[i] <= x)dp[j] = (dp[j] + dp[j + v[i]]) % M;
        }
    }
    cout << dp[0] << endl;  
}