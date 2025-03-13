#include<bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;
const int N = 2e5 + 10;


class SeiveAlgo{
    private:
        //Variables
        int N = 1e6, factors_size,  num_cnt = 0, dp_cnt = 0;
        vector<int> lp;
        vector<bool>isPrime;
        set<int> divisors;
        struct grp{int pm, cnt;};
        vector<grp>factors;

    public:
        vector<int>primes;

        SeiveAlgo(int n = 1e6){
            N = n + 100;
            lp = vector<int> (N);
            isPrime = vector<bool> (N);
            generatePrimes();
        }

        vector<int> primeFactors(int n){
            vector<int> v;
            factors.clear();
            while(n > 1){
                int pm = lp[n], cnt = 0;
                while(n % pm == 0){
                    v.push_back(pm);
                    n /= pm;
                    cnt++;
                }
                factors.push_back({pm, cnt});
            }
            return v;
        }

        //All the divisors of a number
        set<int> allDivisors(int n){
            primeFactors(n);
            factors_size = factors.size();
            divisors.clear();
            allDivisorsGenerator(0, 1);
            return divisors;
        }

    private:
        //Segment Seive
        vector<int> segSeive(int l, int r){
            if(l > r)swap(l, r);
            int n = r - l + 1;
            vector<bool>isPrime(n + 1);
            vector<int>segPrimes;

            for(int i = 0; primes[i] * primes[i] <= r; i++){
                int st = ceil(l * 1.0 / primes[i]) * primes[i];
                for(int j = st; j <= r; j += primes[i]){
                    if(j == primes[i])continue;
                    isPrime[j - l] = true;
                }
            }
            
            for(int i = 0; i < n; i++){
                if(!isPrime[i]){
                    if(i + l > 1){
                        segPrimes.push_back(i + l);
                    }
                }
            }
            return segPrimes;
        }

    private:
        void allDivisorsGenerator(int currIndex, int currDivisor){
            dp_cnt++;
            if(currIndex == factors_size){
                num_cnt++;
                divisors.insert(currDivisor);
                return;
            }
            for(int i = 0; i <= factors[currIndex].cnt; i++){
                allDivisorsGenerator(currIndex + 1, currDivisor);
                currDivisor *= factors[currIndex].pm;
            }
        }

        void generatePrimes(){
            isPrime[0] = isPrime[1] = true;
            for(int i = 2; i < N; i++){
                if(!isPrime[i]){
                    lp[i] = i;
                    for(int j = i + i; j < N; j += i){
                        isPrime[j] = true;
                        if(lp[j] == 0)lp[j] = i;
                    }
                }
            }
            for(int i = 2; i < N; i++){
                if(!isPrime[i])primes.push_back(i);
            }
        }
};

int32_t main(){
  
}