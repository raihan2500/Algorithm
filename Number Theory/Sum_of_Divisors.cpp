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

int func(int aa, int bb){
    __int128_t a = aa, b = bb;
    a--; b--;
    if(b < a)swap(a, b);
    return ((b * (b + 1) / 2) - (a * (a + 1) / 2)) % M;
}

int32_t main()
{
    fast_in_out;
    lin(n);
    int i = 1, q;
    int ans = 0 ;

    for(;i <= n;){
        int f = i;
        q = n / i;
        i = n / q + 1;

        ans += (q * func(f, i)) % M;
        ans %= M;
    }

    cout<<ans<<endl;
    
}