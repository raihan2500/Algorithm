#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)

int main()
{
    vector<int>nums;

    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++)
        if(nums[i]==nums[i+1])return true;
    return false;
    
}