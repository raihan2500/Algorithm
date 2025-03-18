#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using u64 = uint64_t;
using u128 = __uint128_t;

#define int                long long

#define yes                cout<<"YES\n"
#define no                 cout<<"0\n"
#define nl                 cout<<"\n"
#define endl               "\n"

#define lin(n)             int n;cin>>n;
#define vin                vector<int>
#define pr                 pair<int, int>
#define pb(n)              push_back(n)
#define pp                 pop_back()
#define ppfr(v)            v.erase(v.begin());
#define all(x)             x.begin(),x.end()

#define forn(i,e)          for(int i=0;i<e;i++)
#define Forn(i,e)          for(int i=1;i<=e;i++)
#define rforn(i,s)         for(int i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)         for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
template <typename T>      using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#ifdef DEBUG
#include<algo/debug.h>
#else
#   define clog if (0) cerr
#   define DB(...)
#   define db(...) "" 
#endif

const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 100;

int n,m;
vector<int> graph[N];

bool flg, vis[N];
int in[N], low[N], timer;
set<pr> ans;

void dfs(int v = 1, int p = -1){
    vis[v] = true;
    in[v] = low[v] = timer++;

    for(auto child : graph[v]){
        if(child == p)continue;
        if(!ans.count({v, child}) and !ans.count({child, v})){
            ans.insert({v, child});
        }
        if(vis[child]){
            low[v] = min(low[v], in[child]);
        }else{
            dfs(child, v);
            low[v] = min(low[v], low[child]);
            if(low[child] > in[v]){
                flg = true;
            }
        }
    }
}


void sukuna(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs();
    if(flg){cout << 0 << endl; return;}
    mprint(ans);
}

int32_t main(){
    fast_in_out;

    int test = 1;  
    for(int i = 1; i <= test; i++)sukuna();
    return 0;
}