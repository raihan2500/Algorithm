#include<bits/stdc++.h>
using namespace std;

#define int long long

const int M = 1e9 + 7;
const int N = 1e5 + 100;
vector<int> graph[N];
int sum[N];
int val[N];

void dfs(int vertex, int par = 0){

    sum[vertex] += val[vertex];
    for(auto child : graph[vertex]){
        if(child == par)continue;

        dfs(child, vertex);
        sum[vertex] += sum[child];
    }
}

int32_t main(){
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }    
    for(int i = 1; i <= n; i++){
        cin >> val[i];
    }

    dfs(1);

    int ans = 0;

    for(int i = 2; i <= n; i++){
        int part1 = sum[i];
        int part2 = sum[1] - part1;
        ans = max(ans, (part1 * part2) % M);
    }

    cout<<ans<<endl;

}