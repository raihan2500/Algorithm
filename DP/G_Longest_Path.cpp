#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, m;
vector<int> graph[N], vis(N, 0), dp(N, -1);

int dfs(int vertex){

    if(dp[vertex] != -1)return dp[vertex];
    vis[vertex] = true;
    
    int ans = 0;
    for(auto child : graph[vertex]){
        ans = max(ans, dfs(child));
    }
    return dp[vertex] = ans + 1;
}

int32_t main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i])continue;
        ans = max(ans, dfs(i));
    }

    cout << ans - 1<< endl;

}