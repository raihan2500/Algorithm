#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long



int multiply(int a, int b, int m){
    int ans = 0;

    while(b > 0){
        if(b & 1)ans = (ans + a) % m;
        b >>= 1;
        a = (a + a) % m;
    }

    return ans;
}

int power(int a, int b, int m){
    int ans = 1;
    while(b > 0){
        if(b & 1) ans = multiply(ans, a, m);
        b >>= 1;
        a = multiply(a, a, m);
    }
    return ans;
}

int power2(int a, int b, int m){
    int ans =  1;
    while(b > 0){
        if(b & 1)ans = (ans * a) %m;
        b >>= 1;
        a = (a * a) % m;
    }
    return ans;
}


int superPow(int a, vector<int>& b) {

    int m = 1140;
    int M = 1337;
    int y = 0;
    for(int i = b.size() - 1, j = 0; i >=0; i--, j++){
        y = (y + (b[i] * power(10, j, m))) % m;
    }
    if(y == 0)y = 1140;
    return power2(a, y, M);
}


int32_t main(){
    int a, n;
    cin>>a>>n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) 
        cin>>b[i];
    cout<<superPow(a, b)<<endl;

    cout<<power(7, 1140, 1337)<<endl;

}