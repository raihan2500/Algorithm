#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> graph[N];
bool vis[N];
bool isLoopExists = false;

bool dfs(int vertex, int par){
    if(isLoopExists)return true;
    
    vis[vertex] = true;

    for(auto child : graph[vertex]){
        if(child == par)continue;
        if(vis[child])return true;
        isLoopExists = dfs(child, vertex);
    }

    return isLoopExists;

}


int main(){
    int v, e;
    cin >> e >> v;
    for(int i = 0; i < e; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for(int i = 1; i <= v; i++){
        isLoopExists = false;
        if(vis[i])continue;
        if(dfs(i, 0)){
            break;
        }
    }

    cout<<isLoopExists<<endl;
}