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

int n, m, q;
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

int color[N], cc = 0;

void dfsc(int v){
    if(vis[v])return;
    vis[v] = true;
    color[v] = cc;
    for(auto child : graph[v]){
        dfsc(child);
    }
}


int32_t main(){
    fast_in_out;
    
    cin >> n >> m >> q;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            cc++; dfsc(i);
        }
    }
    find_cutpoints();
    // clog << db(art_point);

    while(q--){
        int a, b, c;
        cin >> a >> b >> c;
        if(low[a] > low[b])swap(a, b);
        clog << a <<" " << b <<" " << c << endl;
        clog << low[a] << " " << low[b] <<" " << in[c] << endl << endl;

        if(color[a] != color[b]){no; continue;}
        if(!art_point.count(c)){yes; continue;}

        if(low[b] < in[c] or low[a] > in[c]){yes; continue;}
        // yes;
        no;
    }
}