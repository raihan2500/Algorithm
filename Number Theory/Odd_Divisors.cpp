#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

int sq(int n){
    return n * n;
}

int cnt(int n){
    if(n == 0)return 0;
    if(n & 1){
        return sq((n + 1) / 2) + cnt(n / 2);
    }else{
        return sq(n / 2) + cnt(n / 2);
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;

        cout << cnt(b) - cnt(a - 1) << endl;
    }
}

