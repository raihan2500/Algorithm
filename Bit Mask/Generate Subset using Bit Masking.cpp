#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;

int32_t main(){
    int n; string v;
    cin >> v; 
    n = v.size();
    vector<string> subset;

    for(int i = 0; i < 1 << n; i++){
        string sub;
        for(int j = 0, x = i; j < n; j++){
            if(x & 1)sub.push_back(v[j]);
            x >>= 1;
        }
        subset.push_back(sub);
    }

    for(auto sub : subset)cout<<sub<<endl;    
}