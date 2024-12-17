#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;


int x, y;
int dp[110][110];

int recur(int i, int j){

    if(i == x -1 and j == y - 1)return 1;
    if(i > x or j > y)return 0;
    if(dp[i][j] != -1)return dp[i][j];

    int a = recur(i + 1, j);
    int b = recur(i, j + 1);

    return dp[i][j] = a + b;
}

int uniquePaths(int m, int n) {
    memset(dp, -1, sizeof(dp));
    x = n, y = m;
    return recur(0,0);       
}

int32_t main(){
    int n, m;
    cin >> n >> m;
    cout << uniquePaths(n, m) << endl;
}