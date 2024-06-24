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

int dp[25001];

int lis(int n, vector<int> &v){

	if(n == -1)return 1;
	int ans = 1;
	for(int i = n - 1; i >= 0; i--){
		if(v[i] < v[n]){
			if(dp[i] == 0)dp[i] = lis(i, v);
			ans = max(ans, dp[i] + 1);
		}
	}
	return dp[n] = ans;
}

int lengthOfLIS(vector<int>& nums) {
	fast_in_out;
	int n = nums.size(), ans = 1;

	for(int i = 0; i < n; i++){
		ans = max(ans, lis(i, nums));
	}
	return ans;      
}


int32_t main()
{
	fast_in_out;
	lin(n);
	vin v(n);
	forn(i,n)cin>>v[i];
	cout<<lengthOfLIS(v);
	
}