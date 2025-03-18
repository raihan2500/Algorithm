//Undirected graph representation using Adjacency list

#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
const int N = 10;

vector<int> graph[N];
vector<pair<int, int>> weighted_graph[N];

int32_t main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int v1, v2, w;
        cin >> v1 >> v2 >> w;

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);

        weighted_graph[v1].push_back({v2, w});
        weighted_graph[v2].push_back({v1, w});
    }

    for(auto a : graph){print(a);}
    
}