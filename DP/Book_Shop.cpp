#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 1e4 + 2;

int n, X;
int h[N], s[N];
int dp[1002][N];

int recur(int i, int x){

    if(i >= n)return 0;
    if(x == 0)return 0;
    if(dp[i][x] != -1)return dp[i][x];

    int a = recur(i + 1, x);
    int b = 0;
    if(h[i] <= x)b = s[i] + recur(i + 1, x - h[i]);

    return dp[i][x] = max(a, b);
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> n >> X;
    for(int i = 0; i < n; i++)cin >> h[i];
    for(int i = 0; i < n; i++)cin >> s[i];

    cout << recur(0, X) << endl;
}