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

bool isPrime[1000];
void seive(){
    memset(isPrime, 1, sizeof(isPrime)); 
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i < 1000; i++){
        if(isPrime[i]){
            for(int j = i + i; j < 1000; j += i){
                isPrime[j] = false;
            }
        }
    }
}


int n;
string digits;

int recur(int ind, bool flg, bool lead, bool parity, int even, int odd){

    if(ind >= n)return isPrime[abs(even - odd)];

    int ans = 0, limit = flg ? digits[ind] - '0' : 9;

    for(int d = 0; d <= limit; d++){
        if(lead and d == 0){
            ans += recur(ind + 1, 0, 1, 0, 0, 0);
            continue;
        }

        int ev = even, od = odd;
        if(parity)ev += d;
        else od += d;

        ans += recur(ind + 1, flg & (d == limit), 0, !parity, ev, od);
    }

    return ans;
}

int func(int x){
    if(x < 0)return 0;
    digits = to_string(x);
    n = digits.size();
    cerr << digits << endl;

    return recur(0, 1, 1, 0, 0, 0);
}

void sukuna(int test){
    int l, r;
    cin >> l >> r;
    
    cout << func(r) - func(--l) << endl;
}

int32_t main(){
    fast_in_out;
    seive();

    int test = 1;   cin>>test;
    for(int i = 1; i <= test; i++)sukuna(i);
    return 0;
}