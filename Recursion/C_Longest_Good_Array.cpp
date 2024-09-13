#include<bits/stdc++.h>
using namespace std;


void solve(){
    int l, r;
    cin >> l >> r;
    int dif = r - l;

    long long lo = 1, hi = 1e9, mid;

    while(hi > lo){
        mid = (lo + hi) / 2;
        long long sum = mid * (mid + 1) / 2;

        if(sum <= dif){
            lo = mid + 1;
        }else{
            hi = mid;
        }
    }
    cout<<lo<<endl;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}