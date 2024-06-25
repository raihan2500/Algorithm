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
const int N = 1e6 + 100;

vector<int>isPrime(N), arr;

bool afraid(int n){
    int num = n;
    int d = 0;
    while(n > 0){
        if(n%10 == 0){
            return false;
        }
        n /= 10;
        d++;
    }
    int x = d;
    forn(i,x){
        int div = pow(10, d);
        int ind = num% div;
        if(isPrime[ind])return false;
        d--;
    }

    
    return true;
}


void seive(){
    isPrime[0] = isPrime[1] = 1;
    
    for(int i = 2; i * i < N; i++){
        if(!isPrime[i]){
            for(int j = i * i; j < N; j += i){
                isPrime[j] = 1;
            }
        }
    }

    for(int i = 2; i < N; i++){
        if(!isPrime[i]){
            if(afraid(i)){
                arr.push_back(i);
            }
        }
    }

}


void sukuna()
{
    lin(n);
    int ans = upper_bound(all(arr), n) - arr.begin();
    cout<<ans<<endl;    
}

int32_t main()
{
    seive();
    fast_in_out;

    int test;	cin>>test;
    while(test--)sukuna();
    return 0;
}