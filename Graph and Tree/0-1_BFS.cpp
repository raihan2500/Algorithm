#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int INF = 1e9 + 7;

vector<pair<int, int>> graph[N];
vector<int> lev(N, INF);
int n, m;

int bfs(){
    deque<int> q;
    q.push_back(1);
    lev[1] = 0;

    while(!q.empty()){
        int v = q.front();
        q.pop_front();

        for(auto child : graph[v]){
            int child_v = child.first;
            int wt = child.second;

            if(lev[v] + wt < lev[child_v]){
                lev[child_v] = lev[v] + wt;
                if(wt == 1){
                    q.push_back(child_v);
                }else{
                    q.push_front(child_v);
                }
            }
        }
    }
    return lev[n] == INF ? -1 : lev[n];
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        if(x == y)continue;
        graph[x].push_back({y, 0});
        graph[y].push_back({x, 1});
    }

    cout<<bfs() <<endl;
}