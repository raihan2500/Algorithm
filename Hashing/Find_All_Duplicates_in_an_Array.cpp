#include<bits/stdc++.h>
using namespace std;

#define ll                long long

#define endl               "\n"
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)
#define print(aaa)         for(auto a : aaa) cout<<a<<" "; cout<<endl;

vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    vector<int>ans, cnt(n+1);
    for(int i = 0; i < n; i++){
        cnt[nums[i]]++;
    }
    for(int i = 0; i <= n; i++){
        if(cnt[i] == 2)ans.push_back(i);
    }
    // print(cnt);
    // print(ans);

    return ans;      
}


signed main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    forn(i,n)cin>>v[i];
    findDuplicates(v);
    
}