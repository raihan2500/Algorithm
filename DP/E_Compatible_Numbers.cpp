    #include<bits/stdc++.h>
    using namespace std;
     
    const int N = 1e6 + 1;
    int n, v[N], dp[1 << 22];
     
    int32_t main(){
        cin >> n;
        for(int i = 1; i <= n; i++)cin >> v[i], dp[v[i]] = v[i];
        
        for(int bit = 0; bit < 22; bit++){
            for(int mask = 0; mask < (1 << 22); mask++){
                if(mask & (1 << bit) and dp[mask ^ (1 << bit)]){
                    dp[mask] = dp[mask ^ (1 << bit)];
                }
            }
        }
        for(int i = 1; i <= n; i++){
            int b = ((1 << 22) - 1) ^ v[i];
            cout << (dp[b] ? dp[b] : -1) <<" ";
        }
    }