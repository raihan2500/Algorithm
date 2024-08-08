#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;


int32_t main(){
    int n, cnt = 0;
    cin>>n;
    vector<int> v(n),  lis;
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    lis.push_back(v[0]);

    for(int i = 1; i < n; i++){
        if(v[i] > lis.back()){
            lis.push_back(v[i]);
        }
        else{
            auto lb = lower_bound(lis.begin(), lis.end(), v[i]);
            *lb = v[i];
        }
    }


    cout<<lis.size()<<endl;
    
}