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
int n, w, mx = 0;
vector<pair<int, int>> v;
int dp[102];

void recur(int i, int weight, int sum){
    cout<<i<<endl;

    if(weight <= w){
        mx = max(mx, sum);
    }
    else return;
    if(i == -1){
        mx = max(mx, sum);
        return;
    }

    recur(i - 1, weight, sum);
    // if(dp[i] == 0)
        recur(i - 1, weight + v[i].first, sum + v[i].second);


}



int32_t main()
{
    fast_in_out;
    cin>>n>>w;

    forn(i,n){
        lin(x) lin(y)
        v.push_back({x, y});
    }

    recur(n - 1, 0, 0);
    cout<<mx<<endl;
    
    
}