#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<sys/Zresource.h>
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n;
string str, rev;
int dp[1005][1005];

int recur(int i = 0, int j = 0){
    if(i >= n or j >= n)return 0;
    if(dp[i][j] != -1)return dp[i][j];

    int x = 0;
    if(str[i] == rev[j])x = 1 + recur(i + 1, j + 1);

    int a = recur(i, j + 1);
    int b = recur(i + 1, j);

    return dp[i][j] = max({x, a, b});
}

int longestPalindromeSubseq(string s) {
    str = s;
    n = str.size();
    rev = str;
    memset(dp, -1, sizeof(dp));

    reverse(all(rev));
    return recur();       
}


int32_t main(){
    cin >> str;
    n = str.size();
    rev = str;
    reverse(rev.begin(), rev.end());
    for(int i = n - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            int x = 0;
            if(str[i] == rev[j])x = 1 + dp[i + 1][j + 1];
            int a = dp[i + 1][j];
            int b = dp[i][j + 1];
            dp[i][j] = max({x, a, b});
        }
    }

    cout << dp[0][0] << endl;
}