#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, m;
vector<vector<int>> graph(N);


short color[N];
bool has_cycle;
void isCyclic(vector<vector<int>> &graph, int v){
    if(has_cycle || color[v] == 2)return;
    if(color[v] == 1){  has_cycle = true; return;}

    color[v] = 1;
    for(auto child : graph[v]){
        isCyclic(graph, child);
    }
    color[v] = 2;
}

bool checkCycle(vector<vector<int>> &graph){
    for(int i = 0; i <= n; i++)color[i] = 0;
    for(int i = 1; i <= n; i++){
        if(!color[i])isCyclic(graph, i);
        if(has_cycle)return true;
    }
    return false;
}

int32_t main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    cout << checkCycle(graph) << endl;
    char x = 4;
    cout << (int) x << endl;

    cout << sizeof(short) << " " << sizeof(int) << endl;
}