#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
const int N = 1e5;

vector<int> graph[N];
vector<bool> vis(N);

void dfs(int vertex, int parent){

    if(vis[vertex] && vertex != parent){
        
    }

    vis[vertex] = true;

    for(auto child : graph[vertex]){
        dfs(child, parent);
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

    
}