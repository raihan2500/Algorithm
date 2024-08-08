#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
const int N = 1e5 + 10;

int dp_counter;
vector<pair<int, int>> v;
int dp[1002][N];

int recur(int i, int w){
    // dp_counter++;

    if(i == -1 || w < 0)return 0;

    if(dp[i][w] != 0)return dp[i][w];

    int x, y = 0;
    x = recur(i - 1, w);

    if(w - v[i].first >= 0){
        y = recur(i - 1, w - v[i].first) + v[i].second;
    }

    return dp[i][w] = max(x, y);

}



int32_t main(){
    int n, w;
    cin>>n>>w;
    for(int i = 0; i < n; i++){
        int fi; cin>>fi;
        v.push_back({fi, 0});
    }
    for(int i = 0; i < n; i++){
        cin>>v[i].second;
    }
    v.push_back({0, 0});


    cout<<recur(n - 1, w)<<endl;
    // cout<<dp_counter<<endl;
    
}