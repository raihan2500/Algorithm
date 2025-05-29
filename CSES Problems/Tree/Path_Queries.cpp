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
const int N = 2e5 + 10, LG = 20;


int v[N];
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
        tree[node] = (hi - lo + 1) * val;
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
            lazy[node] = val;    /************/
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

int n, q;
vector<vector<int>> graph(N);

int sz[N];
int cur_pos = 1, pos[N], head[N], par[N];

void dfs(int u = 1, int p = 0){
    sz[u] = 1;
    par[u] = p;
    if(p)graph[u].erase(find(graph[u].begin(), graph[u].end(), p));

    for(auto &v : graph[u]){
        if(v == p)continue;
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v] > sz[graph[u][0]]){
            swap(v, graph[u][0]);
        }
    }
}

void hld(int u){
    pos[u] = cur_pos++;
    for(auto &v : graph[u]){
        if(v == graph[u][0])head[v] = head[u];
        else head[v] = v;
        hld(v);
    }
}

int query_up(int u, int v){
    int ans = 0;
    while(head[u] != head[v]){
        int chain_head = head[u];
        int cur = st.query(1, 1, n, pos[chain_head], pos[u]);
        ans += cur;
        u = par[chain_head];
    }
    ans += st.query(1, 1, n, pos[v], pos[u]);
    return ans;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> q;
    int values[n + 1];
    for(int i = 1; i <= n; i++)cin >> values[i];
    for(int i = 2; i <= n; i++){
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
    while(q--){
        int typ, u, x;
        cin >> typ >> u;
        if(typ == 1){
            cin >> x;
            st.update(1, 1, n, pos[u], pos[u], x);
        }else{
            cout << query_up(u, 1) << endl;
        }
    }
}