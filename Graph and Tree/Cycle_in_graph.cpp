#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
const int N = 1e5;

vector<int> graph[N];
vector<bool> vis(N);


bool dfs(int vertex, int par){
    vis[vertex] = true;
    bool isLoopExists = false;
    for(auto child : graph[vertex]){
        if(vis[child] && child == par)continue;
        if(vis[child])return true;

        isLoopExists |= (child, vertex);
    }

    return isLoopExists;
}


int32_t main(){
    int v, e;
    cin >> v >> e;

    for(int i = 0; i < e; i++){
        int v1, v2;
        cin >> v1 >> v2;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    bool isLoopExists = false;

    for(int i = 1; i <= v; i++){
        cout<<i<<" ";
        cout<<dfs(i, 0)<<endl;
        if(vis[i])continue;
        if(dfs(i, 0)){
            isLoopExists = true;
            // break;
        }
    }

    cout<<isLoopExists<<endl;
}