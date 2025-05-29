#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, LG = 18;

struct ST {
    #define lc (n << 1)
    #define rc ((n << 1) | 1)
    int t[4 * N], lazy[4 * N];
    ST() {
        fill(t, t + 4 * N, 0);
        fill(lazy, lazy + 4 * N, 0);
    }
    inline void push(int n, int b, int e) {
        if(lazy[n] == 0) return;
        t[n] += (e - b + 1) * lazy[n];
        if(b != e) {
            lazy[lc] += lazy[n];
            lazy[rc] += lazy[n];
        }
        lazy[n] = 0;
    }
    inline void pull(int n) {
        t[n] = t[lc] + t[rc];
    }
    void build(int n, int b, int e, const vector<int> &values) {
        if(b == e) {
            t[n] = values[b];
            return;
        }
        int mid = (b + e) >> 1;
        build(lc, b, mid, values);
        build(rc, mid + 1, e, values);
        pull(n);
    }
    void upd(int n, int b, int e, int i, int j, int v) {
        push(n, b, e);
        if(j < b || e < i) return;
        if(i <= b && e <= j) {
            lazy[n] += v;
            push(n, b, e);
            return;
        }
        int mid = (b + e) >> 1;
        upd(lc, b, mid, i, j, v);
        upd(rc, mid + 1, e, i, j, v);
        pull(n);
    }
    int query(int n, int b, int e, int i, int j) {
        push(n, b, e);
        if(i > e || b > j) return 0;
        if(i <= b && e <= j) return t[n];
        int mid = (b + e) >> 1;
        return query(lc, b, mid, i, j) + query(rc, mid + 1, e, i, j);
    }
} t;

vector<int> g[N];
int par[N][LG + 1], dep[N], sz[N];
void dfs(int u, int p = 0) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    sz[u] = 1;
    for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
    if (p) g[u].erase(find(g[u].begin(), g[u].end(), p));
    for (auto &v : g[u]) if (v != p) {
        dfs(v, u);
        sz[u] += sz[v];
        if(sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
    if (u == v) return u;
    for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
    return par[u][0];
}
int kth(int u, int k) {
    assert(k >= 0);
    for (int i = 0; i <= LG; i++) if (k & (1 << i)) u = par[u][i];
    return u;
}
int T, head[N], st[N], en[N];
void dfs_hld(int u) {
    st[u] = ++T;
    for (auto v : g[u]) {
        head[v] = (v == g[u][0] ? head[u] : v);
        dfs_hld(v);
    }
    en[u] = T;
}
int n;
void update_up(int u, int v, int val) {
    while(head[u] != head[v]) {
        t.upd(1, 1, n, st[head[u]], st[u], val);
        u = par[head[u]][0];
    }
    t.upd(1, 1, n, st[v], st[u], val);
}
int query_up(int u, int v) {
    int ans = 0;
    while(head[u] != head[v]) {
        ans += t.query(1, 1, n, st[head[u]], st[u]);
        u = par[head[u]][0];
    }
    ans += t.query(1, 1, n, st[v], st[u]);
    return ans;
}
int query(int u, int v) {
    int l = lca(u, v);
    int ans = query_up(u, l);
    if (v != l) ans += query_up(v, kth(v, dep[v] - dep[l] - 1));
    return ans;
}
void update(int u, int v, int val) {
    int l = lca(u, v);
    update_up(u, l, val);
    if (v != l) update_up(v, kth(v, dep[v] - dep[l] - 1), val);
}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<int> values(n + 1), hld_values(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    head[1] = 1;
    dfs_hld(1);
    
    // Prepare values for segment tree based on HLD order
    for (int i = 1; i <= n; i++) {
        hld_values[st[i]] = values[i];
    }
    
    t.build(1, 1, n, hld_values);
    
    int q;
    cin >> q;
    while (q--) {
        int ty;
        int u, v, val;
        cin >> ty >> u >> v;
        if (ty == 1) {
            cin >> val;
            update(u, v, val);
        } else {
            cout << query(u, v) << '\n';
        }
    }
    return 0;
}