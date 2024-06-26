#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;


int32_t main(){
    int n, sum = 0;
    cin>>n;
    while(n --){
        int x; cin>>x;
        sum += x;
    }
    cout<<sum<<endl;   
}