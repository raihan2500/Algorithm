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

set<vector<int>>A;

void permute(vector<int> &v,vector<int>an, set<int> ind){

    // print(ind);nl;

    if(ind.empty()){
    // print(an);
        A.insert(an);
        return;
    }

    for(auto a : ind){

        vector<int> aa = an;
        aa.push_back(v[a]);
        
        set<int> s = ind;
        s.erase(a);
        permute(v, aa, s );
    }
    
}


vector<vector<int>> permuteUnique(vector<int>& nums) {
    fast_in_out;
    vector<vector<int>>ans;
    set<int>ind;
    for(int i = 0; i < nums.size(); i++)ind.insert(i);
    permute(nums, {}, ind);
    
    for(auto a : A){
        ans.push_back(a);
    }


    return ans;        
}


int32_t main()
{
    fast_in_out;
    int n;
    cin>>n;
    vin v(n);
    forn(i,n)cin>>v[i];    
    permuteUnique(v);
    
}