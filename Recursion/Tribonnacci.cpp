#include<bits/stdc++.h>
using namespace std;

#define ll                long long

#define endl               "\n"
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)
#define print(aaa)         for(auto a : aaa) cout<<a<<" "; cout<<endl;



int tribonacci(int n) {

    if(n < 3){
        if(n == 0)return 0;
        else return 1;
    }

    int a = 0, b = 1, c = 1, d ;

    for(int i = 2; i<n; i++){
        d = a + b + c;
        a = b; b = c; c = d;
    }
    
    
    cout<<d<<endl;    
    return d;    
}


signed main()
{
    int n;
    cin>>n;
    // cout<<n<<endl;
    tribonacci(n);   
    
}