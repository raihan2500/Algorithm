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

SeiveAlgo sv;

struct grp{int pm, cnt; void display(){cout << pm <<" " << cnt << endl;}};

int calculate(int n){
    int ans = 0;
    for(int i = 1;; i++){
        if((i * (i + 1) / 2) > n)break;
        ans = i;
    }
    return ans;
}

int32_t main(){
    fast_in_out;
    lin(n);
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }
    vector<grp> factors;
    vin primes = sv.primes;

    for(int i = 0; primes[i] * primes[i] <= n; i++){
        if(n % primes[i])continue;
        int m = n;
        int cnt = 0;
        while(m % primes[i] == 0){
            cnt++;
            m /= primes[i];
        }
        factors.push_back({primes[i], cnt});
    }

        
    int ans = 0;
    for(auto i : factors){
        ans += calculate(i.cnt);
    }

    cout << max(1ll, ans) << endl;
}