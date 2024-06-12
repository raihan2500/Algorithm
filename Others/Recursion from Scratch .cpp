#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)
ll sum=1;
ll fact(ll n)
{
    if(n==0)return 1;
    return fact(n-1)*n;
    
}


int main()
{
    ll n;
    cin>>n;
    cout<<fact(n);nl; 
}

//1.Number of function calls
//2.What is complexitty of each function