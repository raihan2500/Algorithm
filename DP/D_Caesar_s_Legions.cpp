#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e8;
const int N = 100 + 10;

int n1, n2, k1, k2;
int dp[N][N][3];

int recur(int i, int j, bool flg){
    
    if(i >= n1 and j >= n2)return 1;
    if(j >= n2)return (n1 - i) <= k1;
    if(i >= n1)return (n2 - j) <= k2;
    if(dp[i][j][flg] != -1)return dp[i][j][flg];

    int ans = 0;
    if(flg){
        for(int x = 1; x <= k1; x++){
            if(i + x > n1)break;
            ans += recur(i + x, j, !flg);
            ans %= M;
        }

    }else{
        for(int y = 1; y <= k2; y++){
            if(j + y > n2)break;
            ans += recur(i, j + y, !flg);
            ans %= M;
        }
    }

    return dp[i][j][flg] = ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n1 >> n2 >> k1 >> k2;
    memset(dp, -1, sizeof(dp));

    int ans =  recur(0, 0, 0);
    ans += recur(0, 0, 1);
    ans %= M;

    cout << ans << endl;
}