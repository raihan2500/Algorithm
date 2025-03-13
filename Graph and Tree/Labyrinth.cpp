#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 1e3 + 10;

int n, m;
int vis[N][N];
char par[N][N];
vector<string> grid;

vector<pair<int, int>> moves = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

bool isValid(int x, int y){
    return x >= 0 and x < n and y >= 0 and y < m;
}

char Direction(int x, int y){
    if(x == 1)return 'D';
    if(x == -1)return 'U';
    if(y == 1)return 'R';
    if(y == -1)return 'L';
    return 'X';
}

pair<int, int> dirToPoint(char c){
    if(c == 'D')return {-1, 0};
    if(c == 'U')return {1, 0};
    if(c == 'R')return {0, -1};
    if(c == 'L')return {0, 1};
    return {0, 0};
}

bool bfs(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = true;

    while(!q.empty()){
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for(auto mv : moves){
            int x = i + mv.first;
            int y = j + mv.second;
            if(!isValid(x, y))continue;
            if(grid[x][y] == '#')continue;
            if(vis[x][y])continue;
            vis[x][y] = true;
            par[x][y] = Direction(mv.first, mv.second);
            if(grid[x][y] == 'B')return true;
            q.push({x, y});
        }
    }  
    return false;  
}

int32_t main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        string str;
        cin >> str;
        grid.push_back(str);
    }

    int x, y;
    for(int i = 0; i < n; i++){
        bool flg = false;
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A'){
                x = i, y = j;
                flg = true;
                break;
            }
        }
        if(flg)break;
    }
    if(bfs(x, y) == false){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        bool flg = false;
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'B'){
                x = i, y = j;
                flg = true;
                break;
            }
        }
        if(flg)break;
    }
    string ans;
    while(grid[x][y] != 'A'){
        ans.push_back(par[x][y]);
        auto pr = dirToPoint(ans.back());
        x += pr.first;
        y += pr.second;
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}