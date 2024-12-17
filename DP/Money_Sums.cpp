#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++)cin >> v[i];
    int sum = accumulate(v.begin(), v.end(), 0);

    int dp[sum + 10] = {0};
    dp[0] = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = sum; j > 0; j--){
            if(j - v[i] < 0)break;
            dp[j] |= dp[j - v[i]];
        }
    }

    set<int> s;
    for(int i = 1; i <= sum; i++){
        if(dp[i])s.insert(i);
    }

    cout << s.size() << endl;
    for(auto i : s)cout << i <<" "; cout << endl;

}