#include<bits/stdc++.h>
using namespace std;

#define ll                long long

#define endl               "\n"
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)
#define print(aaa)         for(auto a : aaa) cout<<a<<" "; cout<<endl;

#define fast_in_out        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


int countPrimes(int n) {
    fast_in_out;

    vector<bool> isPrime(n+1, 1);
    isPrime[0] = 0; isPrime[1] = 0;

    int cnt = 0;
    for(int i = 2; i * i< n; i++){
        if(isPrime[i]){
            for(int j = i * i; j < n; j+=i){
                isPrime[j] = 0;
            }

        }
    }
    for(int i = 2; i < n; i++){
        if(isPrime[i])cnt++;
    }
    return cnt;     
}


signed main()
{
    int n;
    cin>>n;
    cout<<countPrimes(n);
    
}