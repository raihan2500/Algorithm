#include<bits/stdc++.h>
using namespace std;

#define int long long
#ifdef DEBUG
#include<algo/debug.h>
#include<algo/resources.h>
#else
#   define clog if (0) cerr
#   define NB 420
#   define db(...) "" 
#endif

const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, m;
vector<int> graph[N];

bool vis[N];
vector<int> ord;

void dfs(int u){
    if(vis[u])return;
    vis[u] = true;
    for(auto v : graph[u]){
        dfs(v);
    }
    ord.push_back(u);
}
void dfsMethod(){
    for(int i = 1; i <= n; i++){
        dfs(i);
    }
    reverse(ord.begin(), ord.end());

    vector<int> pos(n + 1);
    for(int i = 0; i < n; i++){
        pos[ord[i]] = i;
    }
    for(int u = 1; u <= n; u++){
        for(auto v : graph[u]){
            if(pos[u] > pos[v]){
                cout << "Does not exist Top Sort" << endl;
                return;
            }
        }
    }
    cout << "The topological order is: ";
    for(auto &i : ord)cout << i <<" ";
    cout << endl;
}

void kahnsAlgo(){
    vector<int> in_degree(n + 1);
    for(int i = 1; i <= n; i++){
        for(auto &v : graph[i])in_degree[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(in_degree[i] == 0)q.push(i);
    }

    vector<int> ans;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ans.push_back(u);

        for(auto &v : graph[u]){
            in_degree[v]--;
            if(in_degree[v] == 0){
                q.push(v);
            }
        }    
    }

    if(ans.size() != n){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    for(auto &i : ans)cout << i <<" ";
    cout << endl;
}

int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    // dfsMethod();
    kahnsAlgo();
}