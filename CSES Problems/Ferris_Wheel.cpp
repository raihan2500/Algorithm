#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;


int32_t main(){
    int n, k, ans = 0;
    cin >> n >>k;
    vector< int > v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());

    for(int i = 0, j = n - 1; i <= j;){
        if(v[i] + v[j] <= k){
            i++;
            j--;
        }
        else j--;
        ans ++;
    }

    cout<<ans<<endl;    
}