#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;

int setbit(int n){
    if(n == 0)return 0;
    return (n & 1) + setbit(n / 2);
}

int32_t main(){
    int n;
    cin>>n; 
    cout<<setbit(n)<<endl;  
}