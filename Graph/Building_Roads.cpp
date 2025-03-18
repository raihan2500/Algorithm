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

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1e9 + 7;
const int N = 2e5 + 10;
int n, m;
vin graph[N], c;
bool vis[N];
vector<vin> cc;

void dfs(int vertex){
    if(vis[vertex])return;
    vis[vertex] = 1;
    c.push_back(vertex);
    for(auto child : graph[vertex]){
        dfs(child);
    }
}

int32_t main()
{
    fast_in_out;
    cin >> m >> n;
    forn(i,n){
        lin(v1) lin(v2);
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for(int i = 1; i <= m; i++){
        if(vis[i])continue;
        c.clear();
        dfs(i);
        cc.push_back(c);
    }

    cout<<cc.size()-1<<endl;
    for(int i = 1; i < cc.size(); i++){
        cout<<cc[i - 1].back()<<' '<<cc[i].front()<<endl;
    }    
}