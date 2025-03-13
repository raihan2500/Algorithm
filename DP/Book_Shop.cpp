#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, x;
int price[N], pages[N], dp[N];

int32_t main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++)cin >> price[i];
    for(int j = 0; j < n; j++)cin >> pages[j];

    for(int i = 0; i < n; i++){
        for(int j = x; j >= price[i]; j--){
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }
    cout << dp[x] << endl;
}