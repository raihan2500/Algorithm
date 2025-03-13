#include<bits/stdc++.h>
using namespace std;
#define int long long

int LCS_iterative(string s, string t){
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = n - 1; i >= 0; i--){
        for(int j = m - 1; j >= 0; j--){
            int x = 0;
            if(s[i] == t[j])x = 1 + dp[i + 1][j + 1];
            int a = dp[i + 1][j];
            int b = dp[i][j +  1];
            dp[i][j] = max({a, b, x});
        }
    }

    return dp[0][0];
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s, t;
    while(cin >> s >> t){
        cout << LCS_iterative(s, t) << endl;
    }
}