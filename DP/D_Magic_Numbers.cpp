#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e3 + 10;

int m, dig, n;
string digits;
int dp[N][2][2][2][N];


int recur(int ind, bool flg, bool leading, bool even, int cur){

    if(ind >= n)return (cur % m == 0);
    if(dp[ind][flg][leading][even][cur] != -1)return dp[ind][flg][leading][even][cur];
    int ans = 0, limit = (flg ? digits[ind] - '0': 9);
    
    if(even){
        if(flg and limit < dig)return dp[ind][flg][leading][even][cur] = 0;
        else{
            int temp = cur * 10 % m;
            temp = (temp + dig) % m;
            return dp[ind][flg][leading][even][cur] = recur(ind + 1, flg & (limit == dig), false, false, temp) % M;
        }
    }

    for(int d = 0; d <= limit; d++){
        if(leading and d == 0){
            ans += recur(ind + 1, false, true, 0, 0);
            ans %= M; continue;
        }
        if(d == dig)continue;
        int temp = cur * 10 % m;
        temp = (temp + d) % m;

        if(flg and d == limit){
            ans += recur(ind + 1, flg, false, 1, temp);
            ans %= M; continue;
        }
        ans += recur(ind + 1, false, false, 1, temp);
        ans %= M;        
    }

    return dp[ind][flg][leading][even][cur] = ans;

}

int func(string &str){
    memset(dp, -1, sizeof(dp));
    digits = str;
    n = digits.size();

    return recur(0, 1, 1, 0, 0);
}

void decrement(string &str){
    int n = str.size();
    int carry = 1;
    for(int i = n - 1; i >= 0; i--){
        if(str[i] > '0'){
            str[i] --;
            carry = 0;
        }else{
            str[i] = '9';
            carry = 1;
        }
        if(!carry)break;
    }
    if(str.front() == '0')str.erase(str.begin());
    if(str.empty())str.push_back('0');
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    string l, r;
    cin >> m >> dig;
    cin >> l >> r;
    decrement(l);
    int ans = (func(r) + M - func(l)) % M;
    cout << ans << endl;
}