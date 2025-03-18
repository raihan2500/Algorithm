#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
typedef                    long double ld;
#define int                long long

#define yes                cout<<"YES\n"
#define no                 cout<<"NO\n"
#define nl                 cout<<"\n"
#define endl               "\n"

#define lin(n)             ll n;cin>>n;
#define in(n)              int n;cin>>n;
#define vin                vector<int>
#define pr                 pair<int, int>
#define pb(n)              push_back(n)
#define pp                 pop_back()
#define srt(v)             sort(v.begin(),v.end());
#define all(x)             x.begin(),x.end()

#define fi                 first
#define se                 second
#define mmp                make_pair

#define sz(x)              ((int)(x).size())
#define forn(i,e)          for(int i=0;i<e;i++)
#define Forn(i,e)          for(int i=1;i<=e;i++)
#define rforn(i,s)         for(int i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)         for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long long INF = 1e18;
const int M = 1e9 + 7;

int n, m;
vector<vector<char>> graph;
bool vis[301][301];

void dfs(int x, int y){
    if(x >= n || x < 0)return;
    if(y >= m || y < 0)return;

    if(graph[x][y] == '0')return;

    if(vis[x][y])return;
    vis[x][y] = true;

    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int numIslands(vector<vector<char>>& grid) {
    graph = grid;
    n = graph.size();
    m = graph.front().size();
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(graph[i][j] == '0')continue;
            if(vis[i][j])continue;
            cnt++;
            dfs(i, j);
        }
    }
    return cnt;   
}

int32_t main()
{
    fast_in_out;
    cin >> n >> m;

    forn(i,n){
        vector<char> v(m);
        forn(j, m)cin >> v[j];
        graph.push_back(v);
    }
    
    cout<<numIslands(graph)<<endl;
    
}