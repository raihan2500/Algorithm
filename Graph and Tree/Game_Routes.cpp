#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int M = 1e9 + 7;
vector<int> graph[N], val(N);
int vis[N];
int dp[N];
int n, m;

int recur(int vertex){
    if(vertex == n)return 1;
    if(dp[vertex] != 0)return dp[vertex];
    if(vis[vertex])return 0;
    vis[vertex] = true;
    int ans = 0;
    for(auto child : graph[vertex]){
        ans += recur(child);
        ans %= M;
    }
    return dp[vertex] = ans;
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }   

    cout << recur(1) << endl;

    

}