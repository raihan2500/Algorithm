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
const int N = 1e6 + 100;

int dp[N];

int32_t main()
{
    fast_in_out;
    lin(n); int sum = 0;
    vin v(n);
    forn(i,n){
        cin>>v[i];
        sum += v[i];
    }
    
    dp[0] = 1;

    for(int i = 0; i < n ; i++){

        for(int j = sum; j > 0; j--){

            if(j < v[i])continue;

            dp[j] += dp[j - v[i]];
        }
    }


    set<int> s;

    for(int i = 1; i <=sum; i++){
        if(dp[i])s.insert(i);
    }

    cout<<s.size()<<endl;
    print(s);
    
}

//https://www.youtube.com/watch?v=PXdOyrbNr78