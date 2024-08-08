#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;


int32_t main(){
    int n;
    cin>>n;
    set<int> s;
    while(n --){
        int x; cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<endl;
    
}