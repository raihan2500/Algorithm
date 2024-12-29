#include<bits/stdc++.h>
using namespace std;

#define int long long
#define print(arr) for(auto i : arr)cout << i <<" ";cout << endl;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n;
int dp[11][20][2][2];
vector<int> digits;

int recur(int prev, int ind, bool flg, bool leading){
    if(ind >= n)return 1;
    if(dp[prev][ind][flg][leading] != -1)return dp[prev][ind][flg][leading];

    int ans = 0, limit = (flg ? digits[ind] : 9);

    for(int d = 0; d <= limit; d++){
        if(leading and d == 0){
            ans += recur(10, ind + 1, false, true);
            continue;
        }
        if(prev == d)continue;

        ans += recur(d, ind + 1, flg & (d == limit), 0);
    }
    return dp[prev][ind][flg][leading] = ans;
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

    return recur(10, 0, 1, 1);
}

int32_t main(){
    int a, b;
    cin >> a >> b;
    int ans = func(b) - func(a - 1);
    cout << ans << endl;
}