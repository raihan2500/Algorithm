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
const int M = 1e10;
int n, x;
vin v;

int32_t main()
{
    fast_in_out;

    cin >> n >> x;
    v.pb(M);
    forn(i,n){
        lin(l);
        v.pb(l);
    }
    sort(v.begin() + 1, v.end());
    int ans = 0;
    for(int i = n; i > 0; i--){
        if(v[i] == M)continue;
        int sum = v[i];
        for(int j = i - 1; j > 0; j --){
            if(v[j] == M)continue;
            if(sum + v[j] > x)continue;
            sum += v[j];
            v[j] = M;
        }
        ans++;
    }

    cout<<ans<<endl;
}