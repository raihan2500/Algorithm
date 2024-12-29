#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, m, dp[505][505];
string s, t;

int recur(int i, int j){
    if(i == n)return m - j;
    if(j == m)return n - i;
    if(dp[i][j] != -1)return dp[i][j];

    int a = 1 + recur(i, j + 1);
    int b = 1 + recur(i + 1, j);
    int c = (s[i] != t[j]) + recur(i + 1, j + 1);

    return dp[i][j] = min({a, b, c});
}

int32_t main(){
    memset(dp, -1, sizeof(dp));
    cin >> s >> t;
    n = s.size(), m = t.size();

    cout << recur(0, 0) << endl;
}