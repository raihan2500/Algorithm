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
int n; vin v;

int recur(int i, int dis){
    if(i == (n - 1)){
        return v[i ];
    }

    if(dis == 0){
        dis = recur(i + 1, dis);
    }
    dis =  ((dis * v[i]) % M + (v[i] + dis) % M) % M;

    return dis;

}

int32_t main()
{
    fast_in_out;
    cin>>n;
    forn(i,n){
        lin(x);
        v.push_back(x);
    }
    cout<<recur(0, 0);
}