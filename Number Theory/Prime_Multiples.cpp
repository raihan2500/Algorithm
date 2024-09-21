#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;



int32_t main(){
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> v(k);
    for(int i = 0; i < k; i++){
        cin >> v[i];
    }
    
    double RHS = log(n) + 0.001;
    for(int i = 1; i < (1 << k); i++){
        
        double LHS = 0.0;
        int div = 1;
        for(int j = 0; j < k; j++){
            if(i & (1 << j)){
                LHS += log(v[j]);
                div *= v[j];
            }
        }
        if(LHS < RHS)
        if(__builtin_popcount(i) & 1)ans += n / div;
        else ans -= n / div;
    }

    cout << ans << endl;
    
}