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
const int N = 1e6 + 10;
const int B = 20;
int n, v[N], mp[1 << B], dp[1 << (B)][B + 1];
int X = (1 << B) - 1;

#define dpr dp[mask][i]

int recur(int mask, int i){
    if(mask > (1 << B))return 0;
    if(i == -1)return mp[mask];
    if(dpr != -1)return dpr;
    int a = recur(mask, i - 1), b = 0;
    if(!(mask & (1 << i)))b = recur(mask ^ (1 << i), i - 1);
    return dpr = a + b;
}

int32_t main(){
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> v[i], mp[v[i]]++;
    memset(dp, -1, sizeof(dp));
    for(int mask = 0; mask < (1 << B); mask++){
        recur(mask, B);
    }

    for(int i = 0; i < B; i++){
        for(int mask = 0; mask < (1 << B); mask++){
            if(mask & (1 << i)){
                mp[mask] += mp[mask ^ (1 << i)]; 
            }
        }
    }

    for(int i = 0; i < 10; i++){
        clog << db(i) << "  Way: " << dp[i][20] << "   Zero: " << mp[(1 << 20) - 1 - i] << endl;
    }
}