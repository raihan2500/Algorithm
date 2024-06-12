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


int findPeakElement(vector<int>& nums) {
    fast_in_out;
    int n = nums.size();
    if(nums[0] > nums[1]){
        return 0;
    }
    else if(nums[n - 1] > nums[n - 2]){
        return n - 1;
    }

    int lo = 0, hi = n - 1;
    int mid;

    while(hi > lo){
        mid = (hi + lo) / 2;
        if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]){
            return mid;
        }
        if(nums[mid] < nums[mid + 1]){
            lo = mid;
        }
        else if(nums[mid] < nums[mid - 1]){
            hi = mid;
        }
    }
    return mid;
            
}


int32_t main()
{
    fast_in_out;
    lin(n);
    vin v(n);
    forn(i,n)cin>>v[i];
    cout<<findPeakElement(v);
    
    
}