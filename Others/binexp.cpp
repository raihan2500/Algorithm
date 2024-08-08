#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;

int multiplesBySum(int a, int b){
    int ans = 0;

    while(b > 0){
        if(b & 1)ans = (ans + a) % M;
        b >>= 1;
        a = (a + a) % M;
    }
    return ans;
}
int binexp(int a, int b){
    
    if(b == 0)return 1;
    
    int multiplies = binexp(a, b >> 1);

    if(b & 1)return (multiplies * multiplies * a) % M;
    else return (multiplies * multiplies) % M;
    
}

int binExp(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b & 1)ans = multiplesBySum(ans, a);
        b >>= 1;
        a = multiplesBySum(a, a);
    }
    return ans;
}



int32_t main(){
    int a, b;
    cin >> a >> b;   
    cout<<binexp(a, b)<<endl;
    cout<<binExp(a, b)<<endl;
}