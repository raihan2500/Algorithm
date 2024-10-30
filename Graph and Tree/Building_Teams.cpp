#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;


int n, m;
vector<int> graph[N], color(N);
bool vis[N];

void dfs(int vertex, int col = 1){
    if(vis[vertex])return;
    vis[vertex] = true;

    color[vertex] = col;
    if(col == 1)col = 2;
    else col = 1;

    for(auto child : graph[vertex]){
        dfs(child, col);
    }
}

void sukuna(){
        cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){
        if(vis[i])continue;
        dfs(i, 1);
    }

    for(int v = 1; v <= n; v++){
        for(auto u : graph[v]){
            if(color[u] == color[v]){
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        cout << color[i] << " ";
    } cout << endl;
}



int main(){
    sukuna();
}