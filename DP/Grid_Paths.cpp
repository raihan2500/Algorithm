#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 1e3 + 10;

int n;
int dp[N][N];
vector<string> grid;

int recur(int i, int j){
    if(i == n - 1 and j == n - 1)return grid[i][j] == '.';
    if(i >= n or j >= n)return 0;
    if(grid[i][j] == '*')return 0;
    if(dp[i][j] != -1)return dp[i][j];

    int a = recur(i, j + 1);
    int b = recur(i + 1, j);

    return dp[i][j] = (a + b) % M;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(dp, -1, sizeof(dp));

    cin >> n;
    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        grid.push_back(str);
    }

    cout << recur(0, 0) << endl;  
}