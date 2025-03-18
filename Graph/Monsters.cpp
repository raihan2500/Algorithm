#include<bits/stdc++.h>
using namespace std;

#define printvis            for(int i = 0; i < n; i++){for(int j = 0; j < m; j++){cout<<vis[i][j]<<' ';}cout<<endl;} 
const int N = 1e3 + 10;
int n, m;
vector<string> graph;
vector<vector<pair<int, int>>> par(N, vector<pair<int, int>> (N));
vector<vector<char>> val(N, vector<char> (N));
bool vis[N][N], isPossible = false, monster = true;

vector<pair<int, int>> movements = {
    {1, 0},
    {-1, 0}, 
    {0, 1},
    {0, -1}
};

bool isValid(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}


char indentify(int x, int y){
    if(x == 0){
        if(y == 1)return 'R';
        else return 'L';
    }
    if(x == 1)return 'D';
    if(x == -1)return 'U';
    return 'X';
}


void bfs(int vx, int vy){
    int x = vx, y = vy;
    queue<pair<int, int>> q;
    q.push({x, y});
    if(vis[x][y])return;
    vis[x][y] = true;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(auto mv : movements){
            int a = x + mv.first;
            int b = y + mv.second;

            if(!isValid(a, b))continue;
            if(vis[a][b])continue;
            if(graph[a][b] == 'A' && monster)continue;
            vis[a][b] = true;

            if(graph[a][b] == '#')continue;
            if(graph[a][b] == 'M')continue;


            q.push({a, b});
            par[a][b] = {x, y};
            val[a][b] = indentify(mv.first, mv.second);

            if(a == 0 || a == n - 1 || b == 0 || b == m - 1){
                if(monster)continue;
                isPossible = true;
                return;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        graph.push_back(str);
    }
    int x, y;
    vector<pair<int, int>> monsterLocation;

    int i = 0, j = 0;
    for(; i < n; i++){
        for(j = 0; j < m; j++){
            if(graph[i][j] == 'A'){
                x = i; 
                y = j;
            }
            if(graph[i][j] == 'M'){
                monsterLocation.push_back({i, j});
            }
        }
    }
    if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
        cout<<"YES\n0\n";
        return 0;
    }

    for(auto i : monsterLocation){
        bfs(i.first, i.second);
    }


    monster = !monster;
    bfs(x, y);

    if(!isPossible){
        cout<<"NO"<<endl;
        return 0;
    }

    bool flg = true;
    for(int i = 0; i < n; i++)if(vis[i][0] && graph[i][0] == '.'){x = i; y = 0; flg = 1; break;}
    for(int i = 0; i < n; i++)if(vis[i][m - 1] && graph[i][m - 1] == '.'){x = i; y = m - 1; flg = 1; break;}
    for(int i = 0; i < m; i++)if(vis[0][i] && graph[0][i] == '.'){x = 0; y = i; flg = 1; break;}
    for(int i = 0; i < m; i++)if(vis[n - 1][i] && graph[n - 1][i] == '.'){x = n - 1; y = i; flg = 1; break;}

    string ans;
    ans.push_back(val[x][y]);

    for(;graph[x][y] != 'A';){
        pair<int, int> p = par[x][y];
        x = p.first; y = p.second;
        ans.push_back(val[x][y]);
    }
    ans.pop_back();
    reverse(ans.begin(), ans.end());

    cout<<"YES"<<endl;
    cout<<ans.size()<<endl;
    cout<<ans<<endl;  


    

}