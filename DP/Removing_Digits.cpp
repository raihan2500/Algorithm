#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;

int func(int n){
    int x = 0;
    while(n > 0){
        x = max(x, n %10);
        n /= 10;
    }
    return x;
}


int32_t main(){
    int n;
    cin>>n;
    int cnt = 0;

    while(n > 0){
        cnt ++;
        n -= func(n);
    }
    cout<<cnt<<endl;
    
}