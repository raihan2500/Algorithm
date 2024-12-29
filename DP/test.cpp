#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;

//Initialize first Pollard::init();
namespace Pollard{
    #define int long long
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    const int N = 1e6 + 100;
    bool isPrime[N]; int hp[N];
    vector<int> primes;

    void init(){
        memset(isPrime, 1, sizeof(isPrime));
        isPrime[0] = isPrime[1] = 0;

        for(int i = 2; i < N; i++){
            if(isPrime[i]){
                hp[i] = i;
                for(int j = i + i; j < N; j += i){
                    isPrime[j] = 0;
                    hp[j] = i;
                }
            }
        }
        for(int i = 2; i < N; i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }
    }
    
    int binExp(int a, int b, int M = 1e9 + 7){
        int ans = 1;    a %= M; b %= M;
        
        while(b > 0){
            if(b & 1)ans = ((__uint128_t)(ans % M) * (a % M)) % M;
            b >>= 1;
            a = ((__uint128_t)(a % M) * (a % M)) % M;
        }
        return ans;
    }

    //Miller Rabin primality test
    bool is_composite(int n, int a, int d, int p){
        int x = binExp(a, d, n);
        if(x == 1 or x == n - 1)return false;
    
        for(int i = 0; i < p - 1; i++){
            x = (__uint128_t)x * x % n;
            if(x == n - 1)return false;
        }
    
        return true;
    }
    
    bool miller_rabin(int n, int iter = 5){
        if(n < 4)return n == 2 || n == 3;
        
        int p = 0, d = n - 1;
        while((d & 1) == 0){
            d >>= 1;
            p++;
        }
    
        for(int i = 0; i < iter; i++){
            int a = 2 + rnd() % (n - 3);
            if(is_composite(n, a, d, p))return false;
        }
    
        return true;
    }
    
    //Pollard rho
    int func(int x, int c, int mod){
        return ((__uint128_t) x * x % mod + c) % mod;
    }    

    int rho(int n){
        int c = 1 + rnd() % (n - 2);
        int x =  2 + rnd() % (n - 2);
        int y = x, d = 1;

        while(d == 1){
            x = func(x, c, n);
            y = func(func(y, c, n), c, n);
            d = __gcd(abs(x - y), n);
        }
        return d;
    }

    vector<int> factorize(int n){
        if(n == 1)return {1};
        if(miller_rabin(n))return {n};
        vector<int> factors, temp;
        
        if(n < N){
            while(n > 1){
                int pm = hp[n];
                while(n % pm == 0){
                    factors.push_back(pm);
                    n /= pm;
                }
            }
            return factors;
        }

        int x = rho(n);
        factors = factorize(x);
        temp = factorize(n / x);
        factors.insert(factors.end(), temp.begin(), temp.end());
        return factors;
    }

    void allDivsGen(int ind, int curVal, vector<pair<int, int>> &pmFact, set<int> &ans){
        if(pmFact[ind].first == -1){
            ans.insert(curVal);
            return;
        }
        for(int i = 0; i <= pmFact[ind].second; i++){
            allDivsGen(ind + 1, curVal, pmFact, ans);
            curVal *= pmFact[ind].first;
        }
    }

    set<int> allDivisors(int n){
        set<int> ans;
        vector<pair<int, int>> prime_factors;
        vector<int> fact = factorize(n);
        unordered_map<int, int> mp;
        for(auto i : fact)mp[i]++;
        for(auto i : mp)prime_factors.push_back({i.first, i.second});
        prime_factors.push_back({-1, -1});
        allDivsGen(0, 1, prime_factors, ans);
        return ans;
    }
}
using namespace Pollard;

bool isLucifer(int x){
    string str = to_string(x);
    int even = 0;
    for(int i = 0; i < str.size(); i++){
        if(i & 1)even += str[i] - '0';
        else even -= str[i] - '0';
    }
    return isPrime[abs(even)];
}

int32_t main(){
    init();
    int n, ans = 0;
    cin >>n;
    for(int i = 0; i <= n; i++){
        ans += isLucifer(i);
    }
    cout << ans << endl;
}