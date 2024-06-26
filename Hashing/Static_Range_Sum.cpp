#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;


int32_t main(){
    int n, q;
    cin>>n>>q;

    vector<int> prefix_sum(n + 1);

    for(int i = 1; i <= n; i++){
        cin>>prefix_sum[i];
        prefix_sum[i] += prefix_sum[i - 1];        
    }

    while(q--){
        int l, r;
        cin>> l >>r;
        cout<<prefix_sum[r] - prefix_sum[l]<<endl;
    }
    
}