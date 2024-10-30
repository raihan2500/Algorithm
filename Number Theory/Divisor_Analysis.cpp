#include<bits/stdc++.h>
using namespace std;

#define int                long long

#define yes                cout<<"YES\n"
#define no                 cout<<"NO\n"
#define nl                 cout<<"\n"
#define endl               "\n"

#define lin(n)             int n;cin>>n;
#define vin                vector<int>
#define pr                 pair<int, int>
#define pb(n)              push_back(n)
#define pp                 pop_back()
#define all(x)             x.begin(),x.end()

#define fi                 first
#define se                 second

#define forn(i,e)          for(int i=0;i<e;i++)
#define Forn(i,e)          for(int i=1;i<=e;i++)
#define rforn(i,s)         for(int i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)         for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 100;

class SeiveAlgo{
    private:
        int N = 1e6;
        vector<bool> isPrime;
    public:
        vector<int> prime_numbers, lowest_prime, heighest_prime;
        
        SeiveAlgo(){
            N++; this->N = N;
            lowest_prime = vector<int> (N);
            heighest_prime = lowest_prime;
            isPrime = vector<bool> (N);
            generate();
        }
    
        SeiveAlgo(int N){
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

SeiveAlgo sv;

int32_t main(){
    fast_in_out;
    
    
}