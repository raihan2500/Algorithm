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
vector<int> v;
vector<vector<int>> dp(202, vector<int> (202));

int recur(int ind, int sum){

    if(sum == 0)return dp[ind][sum] = true;
    if(sum < 0)return false;
    if(ind >= n)return dp[ind][sum] = false;

    int a = recur(ind + 1, sum), b = recur(ind + 1, sum - v[ind]);
    return dp[ind][sum] = a | b;
}


bool canPartition(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    v = nums;
    n = v.size();
    int sum = accumulate(v.begin(), v.end(), 0ll);
    if(sum & 1)return false;
    return recur(0, sum / 2);
}


void sukuna(int test){
    lin(n);
    vin arr(n);
    forn(i,n)cin >> arr[i];

    if(canPartition(arr))yes;
    else no;    
}

int32_t main(){
    fast_in_out;

    int test = 1;
    for(int i = 1; i <= test; i++)sukuna(i);
    return 0;
}