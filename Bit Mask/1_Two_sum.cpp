#include<bits/stdc++.h>
using namespace std;

#define ll                long long

#define endl               "\n"
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)
#define print(aaa)         for(auto a : aaa) cout<<a<<" "; cout<<endl;


vector<int> twoSum(vector<int>& nums, int target) {
    multimap<int,pair<int,int>>m;
    int n = nums.size();

    for(int i = 0; i < n; i++){
        m.insert({nums[i], {1, i}});
    }

    for(auto a : m){
        int findd = target - a.first;
        if(m.count(findd) == 1){
            
        }
    }

    
}


signed main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    forn(i,n){
        cin>>v[i];
    }
    twoSum(v, 4);
    
}