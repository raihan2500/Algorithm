#include<bits/stdc++.h>
using namespace std;

int n, K;
int v[100005], dp[100005];

int recur(int k){

    if(dp[k] != -1)return dp[k];
    for(int i = 0; i < n; i++){
        if(v[i] <= k and !recur(k - v[i])){
            return dp[k] = true;
        }
    }
    return dp[k] = false;
}

int32_t main(){
    memset(dp, -1, sizeof(dp));

    cin >> n >> K;
    for(int i = 0; i < n; i++)cin >> v[i];

    if(recur(K))cout <<"First" << endl;
    else cout <<"Second" << endl;
}