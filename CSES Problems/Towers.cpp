#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;


int32_t main(){
    int n, sum = 0, ans = 0;
    cin>>n;
    vector<int > v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    for(int i = 0; i < n - 1; i++){
        if(v[i] <= v[i + 1])ans++;
    }

    cout<<ans<<endl;
}