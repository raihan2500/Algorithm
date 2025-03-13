#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using u64 = uint64_t;
using u128 = __uint128_t;

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
#define ppfr(v)            v.erase(v.begin());
#define all(x)             x.begin(),x.end()

#define fi                 first
#define se                 second

#define forn(i,e)          for(int i=0;i<e;i++)
#define Forn(i,e)          for(int i=1;i<=e;i++)
#define rforn(i,s)         for(int i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)         for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
template <typename T>      using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const long long INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 100;


//Initialize first Pollard::init();
namespace Pollard{
    #define int long long
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    const int N = 1e7 + 100;
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


void sukuna(int n){
    vin v = Pollard::factorize(n);
    map<int, int> mp;
    for(auto i : v)mp[i]++;
    for(auto i : mp){
        cout << i.first<<"^"<<i.second <<" ";
    }nl;
    
}

int32_t main(){
    fast_in_out;
    Pollard::init();
    int n;
    cin >> n;
    while(n > 0){
        sukuna(n);
        cin >> n;
    }
    
    return 0;
}