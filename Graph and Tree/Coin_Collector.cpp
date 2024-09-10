#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, val[N], vis[N], dp[N];
vector<int> graph[N], c;
vector<vector<int>> cc;
void dfs(int vertex){
    if(vis[vertex])return;
    vis[vertex] = true;
    c.push_back(vertex);
    for(auto child : graph[vertex]){
        dfs(child);
    }
}

int recur(int vertex){
    if(dp[vertex] != 0)return dp[vertex];
    if(vis[vertex])return 0;
    vis[vertex] = true;

    int mx = 0;
    for(auto child : graph[vertex]){
        mx = max(mx, recur(child));
    }
    return dp[vertex] = val[vertex] + mx;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> val[i];
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    } 
    
    for(int i = 1; i <= n; i++){
        cout << i <<" ";
        for(auto x : graph[i]){
            cout << x << " ";
        }
        cout << endl;
    }

}