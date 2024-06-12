#include<bits/stdc++.h>
using namespace std;

#define ll                long long

#define endl               "\n"
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)
#define print(aaa)         for(auto a : aaa) cout<<a<<" "; cout<<endl;


#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int hours_counts(vector<int> v, int n, int k){

    int hours_count = 0;

    for(int i = 0; i < n; i++){
        hours_count += ceil(v[i] * 1.0 / k);
    }

    return hours_count;

}



 int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int l = 1, r = 1e9, mid;
    fast_in_out;

    while(r - l > 0){
        mid = (r + l) / 2;
        int hours = hours_counts(piles, n, mid);
        if(hours > h){
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }    

    return l;        
}



signed main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    forn(i,n)cin>>v[i];
    int h;
    cin>>h;

    
    cout<<minEatingSpeed(v,h);
    
}