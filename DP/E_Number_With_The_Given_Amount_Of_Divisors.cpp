#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 2e18;

int m, n = 10, binPow[50][70];
int pm[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

int dp[60][20][10][5][5][4][2][2][2][2];
vector<int> sz = {60, 15, 8, 3, 3, 2, 2, 2, 2, 2};

#define dpr dp[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]][v[6]][v[7]][v[8]][v[9]]

int recur(vector<int> v){
    __uint128_t cur = 1; int cnt = 1;
    for(int i = 0; i < n; i++){
        cur *= binPow[pm[i]][v[i]];
        cnt *= (v[i] + 1);
        if(cur >= INF)return INF;
        if(sz[i] <= v[i])return INF;
    }
    
    if(cnt == m)return cur;
    if(dpr != -1)return dpr;

    int ans = INF;
    for(int i = 0; i < n; i++){
        int nxt = cur / (v[i] + 1);
        nxt = cur * (v[i] + 2);
        v[i]++;
        if(cnt <= m)ans = min(ans, recur(v));
        v[i]--;
    }

    return dpr = ans;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> m;

    for(int i = 1; i < 50; i++){
        __uint128_t p = 1;
        for(int j = 0; j <= 60; j++){
            binPow[i][j] = p;
            p *= i;
            if(p > INF)break;
        }
    }

    vector<int> v(10);
    memset(dp, -1, sizeof(dp));
    cout << recur(v) << endl;
}