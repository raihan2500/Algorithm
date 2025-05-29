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

int dp[1 << 25][2];
int n, mp[(1 << 25)];

int recur(int mask, int b){
    if(b == -1)return mp[mask];
    int x = recur(mask, b - 1), y = 0;
    if(mask & (1 << b))y = recur(mask ^ (1 << b), b - 1);
    return x + y;
}

int32_t main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        int num = 0;
        for(auto i : str){num |= (1 << (i - 'a'));}
        mp[num]++;
        dp[num][0]++;
    }

    for(int bit = 25; bit > 0; bit--){
        int b = bit - 1;
        for(int mask = (1 << 24) - 1; mask >= 0; mask--){
            dp[mask][bit & 1] = dp[mask][(bit - 1) & 1];
            if(mask & (1 << b))dp[mask][bit & 1] += dp[mask ^ (1 << b)][(bit - 1) & 1];
        }
    }
    
    cout << dp[3][1] << endl;
}