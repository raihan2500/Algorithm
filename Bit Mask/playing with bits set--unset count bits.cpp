#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)

int main()
{
    int n,p,x=1;
    cin>>n>>p;
    x<<=p;
    if((x&n)==x)cout<<"Set";
    else cout<<"Unset"; nl;

    //For set a bit
    n|=x;
    cout<<n;nl;

    //For unset a bit
    x=~x;
    n&=x;  
    cout<<n;nl;


    cout<<(int)'_';nl;
    bitset<8>ud(4-1);
    cout<<ud;nl;   
    cout<<(1<<2);
    
}