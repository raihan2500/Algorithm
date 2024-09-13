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
#define pr                 pair<int, int>
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
#define mprint(mp)         for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;
 
#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long long INF = 1e18;
const int M = 1e9 + 7;
vector<pair<pr, int>> v;
vin ub;
int n, m;
 
int func(int i){
    if(i >= m)return 0;
    
    int it = upper_bound(all(ub), v[i].fi.se) - ub.begin();
    return v[i].se + func(it);
}
 
 
 
int32_t main()
{
    fast_in_out;
    cin >> n;
    vector<pair<pr, int>> a(n);
    forn(i,n){
        cin >> a[i].first.first >> a[i].fi.se >> a[i].second;
    }   
    sort(all(a));
 
    bool ck = 1;
    for(int i = 1; i < n; i++){
        if(a[i].first.fi > a[i - 1].fi.second){
            if(i == n - 1)ck = 0;
            v.push_back({{a[i - 1].first.first, a[i].first.second}, a[i].second + a[i - 1].second});
        }else{
            v.push_back(a[i - 1]);
        }
    }
    if(ck)v.push_back(a.back());
    // v = a;
 
    for(auto i : v){
        ub.push_back(i.fi.fi);
        cout<<i.fi.fi<<" "<<i.fi.se<<" "<<i.se<<endl;
    }
    print(ub);nl;nl;
 
    m = ub.size();


    cout<<func(1)<<endl;
    return 0;


    int ans = 0;
    for(int i = 0; i < m; i++){
        ans = max(ans, func(i));
    }
    cout<<ans<<endl;
}