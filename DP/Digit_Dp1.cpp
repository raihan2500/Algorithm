#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<sys/Zresource.h>
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n;
string digits;
int dp[20][2][100];

int recur(int ind = 0, bool tight = 1, int cnt = 1){
    if(ind == n)return cnt;
    if(dp[ind][tight][cnt] != -1) return dp[ind][tight][cnt];

    int ans = 0, limit = (tight ? digits[ind] - '0' : 9);
    for(int d = 0; d <= 9; d++){
        ans += recur(ind + 1, (tight & (d == digits[ind] - '0')), cnt + d == 3);
    }    

    return dp[ind][tight][cnt] = ans;
}

int calculate(int x){
    memset(dp, -1, sizeof(dp));
    digits = to_string(x);
    n = digits.size();
    return recur(0);
}


int32_t main(){
  
}