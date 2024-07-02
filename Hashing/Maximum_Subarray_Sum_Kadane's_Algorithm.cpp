#include<bits/stdc++.h>
using namespace std;

int32_t main(){
    vector< int > v =  {-2,-3,4,-1,-2,1,5,-3};
    int n = v.size();
    int ans = INT_MIN, mx = 0;
    for(int i = 0; i < n; i++){

        mx = mx + v[i];
        ans = max(ans, mx);

        if(mx < 0){
            mx = 0;
        }
    }
    cout<<ans<<endl;
    
}