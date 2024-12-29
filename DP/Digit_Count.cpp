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

int dp[15][15];
int m, n;
vin digits;

int recur(int prev, int cnt){
    if(cnt >= n)return 1;
    if(dp[prev][cnt] != -1)return dp[prev][cnt];
    int ans = 0;
    for(auto i : digits){
        if(abs(prev - i) <= 2 or prev == 10)ans += recur(i, cnt + 1);
    }
    
    return dp[prev][cnt] = ans;
}

void sukuna(int test){
    cout <<"Case " << test <<": ";
    cin >> m >> n;
    digits.clear();
    forn(i,m){lin(x); digits.push_back(x);}

    memset(dp, -1, sizeof(dp));
    cout << recur(10, 0) << endl;
}

int32_t main(){
    fast_in_out;

    int test = 1;   cin>>test;
    for(int i = 1; i <= test; i++)sukuna(i);
    return 0;
}