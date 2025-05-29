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

int n, v[N], dp[1 << 20], nd[1 << 20];

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)cin >> v[i], dp[v[i]]++, nd[v[i]]++;

    for(int bit = 0; bit < 20; bit++){
        for(int mask = 0; mask < (1 << 20); mask++){
            int b = bit;
            if(mask & (1 << b)){
                dp[mask] += dp[mask ^ (1 << b)];
            }           
        }
    }

    for(int i = 0; i < 20; i++){
        for(int mask = 0; mask < (1 << 20); mask++){
            if(!(mask & (1 << i))){
                nd[mask] += nd[mask ^ (1 << i)];
            }
        }
    }


    for(int i = 1; i <= n; i++){
        cout << dp[v[i]] <<" " << nd[v[i]] << " " << n - dp[(1 << 20) - 1 - v[i]] << endl;
    }
}