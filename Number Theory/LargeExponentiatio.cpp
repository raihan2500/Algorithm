#include<bits/stdc++.h>
using namespace std;
#define int        long long
const int M = 1e18 + 7;

//We just created a function that doesn't directly return the multiples
//It return the multiples with mod. And multiples with addition in O(log(n)) time complexity

int multiply(int a, int b){
    int ans = 0;
    while(b > 0){
        if(b & 1)ans = (ans + a) % M;
        b >>= 1;
        a = (a + a) % M;
    }

    return ans;
}


//Large Exponentiation to get a exp of mod (1e18) range

int largeExp(int a, int b){
    int ans = 1;
    while(b > 0){
        if(b & 1) ans = multiply(ans, a);
        b >>= 1;
        a = multiply(a, a);
    }

    return ans;
}

int32_t main(){
    int a , b;
    cin >> a >> b;
    cout<<largeExp(a, b)<<endl;

}