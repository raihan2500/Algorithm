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
const int N = 2e5 + 100;

vector<pair<int, int>> graph[N];
vector<int> val(N, 0), vis(N);

void dfs(int vertex = 1){

    if(vis[vertex])return;
    vis[vertex] = true;

    for(auto child : graph[vertex]){
        int child_v = child.first;
        int wt = child.second;
        
        if(val[vertex] + wt > val[child_v]){
            val[child_v] = val[vertex] + wt;
            dfs(child_v);            
        }
    }
}

int32_t main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int x, y, wt;
        cin >> x >> y >> wt;
        graph[x].push_back({y, wt});
        graph[y].push_back({x, wt});
    }
    dfs(1);

    cout << val[n] << endl;
}