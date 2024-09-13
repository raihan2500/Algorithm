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

#define sz(x)              ((int)(x).size())
#define forn(i,e)          for(int i=0;i<e;i++)
#define Forn(i,e)          for(int i=1;i<=e;i++)
#define rforn(i,s)         for(int i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int M = 1e9 + 7;

int func(vin v, int x){
    int sum = 0;
    for(auto a : v)sum += abs(x - a);
    return sum;
}

int32_t main()
{
    fast_in_out;
    int n, sum = 0, cost = 0;
    cin >> n;
    vin v(n);
    forn(i,n)cin >> v[i];
    sort(all(v));
    print(v);

    int lo = 0, hi = v[n - 1], mid;
    while(hi > lo){
        mid = (lo + hi)>>1;
        if(func(v, mid) < 0){
            lo = mid + 1;
        }else{
            hi = mid;
        }
    }
    cout<<lo<<endl;
    cout<<func(v, 3)<<endl;
    cout<<abs(func(v, lo))<<endl;

    
}