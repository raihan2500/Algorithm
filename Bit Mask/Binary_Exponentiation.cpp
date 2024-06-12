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
const int M = 1e9 + 7;

// int binExp(int b){
// 	int a = 20;
// 	int ans = 1;

// 	while(b > 0){
// 		if(b & 1){
// 			ans = (ans % M * a % M) % M;
// 		}
// 		a = (a % M * a % M) % M;
// 		b >>= 1;
// 	}

// 	return ans;
// }

long long binExp(long long b){

	if(b == 0)return 1;
	
	long long res = binExp(b / 2) % M;

	if(b & 1)return ((res * 1LL * res) % M * 20) % M;
	else return (res * 1LL * res) % M;
}


int countGoodNumbers(long long n) {
	if(n&1) return (binExp(n / 2) % M * 5)% M;
	return binExp(n / 2);        
}


int32_t main()
{
    fast_in_out;
    lin(n);
    cout<<countGoodNumbers(n);   
    
}