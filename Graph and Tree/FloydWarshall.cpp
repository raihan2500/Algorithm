#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, m;
vector<vector<int>> graph(N, vector<int> (N, INF));

int32_t main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)graph[i][i] = 0;
    
    for(int i = 0; i < m; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        graph[x][y] = wt;
        graph[y][x] = wt;
    }

    //Algortithm
    for(int i = 1; i <= n; i++){
        for(int x = 1; x <= n; x++){
            for(int y = 1; y <= n; y++){
                graph[x][y] = min(graph[x][y], graph[x][i] + graph[i][y]);
            }
        }
    }
}