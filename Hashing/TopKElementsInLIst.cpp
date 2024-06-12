#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
typedef                    long double ld;
#define int                long long

#define yes                cout<<"YES\n"
#define no                 cout<<"NO\n"
#define nl                 cout<<"\n"
#define endl               "\n"

#define lin(n)             ll n;cin>>n;
#define in(n)              int n;cin>>n;
#define vin                vector<int>
#define pb(n)              push_back(n)
#define pp                 pop_back()
#define srt(v)             sort(v.begin(),v.end());
#define all(x)             x.begin(),x.end()

#define fi                 first
#define se                 second
#define mmp                make_pair

#define sz(x)              ((ll)(x).size())
#define forn(i,e)          for(ll i=0;i<e;i++)
#define Forn(i,e)          for(ll i=1;i<=e;i++)
#define rforn(i,s)         for(ll i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


vector<int> topKFrequent(vector<int>& nums, int k) {

    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int>m;
    map<int, int>mp;

    for(int i = 0; i <n; i++){
        m[nums[i]]++;
    }

    for(auto a : m){
        mp.insert({a.second, a.first});
    }

    auto a = --mp.end();

    for(int i = 0; i < k; i++){
        ans.push_back(a->second);
        a--;
    }
    
    return ans;    
}


int32_t main()
{
    fast_in_out;
    lin(n) lin(k);
    vin v(n);
    forn(i,n)cin>>v[i];
    print(topKFrequent(v, k));
    
}