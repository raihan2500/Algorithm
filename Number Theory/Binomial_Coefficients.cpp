#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;
const int N = 1e6 + 10;
int fact[N]; 

int binExp(int a, int b = M - 2){
    int ans = 1;
    while(b > 0){
        if(b & 1)ans = ((ans % M) * (a % M)) % M;
        b >>= 1;
        a = ((a % M) * (a % M)) % M;
    }
    return ans;
}


void solve(){
    int a, b;
    cin  >> a >> b;
    b = fact[b] * fact[a - b];
    a = fact[a];

    // cout << a / b << endl;
    cout << ((a % M) * (binExp(b, M - 2)) % M) % M << endl;
    
}

int32_t main(){
    fact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = ((i % M) * (fact[i - 1] % M)) % M;
    }    

    int test; cin >> test;
    while(test--){
        solve();
    }
}