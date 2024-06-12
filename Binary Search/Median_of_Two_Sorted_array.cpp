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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> v;
    while(nums1.size() > 0 && nums2.size() > 0){
        int a = *nums1.begin();
        int b = *nums2.begin();
        if(a < b){
            v.push_back(a);
            nums1.erase(nums1.begin());
        }
        else{
            v.push_back(b);
            nums2.erase(nums2.begin());
        }
    }
    for(auto a : nums1)v.push_back(a);
    for(auto a : nums2)v.push_back(a);
    // print(v);

    double ans = 0;
    int n =  v.size();
    if(n & 1){
        ans = v[n / 2];
    }
    else{
        n>>=1;
        n --;
        ans = v[n] + v[n + 1];
        ans = ans / 2;
    }


    
    return ans;        
}


int32_t main()
{
    fast_in_out;
    lin(n) lin(m);

    vin nums1(n), nums2(m);

    forn(i,n)cin>>nums1[i];
    forn(i,m)cin>>nums2[i];
    cout<<(findMedianSortedArrays(nums1, nums2));
    
    
}