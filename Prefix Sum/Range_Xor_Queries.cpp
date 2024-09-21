#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int v[N];

int32_t main(){
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        v[i] ^= v[i - 1];
    }
    
    while(m--){
        int l, r;
        cin >> l >> r;
        cout << (v[r] ^ v[l - 1]) << endl;
    }
    
}