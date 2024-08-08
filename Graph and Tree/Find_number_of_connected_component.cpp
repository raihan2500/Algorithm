#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
const int N = 1e5;

vector<int> graph[N];
vector<bool> vis(N);

vector<vector<int>> cc;
vector<int> current_cc;

void dfs(int vertex){
    if(vis[vertex])return;
    current_cc.push_back(vertex);
    vis[vertex] = true;
    
    for(auto child : graph[vertex]){
        dfs(child);
    }
}


int32_t main(){
    int n, e;
    cin >> n >> e;
    
    for(int i = 0; i < n; i++){
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    int cnt = 0;

    for(int i = 1; i <= n; i++){
        if(vis[i])continue;

        current_cc.clear();
        dfs(i);
        cnt++;
        cc.push_back(current_cc);
    }

    cout<<cnt<<endl;

    for(auto a : cc){print(a)}

    
}