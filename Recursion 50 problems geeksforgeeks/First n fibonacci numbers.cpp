#include<bits/stdc++.h>
using namespace std;
#define int        long long
const int M = 1e9 + 7;

vector<int> dp;

void fibo(int n){
    //Don't need to set base case because dp[0] & dp[1] are set already

    //fibo(n) = fibo(n - 1) + fibo(n - 2);
    if(dp[n - 2] == 0)
        fibo(n - 2);
    if(dp[n - 1] == 0)
        fibo(n - 1);
        
    dp[n] = dp[n - 1] + dp[n - 2];

}

int32_t main(){

    int n;
    cin>>n;

    dp.assign(n, 0);
    dp[0] = dp[1] = 1;

    fibo(n - 1);

    for(auto a : dp){
        cout<<a<<' ';
    }
    
}