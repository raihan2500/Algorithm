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

int n, m;
vector<vector<int>> graph(N);



int timer;
set<int> art_point;
vector<int> in(N), low(N), vis(N);

void dfs(int v, int p = -1){
    vis[v] = true;
    in[v] = low[v] = timer++;
    int children = 0;

    for(auto child : graph[v]){
        if(child == p)continue;
        if(vis[child]){
            low[v] = min(low[v], in[child]);
        }else{
            dfs(child, v);
            low[v] = min(low[v], low[child]);
            if(low[child] >= in[v] and p != -1){
                art_point.insert(v);
            }
            children++;
        }
    }
    if(p == -1 and children > 1){
        art_point.insert(v);
    }
}
void find_cutpoints(){
    timer = 0;
    in.assign(n + 1, 0);
    low.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    art_point.clear();
    
    for(int i = 1; i <= n; i++){
        if(!vis[i])dfs(i);
    }
}

void reset(){
    for(int i = 0; i <= n; i++){
        graph[i].clear();
    }
}

void sukuna(int test){
    reset();
    forn(i,m){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    } 
    find_cutpoints();
    cout << art_point.size() << endl;    
}

int32_t main(){
    fast_in_out;

    cin >> n >> m;
    while(n > 0 and m > 0){
        sukuna(1);
        cin >> n >> m;
    }
    return 0;
}