#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 5e3 + 10;

int n;
int v[N];
int dp[N][N][2];

int recur(int i, int j, bool flg){

    if(i > j)return 0;
    if(dp[i][j][flg] != -1)return dp[i][j][flg];

    if(flg){
        int a = v[i] + recur(i + 1, j, !flg);
        int b = v[j] + recur(i, j - 1, !flg);
        return dp[i][j][flg] = max(a, b);
    }else{
        int a = recur(i + 1, j, !flg);
        int b = recur(i, j - 1, !flg);
        return dp[i][j][flg] = min(a, b);
    }
}

int32_t main(){
    memset(dp, -1, sizeof(dp));

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    cout << recur(0, n - 1, 1);
}