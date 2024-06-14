#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long

int superPow(int a, vector<int>& b) {
    int ans = 1;

    for(int i = b.size() - 1; i >= 0; --i){
        for(int j = 0; j < b[i]; ++j){
            ans *= a;
            ans %= 1337;
        }
        int temp = a;
        for(int j = 1; j < 10; ++j){
            a *= temp;
            a %= 1337;
        }
    }

    return ans;    
}


int32_t main(){
    int a, n;
    cin>>a>>n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) 
        cin>>b[i];
    cout<<superPow(a, b)<<endl;
}