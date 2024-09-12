#include<bits/stdc++.h>
using namespace std;
#define print(v)                for(auto i : v)cout << i <<" ";cout << endl;

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



int main(){
    SEIVE pm(10000000);
    print(pm.primeFactors(720));
    print(pm.primeFactors(444632));
}