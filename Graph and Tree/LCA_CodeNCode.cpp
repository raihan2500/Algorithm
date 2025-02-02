#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define DB(...)
#   define db(...) "" 
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int level[N], parent[N];
vector<vector<int>> graph(N);

void dfs(int vertex, int par = 0){
    parent[vertex] = par;
    for(auto child : graph[vertex]){
        if(child == par)continue;

        level[child] = level[vertex] + 1; 
        dfs(child, vertex);
    }
}

int Lca(int a, int b){
    if(level[a] < level[b])swap(a, b);
    
    int dist = level[a] - level[b];
    while(dist > 0)
        a = parent[a];

    //Or We can write this also
    // while(level[a] > level[b])
    //     a = parent[a];
        
    while(a != b){
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int32_t main(){
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1);

    int x, y;
    cin >> x >> y;
    cout << Lca(x, y) << endl;
}

/*
tree:
8
1 2
2 3
2 4
3 7
7 8
4 5
4 6
query:
7 6
*/