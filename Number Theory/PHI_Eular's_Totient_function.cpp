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
}



namespace Phi{
    int phiSqrtN(int n){
        int ans = n;
        for(int i = 2; i * i <= n; i++){
            if(n % i)continue;
            while(n % i == 0)n /= i;
            ans -= ans / i;
        }
        if(n > 1)ans -= ans / n;
        return ans;
    }

    vector<int> phi;
    void phi_1_to_n(int n){ n += 10;
        phi = vector<int> (n);
        for(int i = 0; i < n; i++)phi[i] = i;
        for(int i = 2; i < n; i++){
            if(phi[i] == i){
                for(int j = i; j < n; j += i){
                    phi[j] -= phi[j] / i;
                }
            }
        }
    }

    int phiOfN(int n){
        //This is an uncomplete function
        /**Usage:
         * Get all the prime factor of n. (You can use Pollard Rho algorithm)
         * Let's the prime factors are p1, p2, ....pk
         * Therefore the ans = n * (1 - 1 / p1) * (1 - 1 / p2) ... * (1 / pk);
         *            => ans = n * (p1 - 1) / p1 * (p2 - 1) / p2 * ..... (pk - 1) / pk
         */
        vector<int> primeFactors = Pollard::factorize(n); 
        int ans = n;
        set<int> s;
        for(auto p : primeFactors){
            if(s.count(p))continue;
            ans = (__uint128_t) ans * (p - 1) / p;
            s.insert(p);
        }
        return ans;
    }
}



int32_t main(){
    Pollard::init();
    Phi::phi_1_to_n(1e6);
    
    int n;
    cin >> n;

    if(n <= 1e6)
        cout << Phi::phi[n] << endl;
    cout << Phi::phiOfN(n) << endl;
    cout << Phi::phiSqrtN(n) << endl;
}