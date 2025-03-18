#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int M = 1e9 + 7;
const int N = 505;
int n, m, q;
vector<vector<int>> graph(N, vector<int> (N, INF));
int32_t main(){
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        graph[x][y] = min(graph[x][y], z);
        graph[y][x] = min(graph[y][x], z);
    }
    for(int i = 1; i <= n; i++)graph[i][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                graph[u][v] = min(graph[u][v], graph[i][u] + graph[v][i]);
            }
        }
    }

    while(q--){
        int x, y;
        cin >> x >> y;
        if(graph[x][y] != INF)
            cout << graph[x][y] << endl;
        else cout << -1 << endl;
    }
}