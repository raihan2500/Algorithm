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

void combination(vector<vector<int>>&ans, vector<int> &v, vector<int> vec, int &target, int sum, int ind){

    print(vec);
    if(sum>target)return;
    if(sum == target){
        ans.push_back(vec);
        return;
    }

    for(int i = ind; i < v.size(); i++){

        vector<int>vv = vec; vv.push_back(v[i]);
        
        combination(ans, v, vv, target, sum + v[i], ind+i);

    }    
    
}


vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;

    sort(candidates.begin(),candidates.end());

    combination(ans, candidates, {}, target, 0, 0);


    for(auto a : ans){
        // print(a);
    }

    return ans;
}


int32_t main()
{
    fast_in_out;
    int n, target;
    cin>>n>>target;
    vin v(n);

    forn(i,n)cin>>v[i];
    combinationSum(v, target);  
}