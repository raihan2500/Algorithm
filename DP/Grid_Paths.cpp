#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
int dp[1001][1001];
vector<string> str;
int n, ans = 0, dp_counter = 0;


int recur(int i, int j){
    dp_counter ++;

    int x = 0, y = 0;

    if(str[i][j] == '*')return 0;

    if(i == n - 1 && j == n - 1){
        ans++;
        return 1;
    }

    
    if(i < n - 1){
        if(dp[i + 1][j] == -1){
            dp[i + 1][j] = recur(i + 1, j);
        }
        x = dp[i + 1][j];
    }

    if(j < n - 1){
        if(dp[i][j + 1]){
            dp[i][j + 1] = recur(i, j + 1);
        }
        y = dp[i][j + 1];
    }

    return (x + y) % M;
        
}


int32_t main(){
    memset(dp, -1, sizeof(dp));

    cin>>n;
    for(int i = 0; i < n; i++){
        string s; cin>>s;
        str.push_back(s);
    }

    cout<<recur(0, 0)<<endl;  

}