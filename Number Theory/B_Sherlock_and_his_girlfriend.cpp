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

int32_t main()
{
    fast_in_out;
    lin(n);
    n += 1;
    vector<int>isPrime(n + 1), color(n + 1);
    int x = 2;

    for(int i = 2; i <= n; i++){

        if(isPrime[i] == 0){
            color[i] = 1;
            bool ck = 0;
            
            for(int j = i * 2; j <=n; j+= i){
                if(color[j] == 0){
                    ck = 1;
                    color[j] = x;
                }
                isPrime[j] = 1;
            }
            if(ck){
                color[i] = x;
                x ++;
            }
        }
    }
    cout<<x - 1<<endl;
    for(int i = 2; i <= n; i++){
        cout<<color[i]<<' ';
    }
    
    
    
}