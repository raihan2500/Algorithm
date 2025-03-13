#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using u64 = uint64_t;
using u128 = __uint128_t;

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

int n, m, par[N], dp[N];
vector<vector<int>> graph(N);


int dfs(int v){
    if(v == n)return 1;
    if(dp[v] != -1)return dp[v];
    int ans = -INF;
    for(int child : graph[v]){
        int cal = dfs(child);
        if(cal > ans){
            ans = cal;
            par[v] = child;
        }
    }
    if(graph[v].size() == 0)return dp[v] = -INF;
    return dp[v] = ans + 1;
}

void sukuna(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    memset(dp, -1, sizeof(dp));
    int res = dfs(1);
    if(res < 0){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << res << endl;
    vin ans = {1};
    int i = 1;
    while(i != n){
        i = par[i];
        ans.push_back(i);
    }
    print(ans);
}

int32_t main(){
    fast_in_out;

    int test = 1;  
    // cin>>test;
    for(int i = 1; i <= test; i++){
        // cout << "Case " << i <<": ";
        sukuna();
    }
    return 0;
}