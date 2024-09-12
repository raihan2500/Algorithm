#include<bits/stdc++.h>
using namespace std;
#define print(v)                for(auto i : v)cout << i <<" ";cout << endl;

class SEIVE{
    public:
        int N = 1e6;
        vector<int> prime_numbers, lowest_prime, heighest_prime;
        vector<bool> isPrime;
        
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
};



int main(){
    SEIVE pm;
    print(pm.primeFactors(720));



}