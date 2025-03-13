#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 100;
mt19937 rnd(time(0));

bool isPrime[N];
int hp[N];


void seive(){
    memset(isPrime, -1, sizeof(isPrime));
    for(int i = 2; i < N; i++){
        if(isPrime[i]){
            hp[i] = i;
            for(int j = i + i; j < N; j += i){
                isPrime[j] = false;
                hp[j] = i;
            }
        }
    }
}

int binExp(int a, int b, int M = 1e9 + 7){
    int ans = 1; a %= M;
    while(b > 0){
        if(b & 1)ans = (__uint128_t) ans * a % M;
        b >>= 1;
        a = (__uint128_t) a * a % M;
    }
    return ans;
}

bool isComposite(int n, int a, int d, int s){
    int x = binExp(a, d, n);
    if(x == 1 or x == n - 1)return false;

    for(int r = 1; r < s; r++){
        x = (__uint128_t)x * x % n;
        if(x == n - 1)return false;
    }
    return true;
}

bool miller_rabin(int n, int iter = 5){
    if(n < 4)return n > 1;
    if(!(n & 1))return false;

    int s = 0, d = n - 1;
    while(d % 2 == 0){
        s++;
        d >>= 1;
    }

    for(int i = 0; i < iter; i++){
        int a = 2 + rnd() % (n - 3);
        if(isComposite(n, a, d, s))return false;
    }
    return true;
}

int func(int x, int c, int mod){
    return ((__uint128_t)x * x % mod + c) % mod;
}

int rho(int n){
    int c = 1 + rnd() % (n - 2);
    int x = 2 + rnd() % (n - 2);
    int y = x, d = 1;

    while(d == 1){
        x = func(x, c, n);
        y = func(func(y, c, n), c, n);
        d = __gcd(abs(x - y), n);
    }
    return d;
}

vector<int> factorize(int n){
    if(n == 1)return {};
    if(miller_rabin(n))return {n};

    vector<int> fact, temp;

    if(n < N){
        while(n > 1){
            int pm = hp[n];
            while(n % pm == 0){
                fact.push_back(pm);
                n /= pm;
            }
        }
        return fact;
    }

    int x = rho(n);
    fact = factorize(x);
    temp = factorize(n / x);
    fact.insert(fact.end(), temp.begin(), temp.end());

    return fact;
}

void solve(){
    int n;
    cin >> n;
    vector<int> fact = factorize(n);
    sort(fact.begin(), fact.end());
    cout << fact.size() <<" "; 
    for(auto i : fact)cout << i <<" ";cout << endl;
}


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    seive();
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}