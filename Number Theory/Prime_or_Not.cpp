#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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


using u128 = __uint128_t;

int binExp(int a, int b, int M = 1e9 + 7){
    int ans = 1;    a %= M; b %= M;
    
    while(b > 0){
        if(b & 1)ans = ((u128)(ans % M) * (a % M)) % M;
        b >>= 1;
        a = ((u128)(a % M) * (a % M)) % M;
    }
    return ans;
}

int mmiOfX(int b){ return binExp(b, M - 2); }

bool millerTest(int n, int d, int a){
    int x = binExp(a, d, n);
    if(x == 1 or x == n - 1)return true;

    while(d != n - 1){
        x = ((u128)x * x) % n;
        d <<= 1;

        if(x == 1)return false;
        if(x == n - 1)return true;
    }
    return false;
}

bool is_it_prime(int n, int k = 5){
    if(n <= 1)return false;
    if(n <= 3)return true;
    if(!(n & 1))return false;

    int d = n - 1;
    while(!(d & 1)){
        d >>= 1;
    }

    mt19937_64 mt;
    for(int i = 0; i < k; i++){
        int a = 2 + mt() % (n - 4);

        if(!millerTest(n, d, a))return false;
    }
    return true;
}


void sukuna(int test){
    lin(n);
    if(is_it_prime(n))yes;
    else no;    
}

int32_t main(){
    fast_in_out;

    int test;   cin>>test;
    for(int i = 1; i <= test; i++)sukuna(i);
    return 0;
}