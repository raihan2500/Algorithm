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

int n, m, sz[N];
vector<vector<int>> graph(N);

void cal_sz(int u = 1, int p = 0){
    sz[u] = 1;
    for(auto &v : graph[u]){
        if(v == p)continue;
        cal_sz(v, u);
        sz[u] += sz[v];
    }
}

int centroid(int u = 1, int p = 0){
    for(auto &v : graph[u]){
        if(v == p or sz[v] <= n / 2)continue;
        return centroid(v, u);
    }
    return u;
}

int32_t main(){
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cal_sz();
    cout << centroid() << endl;
}
/*
15
1 2
2 3
3 4
3 5
5 7
5 8
7 10
10 12
3 6
6 9
9 11
11 13
11 14
14 15
*/