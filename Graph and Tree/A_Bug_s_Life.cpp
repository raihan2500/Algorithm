#include<bits/stdc++.h>
using namespace std;

#define int                long long

#define yes                cout<<"YES\n"
#define no                 cout<<"NO\n"
#define nl                 cout<<"\n"
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
const int N = 2e6 + 100;
vector<int> graph[N], vis(N), height(N), depth(N);
int n,m;
vector<char> gender(N);
bool isSuspicious = false;

void dfs(int vertex = 1, int par = -1, char g = 'M'){

    if(vis[vertex]){
        if(gender[par] == gender[vertex]) isSuspicious = true;
        return;
    }
    vis[vertex]= true;
    gender[vertex] = g;

    if(g == 'M')g = 'F';
    else g = 'M';

    for(auto child : graph[vertex]){
        if(child == par)continue;
        dfs(child, vertex, g);
    }
}

void reset(){
    for(int i = 1; i <= n; i++){
        graph[i].clear();
        vis[i] = 0;
        height[i] = 0;
        depth[i] = 0;
        gender[i] = ' ';
    }
    isSuspicious = false;
}

void sukuna(int test){
    cout << "Scenario #" << test <<":\n";

    cin >> n >> m;
    reset();
    for(int i = 0; i < m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for(int i = 1; i <= n; i++){
        if(vis[i])continue;
        dfs(i, 0, 'M');
    }

    if(isSuspicious){
        cout <<"Suspicious bugs found!" << endl;
    }else{
        cout <<"No suspicious bugs found!" << endl;
    }
}

int32_t main(){
    fast_in_out;

    int test;   cin>>test;
    Forn(i,test)sukuna(i);
    return 0;
}