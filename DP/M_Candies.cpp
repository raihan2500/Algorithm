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

int n, k, dp_cnt;
vin v;
vector<vin> dp(101, vin (N, -1));

int recur(int ind, int k){ 
    dp_cnt++;
    if(k == 0)return 1;
    if(ind == n)return 0;
    if(dp[ind][k] != -1)return dp[ind][k];

    int ans = 0;
    
    for(int i = 0; i <= v[ind] && i <= k; i++){
        int x = recur(ind + 1, k - i);
        ans += x;
        ans %= M;
    }

    return dp[ind][k] = ans;
}

void sukuna(int test){
    cin >> n >> k;
    forn(i,n){
        lin(x);
        v.push_back(x);
    }

    cout << recur(0, k) << endl;
    cout << dp_cnt << endl;
    
}

int32_t main(){
    fast_in_out;

    int test = 1;
    for(int i = 1; i <= test; i++)sukuna(i);
    return 0;
}