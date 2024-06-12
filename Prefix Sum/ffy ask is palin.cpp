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

/*CONSTRAINS
1<=t<=10
1<=N,Q<=1e6 
1<=L<=R<=N
*/

int solve()
{
    ll n,q;     cin>>n>>q;
    string str; cin>>str;
    int arr[26][n+1];
    memset(arr,0,sizeof(arr));

    forn(i,n)arr[str[i]-97][i+1]++;

    forn(i,26)
        for(int j=1;j<=n;j++)arr[i][j]+=arr[i][j-1];

    while(q--)
    {
        ll l,r,cnt=0;
        cin>>l>>r;
        forn(i,26)if((arr[i][r]-arr[i][l-1])%2==1)cnt++;
        
        if(cnt>1)no; 
        else yes;
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
//O(t* ( n+ n*26 + q*26 ) )
//O( t * n ) 







































// int solve()
// {
//     ll n ,q ;
//     cin>>n>>q;
//     string str;
//     cin>>str;
//     while(q--)
//     {
//         ll l,r,cnt=0;
//         cin>>l>>r;
//         int hs[26]={0};

//         for(int i=l-1;i<r;i++)hs[str[i]-97]++;
//         for(int i=0;i<26;i++)if(hs[i]%2==1)cnt++;
//         if(cnt>1)no;
//         else yes;
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

// //Time complexity
// // O(t* (n+q *(26+n+26)))
// //O(t*q*n)