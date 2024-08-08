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

void sukuna()
{
    int n, q;
    cin>>n>>q;
    vin v(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>v[i];
        v[i] += v[i - 1];
    }

    int sum = v[n]; 
    while(q--){
        int l, r, k;
        cin>>l>>r>>k; l--;
        int mid = v[r] - v[l];
        int chk = (r - l) * k;

        if(sum & 1){
            if(mid % 2 == chk % 2)yes;
            else no;
        }
        else {
            if(mid % 2 == chk % 2)no;
            else yes;        
        }
    }


    
}

int32_t main()
{
    fast_in_out;

    int test;	cin>>test;
    while(test--)sukuna();
    return 0;
}