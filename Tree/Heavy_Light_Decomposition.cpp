#include<bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define DB(...)
#   define db(...) "" 
#endif

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

const int LG = 19;

int n, q, v[N];
struct ST{
    #define lc  2 * node
    #define rc  2 * node + 1
    
    vector<int> tree, lazy;
    ST(int N = 2e5 + 10){
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


vector<vector<int>> graph(N);
int cur_pos = 1, head[N], pos[N];
int par[N][LG + 1], sz[N], depth[N];

void dfs(int u = 1, int p = 0){
    par[u][0] = p;
    sz[u] = 1;
    for(int i = 1; i <= LG; i++)par[u][i] = par[par[u][i - 1]][i - 1];
    if(p)graph[u].erase(find(graph[u].begin(), graph[u].end(), p));
    for(auto &v : graph[u]){
        if(v == p)continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v] > sz[graph[u][0]])swap(v, graph[u][0]);
    }
}

void hld(int u){
    pos[u] = cur_pos++;
    for(auto v : graph[u]){
        if(v == graph[u][0])head[v] = head[u];
        else head[v] = v;
        hld(v);
    }
}

int lca(int u, int v){
    if(depth[u] < depth[v])swap(u, v);
    int dif = depth[u] - depth[v];
    while(dif){
        int lg = log2(dif);
        u = par[u][lg];
        dif -= (1 << lg);
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
        clog << chain_head <<" " << u << endl;
        int cur = st.query(1, 1, n, pos[chain_head], pos[u]);
        ans += cur;
        u = par[chain_head][0];
    }
    ans += st.query(1, 1, n, pos[v], pos[u]);
    return ans;
}

int query(int u, int v){
    if(depth[u] < depth[v])swap(u, v);
    int l = lca(u, v);
    int ans = query_up(u, l);
    if(v != l)ans += query_up(v, l);
    return ans;
}



int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    int values[n + 1];
    for(int i = 1; i <= n; i++)cin >> values[i];
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs();
    head[1] = 1;
    hld(1);
    for(int i = 1; i <= n; i++)v[pos[i]] = values[i];
    
    st.build(1, 1, n);
    
    cout << query(2, 1) << endl;
}