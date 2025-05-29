#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using u64 = uint64_t;
using u128 = __uint128_t;

#define int                 long long

#define endl                "\n"
#define yes                 cout<<"YES\n"
#define no                  cout<<"NO\n"
#define nl                  cout<<"\n"

#define lin(n)              int n;cin>>n;
#define pr                  pair<int, int>
#define vin                 vector<int>
#define pp                  pop_back()
#define pb(n)               push_back(n)
#define ppfr(v)             v.erase(v.begin());
#define all(x)              x.begin(),x.end()

#define forn(i,n)           for(int i = 0; i < n; i++)
#define Forn(i,n)           for(int i = 1; i <= n; i++)
#define rforn(i,n)          for(int i = n - 1; i >= 0; i--)
#define print(arr)          for(int i = 1; i <= n; i++)cout<<arr[i]<<" ";nl;
#define mprint(mp)          for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;
                            
mt19937                     rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y)            uniform_int_distribution<int>(x,y)(rng)
template <typename T>       using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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



int q, v[N];
struct ST{
    #define lc  2 * node
    #define rc  2 * node + 1
    
    vector<int> tree, lazy;
    ST(){
        tree = lazy = vector<int>(4 * N);
    }

    inline void pull(int node){
        tree[node] = tree[lc] + tree[rc]; /*********/
    }
    inline void push(int node, int lo, int hi){ /*************/
        if(lazy[node] == 0)return;
        
        int val = lazy[node]; 
        tree[node] += (hi - lo + 1) * val;
        lazy[node] = 0;
        
        if(lo == hi)return;
        lazy[lc] = lazy[lc] + val;
        lazy[rc] = lazy[rc] + val;
    }

    void build(int node, int lo, int hi){
        if(lo == hi){
            tree[node] = v[lo];
            return;
        }
        int mid = (lo + hi) / 2;
        build(lc, lo, mid);
        build(rc, mid + 1, hi);
        pull(node);
    }

    void update(int node, int lo, int hi, int l, int r, int val){
        push(node, lo, hi);
        if(r < lo or l > hi)return;
        if(lo >= l and hi <= r){
            lazy[node] += val;    /************/
            push(node, lo, hi);
            return;
        }
        int mid = (lo + hi) / 2;
        update(lc, lo, mid, l, r, val);
        update(rc, mid + 1, hi, l, r, val);
        pull(node);
    }

    int query(int node, int lo, int hi, int l, int r){
        push(node, lo, hi);
        if(r < lo or l > hi)return 0;  /************/
        if(lo >= l and hi <= r)return tree[node];
        int mid = (lo + hi) / 2;
        int q1 = query(lc, lo, mid, l, r);
        int q2 = query(rc, mid + 1, hi, l, r);

        return q1 + q2; /********/
    }
} st;


int n, m;
const int LG = 19;
vector<vector<int>> graph(N);
int head[N], pos[N], cur_pos = 1;
int depth[N], par[N][LG +  1], sz[N];

void dfs(int u = 1, int p = 0){
    sz[u] = 1;
    par[u][0] = p;
    for(int i = 1; i <= LG; i++)par[u][i] = par[par[u][i - 1]][i - 1];
    if(p)graph[u].erase(find(graph[u].begin(), graph[u].end(), p));
    for(auto &v : graph[u]){
        if(u == p)continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v] > sz[graph[u][0]])swap(v, graph[u][0]);
    }
}

void hld(int u = 1){
    pos[u] = cur_pos++;
    for(auto &v : graph[u]){
        if(v == graph[u][0])head[v] =  head[u];
        else head[v] = v;
        hld(v);
    }
}

int lca(int u, int v){
    if(depth[u] < depth[v])swap(u, v);
    int dif = depth[u] - depth[v];
    while(dif){
        int lg = log2(dif);
        dif -= (1 << lg);
        u = par[u][lg];
    }
    if(u == v)return u;
    for(int i = LG; i >= 0; i--){
        if(par[u][i] == par[v][i])continue;
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}

int query_up(int u, int v){
    int ans = 0;
    while(head[u] != head[v]){
        int chain_head = head[u];
        int cur = st.query(1, 1, n, pos[chain_head], pos[u]);
        u = par[chain_head][0];

        ans += cur;
    }
    ans += st.query(1, 1, n, pos[v], pos[u]);
    return ans;
}

int query(int u, int x){
    if(depth[u] < depth[x])swap(u, x);
    int l = lca(u, x);
    int ans = query_up(u, l);
    if(x != l)ans += query_up(x, l) - v[l];
    return ans;
}

void reset(bool flg = true){
    for(int i = 0; i <= n; i++){
        if(flg)graph[i].clear();
    }
}

void solve(){
    cin >> n;
    vin vals(n + 1);

    struct grp{int x, y, wt;};

    vector<grp> adj;
    for(int i = 0; i < n - 1; i++){
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back(y);
        graph[y].push_back(x);
        vals[y] = w;
        adj.push_back({x, y, w});
    }

    dfs();
    head[1] = 1;
    hld();
    // for(auto &g : adj){
    //     if(depth[g.x] > depth[g.y])swap(g.x, g.y);
    //     vals[g.y] = g.wt;
    // }
    
    for(int i = 2; i <= n; i++)v[pos[i]] = vals[i];
    clog << db(vals);
    print(v);

    st.build(1, 1, n);
    cout << st.tree[1] << endl;


    // return;
    while(1){
        string typ; cin >> typ;
        if(typ == "DONE")break;
        int u, v;
        cin >> u >> v;
        if(typ == "QUERY"){
            cout << query(u, v) << endl;
        }else{u--;
            int id = pos[adj[u].y];
            st.update(1, 1, n, id, id, v);
        }
    }
}

int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test = 1;  
    cin>>test;
    for(int i = 1; i <= test; i++){
        // cout << "Case " << i <<": ";
        solve();
    }
    return 0;
}