#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
typedef                    long double ld;

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

#define sz(x)              ((ll)(x).size())
#define forn(i,e)          for(ll i=0;i<e;i++)
#define Forn(i,e)          for(ll i=1;i<=e;i++)
#define rforn(i,s)         for(ll i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int sum = 0;
int x;

void checker(vector<int>v, int n, int s)
{
    if(s > x)return;
    if(n == -1)
    {
        if(s == x)sum++;
        return;
    }

    //Not take
    checker(v,n-1,s);

    //Take
    s = s + v[n];
    checker(v,n-1,s);
}


int main()
{
    fast_in_out;

    int n, p = 1;
    cin>>x>>n;

    vector<int>v;

    for(int i = 2 ; p <= x; i++)
    {
        v.pb(p);
        p = pow(i,n);
    }

    checker(v,v.size()-1, 0);

    cout<<sum<<endl;

    return 0;
}