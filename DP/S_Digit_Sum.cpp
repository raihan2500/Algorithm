#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 1e5 + 10;

int n, m;
string digits;
int dp[N][2][2][110];

int recur(int ind, bool flg, bool leading, int cur){
    if(ind >= n)return (cur % m == 0);
    if(dp[ind][flg][leading][cur] != -1)return dp[ind][flg][leading][cur];

    int ans = 0, limit = (flg ? digits[ind] - '0' : 9);

    for(int i = 0; i <= limit; i++){
        if(leading and i == 0){
            ans += recur(ind + 1, false, true, 0);
            ans %= M;    continue;
        }
        int temp = (cur + i) % m;
        ans += recur(ind + 1, flg && (i == limit), false, temp);
        ans %= M;
    }
    return dp[ind][flg][leading][cur] = ans % M;
}

int func(string str){
    memset(dp, -1, sizeof(dp));
    digits = str;
    n = str.size();
    return recur(0, 1, 1, 0);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> digits >> m;
    n = digits.size();

    cout << (func(digits) + M - func("0")) % M << endl;
}