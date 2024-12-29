#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n;
string digits;
int dp[12][2][2][100];

int recur(int ind, int flg, int lead, int sum){
    if(ind >= n)return sum;
    if(dp[ind][flg][lead][sum] != -1)return dp[ind][flg][lead][sum];

    int ans = 0, limit = flg ? digits[ind] : 9;
    
    for(int d = 0; d <= limit; d++){
        if(lead and d == 0){
            ans += recur(ind + 1, false, true, 0);
            continue;
        }
        ans += recur(ind + 1, flg & (d == limit), false, sum + d);
    }
    return dp[ind][flg][lead][sum] = ans;
}

int func(int x){
    if(x < 0)return 0;
    memset(dp, -1, sizeof(dp));
    digits.clear();
    while(x > 0){
        digits.push_back(x % 10);
        x /= 10;
    } n = digits.size();
    reverse(digits.begin(), digits.end());

    return recur(0, 1, 1, 0);
}

int32_t main(){
    int a, b;
    cin >> a >> b;
    
    while(a != -1 and b != -1){
        int ans = func(b) - func(a - 1);
        cout << ans << endl;
        cin >> a >> b;
    }
}