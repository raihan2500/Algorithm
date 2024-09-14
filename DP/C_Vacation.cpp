#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

vector<vector<int>> v;
int n, dp[N][3];

int recur(int x, int y){

    if(x == n)return 0;
    if(dp[x][y] != 0)return dp[x][y];
    
    int ans = 0;
    for(int i = 0; i < 3; i++){
        if(i == y)continue;
        int temp = v[x][i] + recur(x + 1, i);
        if(temp > ans){
            ans = temp;
        }
    }

    return dp[x][y] = ans;
}

int32_t main(){
    cin >> n;
    for(int i = 0;i  <n; i++){
        vector<int> temp(3);
        for(int j = 0; j < 3; j++)cin >> temp[j];
        v.push_back(temp);
    }   

    int ans = recur(0, -1); 
    cout << ans << endl;

}