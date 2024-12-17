#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 1000 + 10;

int n, m;
string a, b;
int dp[N][N];

int recur(int i, int j){
    
    if(i >= n or j >= m)return 0;
    if(dp[i][j] != -1)return dp[i][j];

    int x = 0, y = 0, z = 0;
    if(a[i] == b[j]) x = 1 + recur(i + 1, j + 1);

    y = recur(i + 1, j);
    z = recur(i, j + 1);

    return dp[i][j] = max(x, max(y, z));
}

int longestCommonSubsequence(string text1, string text2) {
    memset(dp, -1,sizeof(dp));
    a = text1, b = text2;
    n = a.size(), m = b.size();

    return recur(0, 0);        
}

int32_t main(){
    cin >> a >> b;

    cout << longestCommonSubsequence(0, 0) << endl;
}