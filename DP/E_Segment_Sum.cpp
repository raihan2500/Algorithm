#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, k;
string digits;


int recur(int ind, bool flg, bool lead, int cnt){
    if(ind >= n){
        if(__builtin_popcount(cnt) <= k)return 1;
    }
    
    int ans = 0, limit = flg ? digits[ind] : 9;
    for(int d = 0; d <= limit; d++){
        if(lead and d == 0){
            ans += recur(ind + 1, 0, 1, 0);
            ans %= M; continue;
        }
        ans += recur(ind + 1, flg & (d == limit), 0, cnt | (1 << d));
        ans %= M;
    }

    return ans;
}

int func(int x){
    if(x < 0)return 0;
    // memset(dp, -1, sizeof(dp));
    digits.clear();
    while(x > 0){
        digits.push_back(x % 10);
        x /= 10;
    } n = digits.size();
    reverse(digits.begin(), digits.end());

    return recur(0, 1, 1, 0);
}

int32_t main(){
    int l, r;
    cin >> l >> r >> k;

    int ans = func(r) - func(l - 1);
    cout << ans << endl;

}