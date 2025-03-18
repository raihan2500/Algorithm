#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;
vector<int> graph[N], par(N);
bool vis[N], flg = false;
int n, m;

void bfs(){
    queue<int> q;
    q.push(1);
    vis[1] = true;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto child : graph[v]){
            if(vis[child])continue;
            q.push(child);
            vis[child] = true;
            par[child] = v;
            if(child == n){
                flg = true;
                return;
            }
        }
    }    
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    bfs();

    if(!flg){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> ans;

    int x = n;
    ans.push_back(x);
    while(1){
        ans.push_back(par[x]);
        x = par[x];
        if(x == 1)break;
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(auto i : ans)cout<<i<<" ";
    cout<<endl;

}