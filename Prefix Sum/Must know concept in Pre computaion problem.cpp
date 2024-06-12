#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)

const int N=1e7;
int ar[N];


int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b,d;
        cin>>a>>b>>d;
        ar[a] +=d;
        ar[b+1] -=d;
    }

    for(int i=1;i<=n;i++)
        ar[i]+=ar[i-1];

    ll mx =0;
    for(int i=1;i<=n;i++)
        if(ar[i]>mx)
            mx=ar[i];

    cout<<mx;nl;
      
    return 0;
}