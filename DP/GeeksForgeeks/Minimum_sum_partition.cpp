#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 2e5 + 10;

int n, tot;
vector<int> v;
vector<vector<int>> dp;

int recur(int ind, int sum){

    if(ind == n)return abs(tot - 2 * sum);
    if(dp[ind][sum] != -1)return dp[ind][sum];

    int a = recur(ind + 1, sum + v[ind]);
    int b = recur(ind + 1, sum);

    return dp[ind][sum] = min(a, b);
}

int32_t main(){
    cin >> n;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        v.push_back(x);
        sum += x;
    } tot = sum;
    dp = vector<vector<int>>(n + 1, vector<int>(sum + 10, -1));

    cout << recur(0, 0) << endl;
}