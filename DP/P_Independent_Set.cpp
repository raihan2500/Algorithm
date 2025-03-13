#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, m, dp[N][2];
vector<vector<int>> graph(N);

int dfs(int v, int p, int color){
    if(dp[v][color] != -1)return dp[v][color];

    int ans = 1;
    for(auto child : graph[v]){
        if(child == p)continue;
        int a = dfs(child, v, 0);
        int b = 0;
        if(!color)b = dfs(child, v, 1);
        ans = (ans * (a + b) % M) % M;
    }
    return dp[v][color] = ans;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);  cout.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    memset(dp, -1, sizeof(dp));
    int ans = ((dfs(1, 0, 0) + dfs(1, 0, 1))) % M;
    cout << ans << endl;
}