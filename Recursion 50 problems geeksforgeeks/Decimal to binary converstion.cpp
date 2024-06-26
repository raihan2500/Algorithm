#include<bits/stdc++.h>
using namespace std;
#define int        long long
const int M = 1e9 + 7;

int convert(int n){
    if(n == 0)return 0;

    // bit(n) = (n % 2) + 10 * bit(n / 2);
    return (n % 2) + convert(n / 2) * 10;
}

int32_t main(){
    int n;
    cin>>n;
    cout<<convert(n);
}