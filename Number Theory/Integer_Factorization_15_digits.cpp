#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;


using u128 = __uint128_t;

int binExp(int a, int b, int M = 1e9 + 7){
    int ans = 1;    a %= M; b %= M;
    
    while(b > 0){
        if(b & 1)ans = ((u128)(ans % M) * (a % M)) % M;
        b >>= 1;
        a = ((u128)(a % M) * (a % M)) % M;
    }
    return ans;
}

int mmiOfX(int b){ return binExp(b, M - 2); }


bool is_composite(int n, int a, int d, int p){
    int x = binExp(a, d, n);
    if(x == 1 or x == n - 1)return false;

    for(int i = 0; i < p - 1; i++){
        x = (u128)x * x % n;
        if(x == n - 1)return false;
    }

    return true;
}

bool is_prime(int n, int iter = 5){
    if(n < 4)return n == 2 || n == 3;
    
    int p = 0, d = n - 1;
    while((d & 1) == 0){
        d >>= 1;
        p++;
    }

    mt19937_64 rn;
    for(int i = 0; i < iter; i++){
        int a = 2 + rn() % (n - 3);
        if(is_composite(n, a, d, p))return false;
    }

    return true;
}

void pmF(int n){
    int cnt = 0;
    while(n % 2 == 0){
        n >>= 1;
        cnt++;
    }
    if(cnt)cout << 2 << "^" << cnt <<" ";

    for(int i = 3; i * i <= n; i += 2){
        if(n % i)continue;
        if(!is_prime(i))continue;
        cnt = 0;
        while(n % i == 0){
            n /= i;
            cnt++;
        }
        cout << i <<"^"<< cnt <<" ";
    }
    if(n > 1)cout << n <<"^1" << endl;
    return;
}

int32_t main(){
    int n;
    cin >> n;
    while(n != 0){
        pmF(n);
        cin >> n;
    }
}