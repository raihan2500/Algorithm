#include<bits/stdc++.h>
using namespace std;
#define int long long

int binExp(int a, int b, int M){
    int ans = 1;

    while(b > 0){
        if(b & 1) ans = ((ans % M) * (a % M)) % M;
        b >>= 1;
        a = (a * a) % M;
    }
    return ans;
}

int32_t main(){
    int a, b, m;
    while(cin >> a >>b >> m){
        cout << binExp(a, b, m) << endl;
    }    
}