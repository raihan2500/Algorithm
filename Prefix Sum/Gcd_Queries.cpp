#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
typedef                    long double ld;

#define yes                cout<<"YES\n"
#define no                 cout<<"NO\n"
#define nl                 cout<<"\n"

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
#define rforn(i,s)         for(ll i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int solve()
{
    ll n,q,gc=0;
    cin>>n>>q;
    vector<ll>v(n+1),fw(n+1),bk(n+1);
    
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        fw[i]=__gcd(fw[i-1],v[i]);
    }

    for(int i=n;i>0;i--)
    {
        bk[i]=__gcd(bk[i+1],v[i]);
    }
    // print(fw); print(bk);

    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        cout<<__gcd(fw[l-1],bk[r+1]);nl;
    }


    return 0;
}

int main()
{
    fast_in_out;

    int test;	cin>>test;
    while(test--)solve();
    return 0;
}
//Time complexity
//O(T*(N+N))=10^6




// int solve()
// {
//     ll n,q;
//     cin>>n>>q;
//     vector<ll>v(n+1);

//     for(int i=1;i<=n;i++)cin>>v[i];
//     while(q--)
//     {
//         ll l,r,g=0;
//         cin>>l>>r;

//         for(int i=1;i<=l-1;i++)g=__gcd(g,v[i]);
//         for(int i=r+1;i<=n;i++)g=__gcd(g,v[i]);

//         cout<<g;nl;
//     }

//     return 0;
// }

// int main()
// {
//     fast_in_out;

//     int test;	cin>>test;
//     while(test--)solve();
//     return 0;
// }

/*Time complexity
  O(T*(N+Q*(N)))=O(T*N+T*N*Q)
*/