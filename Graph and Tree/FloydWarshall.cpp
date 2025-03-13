#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int32_t main(){
    int n, m;
    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    
    //Edge input
    // for(int i = 0; i < m; i++){
    //     int x, y, wt;
    //     cin >> x >> y >> wt;
    //     graph[x][y] = wt;
    // }
    

    //Matrix Input
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> graph[i][j];
            if(graph[i][j] == 0)graph[i][j] = INF;
        }
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << graph[i][j] <<" ";
        }
        cout << endl;
    }
  
}