#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 5e3 + 10;

string a, b;
int n, m;
int dp[N][N];

int recur(int i, int j){

    if(j >= m)return n - i;
    if(i >= n)return m - j;

    if(dp[i][j] != -1)return dp[i][j];

    int add = 1 + recur(i, j + 1);
    int rem = 1 + recur(i + 1, j);
    int rep = 1 + recur(i + 1, j + 1);
    
    if(a[i] == b[j])rep--;

    return dp[i][j] = min({add, rem, rep});
}


int32_t main(){
    memset(dp, -1, sizeof(dp));
    cin >> a >> b;
    n = a.size(), m = b.size();

    cout << recur(0, 0) << endl;
}