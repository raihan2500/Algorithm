#include<bits/stdc++.h>
using namespace std;

#define int                long long

#define endl               "\n"
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)


int lower_bound(vector<int>v, int element){
    int lo = 0, hi = v.size()-1;
    int mid;

    while(hi - lo >1){
        mid = (hi + lo) / 2;
        if(v[mid] < element){
            lo = mid +  1;
        }
        else{
            hi = mid;
        }
        // cout<<lo<<" "<<hi<<endl;
    }

    if(v[lo] >= element){
        return lo;
    }
    if(v[hi] >=element){
        return hi;
    }
    return -1;
}

int upper_bound(vector<int>v, int element){
    int lo = 0, hi = v.size()-1;
    int mid;

    while(hi - lo >1){
        mid = (hi + lo) / 2;
        if(v[mid] <= element){
            lo = mid +  1;
        }
        else{
            hi = mid;
        }
        // cout<<lo<<" "<<hi<<endl;
    }

    if(v[hi] >=element){
        return hi;
    }
    if(v[lo] >= element){
        return lo;
    }
    return -1;
}



signed main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    int x;
    cin>>x;
    cout<<lower_bound(v,x)<<endl;
    cout<<upper_bound(v,x)<<endl;


    
}