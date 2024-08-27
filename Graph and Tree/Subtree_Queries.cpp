#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> graph[N];
int subTreeSum[N];
int evenCount[N];


void dfs(int vertex, int par = 0){
    subTreeSum[vertex] += vertex;
    if(vertex % 2 == 0){
        evenCount[vertex]++;
    }
    for(auto child : graph[vertex]){
        if(child == par)continue;

        dfs(child, vertex);
        subTreeSum[vertex] += subTreeSum[child];
        evenCount[vertex] += evenCount[child];
    }
}

int main(){
    int n;
    cin >> n;
    
    for(int i = 0; i < n - 1; i++){
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);

    for(int i = 1; i <= n; i++){
        cout<<evenCount[i]<<" "<<subTreeSum[i]<<endl;
    }
    return 0;

    int q;
    cin >> q;



    while(q--){
        int v;
        cin >> v;
        cout<<subTreeSum[v]<<endl;
        cout<<evenCount[v]<<endl;

    }
}