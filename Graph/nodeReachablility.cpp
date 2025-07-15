#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
bool vis[N];
int lastFinished = -1;

void dfs(int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v])
            dfs(v);
    }
    lastFinished = u;
}

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v; // 0-based indexing
        g[u].push_back(v);
    }

    // Step 1: Find candidate
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    // Step 2: Check if candidate can reach all
    memset(vis, 0, sizeof(vis));
    dfs(lastFinished);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cout << "No such node exists\n";
            return 0;
        }
    }

    cout << "Yes, node " << (lastFinished + 1) << " can reach all others.\n";
    return 0;
}

