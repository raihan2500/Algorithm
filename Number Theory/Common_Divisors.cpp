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
const int NN = 1e6 + 10;

int32_t main()
{
    fast_in_out;
    lin(n);
    vector<int> v(NN);
    int N = 0, ans = 1;
    forn(i,n){
        lin(x);
        v[x] ++;
        N = max(N, x);
    }

    for(int i = 2; i <= N; i++){
        int cnt = 0;
        for(int j = i; j <= N; j +=i){
            if(v[j] > 0){
                cnt += v[j];
            }
            if(cnt > 1){
                ans = max(ans, i);
                break;
            }
        }
    }
    cout<<ans<<endl;
    
    
    
}