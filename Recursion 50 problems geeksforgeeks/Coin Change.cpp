#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;

vector<int> v, dp; 

bool recur(int sum){


    if(sum < 0)return 0;
    if(sum == 0)return 1;

    for(auto a : v){

        if(dp[sum - a] == 0){
            if(recur(sum - a))
                dp[sum - a]++;
        }
        
        if(sum >= a)
            dp[sum] += dp[sum - a];
    }
    return 0;
}



int32_t main(){
    int n, sum;
    cin>>n>>sum;

    v.assign(n,0);
    dp.assign(sum + 1, 0);


    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    recur(sum);
    print(dp);


    
}