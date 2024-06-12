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

set<multiset<int>>s;

void subset(vector<int>&v, multiset<int>ans, int n){
    if(n == -1){
        s.insert(ans);
        return;
    }

    subset(v, ans, n-1);
    ans.insert(v[n]);
    subset(v, ans, n-1);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    
    vector<vector<int>>ans;
    int n = nums.size()-1;

    subset(nums, {}, n);
    for(auto a : s){
        vector<int>v;
        for(auto it : a)v.push_back(it);
        ans.push_back(v);
    }

    // for(auto a : ans){
    //     print(a);
    // }
    


    return ans;
}


int32_t main()
{
    fast_in_out;
    lin(n);
    vin v(n);
    forn(i,n)cin>>v[i];
    subsetsWithDup(v);    
    
}