#include<bits/stdc++.h>
using namespace std;

#define ll                long long

#define endl               "\n"
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)
#define print(aaa)         for(auto a : aaa) cout<<a<<" "; cout<<endl;


int search(vector<int>& nums, int target) {

    int l = 0, r = nums.size()-1;
    int mid;

    while(r - l > 1){
        mid = (r + l) / 2;
        if(nums[mid] < target){
            l = mid +1;
        }
        else {
            r = mid;
        }
    }

    if(nums[l] == target){
        return l;
    }
    else if(nums[r] == target){
        return r;
    }

    return -1;
        
 }


signed main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    forn(i,n)cin>>v[i];

    cout<<search(v, 44);
    
}