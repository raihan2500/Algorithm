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
#define all(x)              x.begin(),x.end()

int n, m, v[N];
vector<vector<int>> graph(N);

int sz[N], ans[N];
void dfs1(int u, int p = 0){
    sz[u] = 1;
    if(p)graph[u].erase(find(all(graph[u]), p));
    for(auto &v : graph[u])if(v != p){
        dfs1(v, u);
        sz[u] += sz[v];
    }
    sort(all(graph[u]), [](int &a, int &b){
        return sz[a] > sz[b];
    });
}

set<int> s[N];

void dfs(int u, int p){
    for(auto &v : graph[u])if(v != p){
        dfs(v, u);
        if(v == graph[u][0]){
            swap(s[u], s[v]);
        }else{
            s[u].insert(all(s[v]));
        }
    }
    s[u].insert(v[u]);
    ans[u] = s[u].size();
}

void sukuna(){
    cin >> n;
    for(int i = 1; i <= n; i++)cin >> v[i];
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs1(1, 0); 
    dfs(1, 0);


    for(int i = 1; i <= n; i++)cout << ans[i] <<" ";

}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sukuna();
}