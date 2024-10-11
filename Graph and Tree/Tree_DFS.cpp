#include<bits/stdc++.h>
using namespace std;

const int N = 14;
vector<int> graph[N];
int depth[N], height[N];

void dfs(int vertex, int par){
    //Part 1: After entering vertex

    for(auto child : graph[vertex]){
        if(child == par)continue;
        
        //Part 2: Before entering child

        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);

        //Part 3: After exiting child

        height[vertex] = max(height[vertex], height[child] + 1);
    }

    //Part 4: Before exiting vertex
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
    dfs(1, 0);
    for(int i = 1; i <= v; i++)cout<<depth[i]<<" ";cout<<endl;
    for(int i = 1; i <= v; i++)cout<<height[i]<<" ";cout<<endl;
}
