#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
typedef                    long double ld;

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
const int N = 1e2;
int n, m, c;

vector<vin> graph;
bool vis[N][N];

void dfs(int x, int y){

    if(vis[x][y])return;

    int cc = graph[x][y];
    vis[x][y] = true;

    if(x + 1 < n){
        if(graph[x + 1][y] == cc and vis[x + 1][y] == 0){
            dfs(x + 1, y);
        }
    }
    if(x - 1 >= 0){
        if(graph[x - 1][y] == cc and vis[x - 1][y] == 0){
            dfs(x - 1, y);
        }
    }

    if(y + 1 < m){
        if(graph[x][y + 1] == cc and vis[x][y + 1] == 0){
            dfs(x, y + 1);
        }
    }
    if(y - 1 >= 0){
        if(graph[x][y - 1] == cc and vis[x][y - 1] == 0){
            dfs(x, y - 1);
        }
    }

    graph[x][y] = c;

}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    graph = image;
    n = graph.size();
    m = graph.front().size();
    c = color;
    dfs(sr, sc);

    return graph;
}


int32_t main()
{
    fast_in_out;
    cin >> n >> m;
    forn(i,n){
        vin v(m);
        forn(j, m)cin >> v[j];
        graph.push_back(v);
    }
    
    int x, y;
    cin >> x >> y >> c;
    
    

    for(auto a : floodFill(graph, x, y, c)){
        print(a);
    }



    
}