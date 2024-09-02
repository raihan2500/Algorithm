#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
typedef                    long double ld;
#define int                long long

#define yes                cout<<"YES\n"
#define no                 cout<<"NO\n"
#define nl                 cout<<"\n";
#define endl               "\n"

#define lin(n)             int n;cin>>n;
#define vin                vector<int>
#define pr                 pair<int, int>
#define pb(n)              push_back(n)
#define pp                 pop_back()
#define all(x)             x.begin(),x.end()

#define fi                 first
#define se                 second

#define forn(i,e)          for(int i=0;i<e;i++)
#define Forn(i,e)          for(int i=1;i<=e;i++)
#define rforn(i,s)         for(int i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)         for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 1e3 + 100;

vector<string> graph;
vector<vector<char>>val(N, vector<char> (N));
vector<vector<pr>> par(N, vector<pr> (N));

bool vis[N][N], flg = 0;
int n, m;


vector<pr> movements = {
    {1, 0},
    {-1, 0}, 
    {0, 1},
    {0, -1}
};

char indentify(int x, int y){
    if(x == 0){
        if(y == 1)return 'R';
        else return 'L';
    }
    if(x == 1)return 'D';
    if(x == -1)return 'U';
    return 'X';
}

bool isValid(int x, int y){
    return x >= 0 && x < n && y >=0 && y < m;
}

void bfs(int x, int y){
    queue<pr> q;
    q.push({x, y});
    vis[x][y] = true;

    while(!q.empty()){
        int vx = q.front().first;
        int vy = q.front().second;
        q.pop();

        for(auto movement : movements){
            int childx = vx + movement.first;
            int childy = vy + movement.second;

            if(!isValid(childx, childy))continue;
            if(graph[childx][childy] == '#')continue;
            if(vis[childx][childy])continue;
            vis[childx][childy] = true;

            par[childx][childy] = {vx, vy};
            val[childx][childy] = indentify(movement.first, movement.second);
            q.push({childx, childy});
            if(graph[childx][childy] == 'B'){
                flg = true;
                return;
            }
        }
    }
}


int32_t main(){
    fast_in_out;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        graph.push_back(str);
    }
    int x = -1, y = -1;

    for(int i = 0; i < n; i++){
        bool ck = 0;
        for(int j = 0; j < m; j++){
            if(graph[i][j] == 'A'){
                x = i;
                y = j;
                ck = 1;
                break;
            }
        }
        if(ck)break;
    }
    bfs(x, y);
    for(int i = 0; i < n; i++){
        bool ck = 0;
        for(int j = 0; j < m; j++){
            if(graph[i][j] == 'B'){
                x = i;
                y = j;
                ck = 1;
                break;
            }
        }
        if(ck)break;
    }

    if(!flg){
        no;
        return 0;
    }

    string ans;
    ans.push_back(val[x][y]);

    for(;graph[x][y] != 'A';){
        pr p = par[x][y];
        x = p.first; y = p.second;
        ans.push_back(val[x][y]);
    }
    ans.pop_back();
    reverse(all(ans));
    yes;
    cout<<ans.size()<<endl;    
    cout<<ans<<endl;
}