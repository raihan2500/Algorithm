#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
const int N = 1e5;

vector<int> graph[N];
vector<bool> vis(6);

void dfs(int vertex){
    if(vis[vertex])return;
    vis[vertex] = true;
    // cout<<vertex<<endl;

    for(auto child : graph[vertex]){
        // cout<<"par: "<< vertex << ", child: " << child<<endl;        
        dfs(child);
    }
}
//Time complexity O(Vertex + Edge)

int32_t main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    dfs(1);
    print(vis)   
}
