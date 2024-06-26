#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;


int32_t main(){
    int n, q;
    cin>>n>>q;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>v[i];
        v[i] += v[i - 1];
    }
    while(q--){
        int a, b;
        cin>>a>>b;
        cout<<v[b] - v[a - 1]<<endl;
    }
    
}