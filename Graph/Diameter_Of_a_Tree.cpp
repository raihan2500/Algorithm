//Maximum distance from one node to another node is called diameter

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int>graph[N];
int depth[N];

void dfs(int vertex, int par = 0){

    for(auto child : graph[vertex]){
        if(child == par)continue;
        depth[child] = depth[vertex] + 1;
        dfs(child,vertex);
    }
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
    int mx_depth = -1;
    int mx_d_node;
    for(int i = 1; i <= n; i++){
        if(depth[i] > mx_depth){
            mx_depth = depth[i];
            mx_d_node = i;
        }
        depth[i] = 0;
    }

    dfs(mx_d_node);

    for(int i = 1; i <= n; i++){
        if(depth[i] > mx_depth){
            mx_depth = depth[i];
        }
    }
    cout<<"Diameter: " << mx_depth<<endl;   
}