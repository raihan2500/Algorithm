#include<bits/stdc++.h>
using namespace std;

#define int long long
#define print(arr)         for(auto x: arr)cout<<x<<" ";cout << endl;
#define mprint(mp)         for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;


const int N = 1e3 + 100;
int n, x;
vector<vector<int>> graph;
vector<int> val(N);

void dfs(int vertex, int par = 0){

    if(graph[vertex].size() < x)return ;

    vector<pair<int, int>> toRemove;
    
    for(auto child : graph[vertex]){
        if(child == par)continue;

        dfs(child, vertex);
        toRemove.push_back({val[child], child});
    }
    sort(toRemove.begin(), toRemove.end());

    for(int i = x; i < toRemove.size(); i++){
        graph[toRemove[i].second].clear();
    }
    for(int i = 0, j = toRemove.size() - 1; i < x; i++, j--){
        val[vertex] += toRemove[j].first;
    }
}

void reset(){
    for(int i = 1; i <= n; i++){
        val[i] = 1;
    }
}

void nanami_sir(int Case){
    cin >> n >> x;
    vector<vector<int>> g(n + 1);
    for(int i = 1; i < n; i++){
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
    }

    for(auto &i : g){
        if(i.size() < x)i.clear();
    }

    // for(auto i : g){
    //     print(i);
    // }
    graph = g;
    reset();
    dfs(1);

    cout << "Case " << Case <<": " << val[1] << '\n';
    
}

int32_t main(){
    int test;
    cin >> test;
    for(int i = 1; i <= test; i++){
        nanami_sir(i);
    }
}