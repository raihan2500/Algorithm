#include<bits/stdc++.h>
using namespace std;

#define int                long long

#define endl               "\n"
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)


int fact(int n){
    if(n==0)
        return 1;
        
    int smallerProblem = fact(n-1);
    int biggerProblem = n* smallerProblem;

    return biggerProblem;
}

signed main()
{

    int n;
    cin>>n;
    int m = 0;
    cout<<fact(n);
    
}