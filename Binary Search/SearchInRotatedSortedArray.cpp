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


int binarySearch(vector<int> v, int lo, int hi, int target){
    int mid;
    while(hi > lo){
        mid = (hi + lo)>>1;
        if(v[mid] < target){
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if(v[lo] == target)return lo;
    return -1;
}


int search(vector<int>& nums, int target) {
    int n = nums.size();
    if(nums[0] < nums[n - 1]){
        return binarySearch(nums, 0, nums.size(), target);
    }

    int lo = 0, hi = nums.size(); 
    int mid, pivot;
    while(hi - lo > 1){
        mid = (hi + lo) >> 1;
        if(nums[lo] > nums[hi]){
            hi = mid - 1;
            
        }
        else {
            hi ++;
            lo = mid ;
        }
    }

    cout<<lo<<" "<<hi<<endl;
    cout<<nums[lo]<<" "<<nums[hi]<<endl;

    int ans = binarySearch(nums, 0, lo , target);
    if(ans != -1)return ans;
    ans = binarySearch(nums, hi, nums.size() - 1, target);


    return ans;    
}


int32_t main()
{
    fast_in_out;
    lin(n); lin(target)
    vin v(n);
    forn(i,n)cin>>v[i];
    cout<<search(v, target);
    
    
}