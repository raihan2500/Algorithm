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
const int N = 2e5 + 100;
vin graph[N];
vin depth(N);
bool vis[N];

void dfs(int vertex, int par = 0){

    vis[vertex] = true;
    for(auto child : graph[vertex]){
        if(vis[child])continue;
        
        depth[child] = depth[vertex] + 1;
        dfs(child, par);
    }
}


int32_t main()
{
    fast_in_out;
    lin(n);
    vin d(n + 1);
    forn(i,n - 1){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(1);
    int mx = 0, node = 0;
    Forn(i,n){
        if(mx < depth[i]){
            mx = depth[i];
            node = i;
        }
    }

    Forn(i,n)depth[i] = 0, vis[i] = 0;;
    dfs(node);

    mx = 0;
    Forn(i,n)mx = max(mx, depth[i]);

    cout<<mx<<endl;
    
}