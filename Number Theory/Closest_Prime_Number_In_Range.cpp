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

#define sz(x)              ((ll)(x).size())
#define forn(i,e)          for(ll i=0;i<e;i++)
#define Forn(i,e)          for(ll i=1;i<=e;i++)
#define rforn(i,s)         for(ll i=s-1;i>=0;i--)
#define print(arr)         for(auto x: arr)cout<<x<<" ";nl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<int> closestPrimes(int left, int right) {
    int N = right + 1;
    vector<bool>isPrime(N);

    vector<int> ans(2);

    //Prime Number Generated with seive;
    isPrime[0] = 1; isPrime[1] = 1;
    for(int i = 2; i < N; i++){
        if(!isPrime[i]){
            for(int j = i * 2; j < N; j+=i){
                isPrime[j] = 1;
            }
        }
    }    

    int st = 0, dis =  INT_MAX;

    for(int i = left; i <= right; i++){
        if(!isPrime[i]){
            st = i;
            break;
        }                
    }
    if(st == 0){
        return{ -1, -1};
    }

    for(int i = st + 1; i <= right; i++){
        if(!isPrime[i]){
            if((i - st) < dis){
                ans[0] = st; ans[1] = i;
                dis = i - st;
            }
            st = i;
        }
    }

    if(dis < INT_MAX){
        return ans;
    }
   return{-1, -1};        
}
 


int32_t main()
{
    fast_in_out;
    lin(left) lin(right);
    print(closestPrimes(left, right));
    
}