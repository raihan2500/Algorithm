#include<bits/stdc++.h>
using namespace std;
#define print(arr)         for(auto x: arr)cout<<x<<' '; cout<<endl;
#define int        long long
const int M = 1e9 + 7;

class SEIVE{
    private:
        int N = 1e6;
        vector<bool> isPrime;
    public:
        vector<int> prime_numbers, lowest_prime, heighest_prime;
        
        SEIVE(){
            N++; this->N = N;
            lowest_prime = vector<int> (N);
            heighest_prime = lowest_prime;
            isPrime = vector<bool> (N);
            generate();
        }
    
        SEIVE(int N){
            N++; this->N = N;
            lowest_prime = vector<int> (N);
            heighest_prime = lowest_prime;
            isPrime = vector<bool> (N);
            generate();
        }

        vector<int> primeFactors(int n){
            vector<int> temp;
            while(n > 1){
                int pm = lowest_prime[n];
                while(n % pm == 0){
                    n /= pm;
                    temp.push_back(pm);
                }
            }
            return temp;
        }

        vector<int> segSeive(int l, int r){
            int n = r - l + 1;
            vector<bool> isPrime(n + 1);
            vector<int> primes;

            for(int i = 0; prime_numbers[i] * prime_numbers[i] <= r; i++){
                int st = ceil(l * 1.0 / prime_numbers[i]) * prime_numbers[i];
                
                for(int j = st; j <= r; j += prime_numbers[i]){
                    if(j == prime_numbers[i])continue;
                    isPrime[j - l] = true;
                }
            }

            for(int i = 0; i < n; i++){
                if(!isPrime[i]){
                    if(i + l > 1){
                        primes.push_back(i + l);
                    }
                }
            }
            return primes;
        }
        
    private:
        void generate(){
            isPrime[0] = isPrime[1] = 1;
    
            for(int i = 2; i < N; i++){
                if(!isPrime[i]){
                    lowest_prime[i] = i;
                    heighest_prime[i] = i;
    
                    for(int j = i + i; j < N; j += i){
                        isPrime[j] = 1;
                        heighest_prime[j] = i;
                        if(lowest_prime[j] == 0){
                            lowest_prime[j] = i;
                        }
                    }
                }
            }
    
            for(int i = 2; i < N; i++){
                if(!isPrime[i]){
                    prime_numbers.push_back(i);
                }
            }
        }
};

SEIVE sv(1e5);

class phi{
    private:
        int n;
    public:
        vector<int> divisors;
        phi(int n){
            this->n = n;
            func();
        }
    private:
        void func(){
            int m = n;
            for(int i = 0; sv.prime_numbers[i] * sv.prime_numbers[i] <= m; i++){
                int d = sv.prime_numbers[i];
                if(n % d == 0){
                    divisors.push_back(d);
                    while(n % d == 0) n /= d;
                }
            }
            if(n != 1)divisors.push_back(n);
        }
};


void solve(int n){
    int ans = n;
    phi div(n);
    
    for(auto i : div.divisors){
        ans = ans / i * (i - 1);
    }

    cout << ans << endl;
}

int32_t main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0)break;
        solve(n);
    }
}