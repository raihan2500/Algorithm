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


int n, m;
bool vis[N];
stack<int> st;
vector<vector<int>> graph(N), rev_graph(N);

void dfs1(int u){
    vis[u] = true;
    for(auto v : graph[u]){
        if(vis[v])continue;
        dfs1(v);
    }
    st.push(u);
}

void dfs2(int u){
    vis[u] = true;
    for(auto v : rev_graph[u]){
        if(vis[v])continue;
        dfs2(v);
    }
}

vector<vector<int>> kosaraju(){
    for(int i = 1; i <= n; i++){
        if(vis[i])continue;
        dfs1(i);
    }
    fill(vis, vis + n + 1, 0);
    vector<vector<int>> ans;
    while(!st.empty()){
        dfs2(st.top());
        vector<int> v;
        while(!st.empty() and vis[st.top()]){
            v.push_back(st.top());
            st.pop();
        }
        ans.push_back(v);
    }
    return ans;
}

int ed = 0;
bool dfs(int u){
    if(u == ed)return true;
    int ans = 0;
    vis[u] = true;
    for(auto v : graph[u]){
        if(vis[v])continue;
        ans |= dfs(v);
    }
    return ans;
}

void sukuna(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        rev_graph[y].push_back(x);
    }
    vector<vector<int>> ans = kosaraju();
    if(ans.size() == 1){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
        int u = ans[0].front();
        ed = ans[1].front();
        fill(vis, vis + n + 1, 0);
        if(dfs(u))swap(u, ed);
        cout << u <<" " << ed << endl;
    }
}

int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sukuna();  
}