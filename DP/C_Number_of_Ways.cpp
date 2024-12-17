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
const int N = 5e5 + 100;

int n, tot;
vin v, pf, dp(N, -1);
map<int, vin> mp;
map<int, int> sz;


int recur(int ind){

    if(ind >= n)return 0;
    if(dp[ind] != -1)return dp[ind];

    int res = tot - pf[ind];
    int sec = 2 * pf[ind];

    if(res != sec)return dp[ind] = recur(ind + 1);
    if(mp.find(sec) == mp.end())return dp[ind] = recur(ind + 1);
    

    int up = lower_bound(all(mp[sec]), ind) - mp[sec].begin();
    if(mp[sec][up] == ind)up++;
    
    int cnt = sz[sec] - up;
    if(mp[sec].back() == n - 1)cnt--;
    cnt = max(cnt, 0ll);
    
    return dp[ind] = cnt + recur(ind + 1);
}

void sukuna(int test){
    cin >> n;

    forn(i,n){
        lin(x);
        v.push_back(x);
    }

    pf.push_back(v.front());
    mp[pf.back()].push_back(0);
    sz[pf.back()]++;

    for(int i = 1; i < n; i++){
        pf.push_back(pf.back() + v[i]);
        mp[pf.back()].push_back(i);
        sz[pf.back()]++;
    }
    tot = pf.back();

    cout << recur(0) << endl;
}

int32_t main(){
    fast_in_out;

    int test = 1; 
    for(int i = 1; i <= test; i++)sukuna(i);
    return 0;
}