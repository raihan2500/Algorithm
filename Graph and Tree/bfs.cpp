#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;

vector<int> graph[N], level(N);
bool vis[N];

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source] = 1;


    while(!q.empty()){
        int vertex = q.front();
        q.pop();

        for(auto child : graph[vertex]){
            if(vis[child])continue;
            q.push(child);
            vis[child] = 1;
            level[child] = level[vertex] + 1;
        }
    }

}


int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    level[5] = 1;
    bfs(5);
    for(int i = 1; i <= 7; i++){
        for(int j = 1; j <= n; j++){
            if(level[j] == i)cout<<j<<" ";
        }
        cout<<endl;
    }

}