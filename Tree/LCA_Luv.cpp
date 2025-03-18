#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 100;
vector<int> graph[N];

int parent[N];

void dfs(int vertex, int par = -1){

    parent[vertex] = par;
    for(auto child : graph[vertex]){
        if(child == par)continue;

        dfs(child, vertex);
    }
}

vector<int> path(int v){
    vector<int> ans;
    while(v != -1){
        ans.push_back(v);
        v = parent[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    int n;
    cin >> n;

    for(int i  = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);

    int x, y, lca = -1;
    cin >> x >> y;

    vector<int> vec1 = path(x), vec2 = path(y);

    for(int i = 0; i < min(vec1.size(), vec2.size()); i++){
        if(vec1[i] == vec2[i]){
            lca = vec1[i];
        }else break;
    }

    cout<<lca<<endl;
}