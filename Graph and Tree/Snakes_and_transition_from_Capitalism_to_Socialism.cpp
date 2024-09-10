#include<bits/stdc++.h>
using namespace std;

const int N = 5e2 + 10;
vector<vector<int>> graph;
bool vis[N][N];
int n, m, lev[N][N];

vector<pair<int, int>> movements = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1}, //Sides
    {1, 1}, {-1, -1}, {1, -1}, {-1, 1} //Corner
};

bool isValid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}


void bfs(vector<pair<int, int>> p){
    queue<pair<int, int>> q;
    for(auto i : p){
        q.push({i.first, i.second});
        vis[i.first][i.second] = 1;
    }

    while(!q.empty()){
        int vx = q.front().first;
        int vy = q.front().second;
        q.pop();

        for(auto mv : movements){
            int childx = vx + mv.first;
            int childy = vy + mv.second;

            if(!isValid(childx, childy))continue;
            if(vis[childx][childy])continue;
            vis[childx][childy] = true;

            q.push({childx, childy});
            lev[childx][childy] = lev[vx][vy] + 1;
        }        
    }
}

void solve(){
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m));
    int mx = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v[i][j];
            mx = max(v[i][j], mx);

            vis[i][j] = 0;
            lev[i][j] = 0;
        }
    }
    vector<pair<int, int>> p;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(v[i][j] == mx){
                p.push_back({i, j});
            }
        }
    }
    bfs(p);
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // cout << lev[i][j] <<' ';
            ans = max(ans, lev[i][j]);
        }
        // cout << endl;
    }
    cout << ans << endl;
}

int main(){
    int test;
    cin >> test;
    while(test--)solve();
}