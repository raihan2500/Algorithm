#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
const int N = 1e5 + 10;
int dp[N];


int32_t main(){
    int n, sum = 0;
    cin >> n;
    vector<int> v(n);

    for(auto &a : v){
        cin >> a;
        sum += a;
    }    
    dp[0] = 1;

    for(auto a : v){
        for(int i = sum; i > 0; i--){
            if(i < a)continue;
            dp[i] += dp[i - a];
        }
    }
        
    set<int> s;
    
    for(int i = 1; i <= sum; i++){
        if(dp[i] > 0){
            s.insert(i);
        }
    }
    
    cout<<s.size()<<endl;
    print(s);
}