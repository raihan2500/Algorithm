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


vector<int> twoSum(vector<int>& nums, int target) {
    fast_in_out;
    unordered_map<int, int> m;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        m[nums[i]] = i;
    }

    // for(auto a : m)cout<<a.se<<" "<<a.fi<<endl;

    for(int i = 0; i < n; i++){
        if(m.count(target - nums[i]) == 1){
            if(i != m[target - nums[i]])
            {
                return {i, m[target- nums[i]]};
            }
        }
    }

    return {};      
}


int32_t main()
{
    fast_in_out;

    int n, target;
    cin>>n>>target;
    vin v(n);
    forn(i,n)cin>>v[i];    
    twoSum(v, target);
    
}