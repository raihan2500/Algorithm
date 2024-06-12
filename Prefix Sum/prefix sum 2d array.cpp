//2D pre computation
// find the sum of the region of array[a][b] to array a[c][d]
#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)

const int N=1e3+10;
int ar[N][N];
int main()
{
    ll n,x,q;
    cin>>n;
   	for(ll i=1;i<=n;i++)
   	{
   		for(ll j=1;j<=n;j++)
   		{
   			cin>>x;
   			ar[i][j]=x+ar[i][j-1]+ar[i-1][j]-ar[i-1][j-1];
   		}
   	}
    // for(ll i=1;i<=n;i++){
    //     for(ll j=1;j<=n;j++)
    //         cout<<ar[i][j]<<" ";nl;
    // }
   	cin>>q;
   	while(q--)
   	{
   		ll a,b,c,d;
   		cin>>a>>b>>c>>d;
   		cout<<ar[c][d]-ar[c][b-1]-ar[a-1][d]+ar[a-1][b-1];nl;
   	}
}