#include<bits/stdc++.h>
using namespace std;
#define int        long long
const int M = 1e9 + 7;

long long fact(int n){
    if(n == 0)return 1;
    return (n * fact(n - 1)) % M;
}


int32_t main(){
    int n;
    cin>>n;
    cout<<fact(n);

    
}