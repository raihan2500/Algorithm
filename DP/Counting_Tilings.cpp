#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define DB(...)
#   define db(...) "" 
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, m;
int dp[1005][1 << 11];

void gen(int i, int cur, int next, vector<int>& masks){
    if(i > n){masks.push_back(next); return;}

    if(cur & (1 << i)){
        gen(i + 1, cur, next, masks);
        return;
    }
    gen(i + 1, cur, next | (1 << i), masks);

    if(i < n and (cur & (1 << i + 1)) == 0)
        gen(i + 2, cur, next, masks);
}

int recur(int i, int mask){
    if(i > m)return mask == 0;
    if(dp[i][mask] != -1)return dp[i][mask];

    int ans = 0;
    vector<int> masks;
    gen(1, mask, 0, masks);

    for(auto x : masks){
        ans = (ans + recur(i + 1, x)) % M;
    }
    return dp[i][mask] = ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << recur(1, 0) << endl;
}