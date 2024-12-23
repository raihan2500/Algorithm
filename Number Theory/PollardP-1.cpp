#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;


using u128 = __uint128_t;

int binExp(int a, int b, int M = 1e9 + 7){
    int ans = 1;    a %= M;
    
    while(b > 0){
        if(b & 1)ans = ((u128)(ans % M) * (a % M)) % M;
        b >>= 1;
        a = ((u128)(a % M) * (a % M)) % M;
    }
    return ans;
}

int mmiOfX(int b){ return binExp(b, M - 2); }



int pollardPMinus1(int n, int B = 20){
    mt19937 mt(time(0));
    int a = 2 + mt() % (n - 3);

    for(int i = 2; i <= B; i++){
        a = binExp(a, i, n);
        int d = __gcd(a, n);
        if(d > 1 && d < n)return d;
    }
    return 1;
}



int32_t main(){
    int n;
    cin >> n;
    int div = pollardPMinus1(n);
    while(div != 1){
        cout << div <<" ";
        n /= div;
        div = pollardPMinus1(n);
    }
    
}