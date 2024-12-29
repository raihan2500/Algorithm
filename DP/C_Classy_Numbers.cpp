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

int n;
string digits;
int dp[20][2][5];

int recur(int ind, bool flg, int cnt){

    if(cnt > 3)return 0;
    if(ind >= n)return 1;
    if(dp[ind][flg][cnt] != -1)return dp[ind][flg][cnt];

    int ans = 0, limit = flg ? digits[ind] : 9;
    for(int d = 0; d <= limit; d++){
        ans += recur(ind + 1, flg & (d == limit), cnt + (d != 0));
    }
    return dp[ind][flg][cnt] = ans;
}

int func(int x){
    if(x < 0)return 0;
    memset(dp, -1, sizeof(dp));
    digits.clear();
    while(x > 0){
        digits.push_back(x % 10);
        x /= 10;
    } n = digits.size();
    reverse(digits.begin(), digits.end());

    return recur(0, 1, 0);
}

void sukuna(int test){
    int l, r;
    cin >> l >> r;

    int ans = func(r) - func(l - 1);
    cout << ans << endl;    
}

int32_t main(){
    fast_in_out;

    int test = 1;   cin>>test;
    for(int i = 1; i <= test; i++)sukuna(i);
    return 0;
}