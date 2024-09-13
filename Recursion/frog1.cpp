#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
vector<int> v, dp(N, -1);

int recur(int n){

    if(n <= 0)return 0;
    if(n == 1)return abs(v[n] - v[0]);

    int x = abs(v[n] - v[n - 2]) + recur(n - 2);
    int y = abs(v[n] - v[n - 1]) + recur(n - 1);
    return dp[n] = min(x, y);
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout<<recur(n - 1)<<endl;


}