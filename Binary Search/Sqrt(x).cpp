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


int mySqrt(int x) {
    fast_in_out;

    long long lo = 1, hi = x/2 + 1;
    long long mid;

    if(x == 0){
        return 0;
    }

    while(hi - lo > 1){
        mid = (hi + lo) / 2;

        if(mid * mid <= x){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    // cout<<lo<<endl;
    int ans = lo;
    return ans;  
        
}


int32_t main()
{
    fast_in_out;
    lin(n);
    cout<<mySqrt(n);   
    
    
}