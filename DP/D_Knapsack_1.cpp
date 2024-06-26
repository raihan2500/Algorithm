#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
const int N = 1e5 + 10;
vector<pair<int, int>> v;
int dp[105][N];

int func(int i, int w){

    if(w == 0)return 0;
    if(i == -1)return 0;

    //Not take
    if(dp[i][w] != 0)return dp[i][w];
    int x = func(i - 1, w);

    //Take

    int y = 0;
    if(w - v[i].first >= 0){
        y = func(i - 1, w - v[i].first) + v[i].second;
    }

    return dp[i][w] = max(x, y);
}


int32_t main(){
    int n, w;
    cin>>n>>w;

    for(int i = 0; i < n; i++){
        int x, y;
        cin>>x>>y;
        v.push_back({x, y});
    }

    cout<<func(n - 1, w)<<endl;
    
}