#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e3 + 10;
const int M = 200 * 210;

int n, m;
int dp[210][210 * 200];

int recur(int i, int j, vector<vector<int>> &v){

    if(i == n - 1 and j == m - 1)return v[i][j];
    if(i > n or j > m)return M;
    if(dp[i][j] != -1)return dp[i][j];

    int a = v[i][j] + recur(i + 1, j, v);
    int b = v[i][j] + recur(i, j + 1, v);

    return dp[i][j] = min(a, b);
}


int minPathSum(vector<vector<int>>& grid) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    n = grid.size(); m = grid.front().size();
    memset(dp, -1, sizeof(dp));
    
    return recur(0, 0, grid);        
}

int32_t main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){cin >> v[i][j];
        cout << v[i][j] <<" ";}cout << endl;
    }

    cout << minPathSum(v) << endl;
  
}