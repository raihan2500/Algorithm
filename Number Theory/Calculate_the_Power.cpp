#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;

int binExp(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b & 1)ans = (ans * a) % M;
        b >>= 1;
        a = (a * a) % M;
    }
    return ans;
}

int recur(int a, int b){
    if(b == 0)return 1;
    
    int res = (recur(a, b / 2)) % M;
    if(b & 1)return ((res * res) % M * a) % M;
    else return (res * res) % M;

}

int32_t main(){
    int a, b;
    cin>> a>> b;
    // cout<<binExp(a, b)<<endl;  
    cout<< recur(a, b)<<endl;
    
}