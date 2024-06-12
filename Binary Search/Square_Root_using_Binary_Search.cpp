#include<bits/stdc++.h>
using namespace std;

#define int                long long

#define endl               "\n"
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)

double eps = 1e-7;


signed main()
{
    double x;
    cin>>x;
    double lo = 1, hi = x, mid;

    while(hi - lo > eps){

        mid = (hi + lo) / 2;
        if(mid*mid < x){
            lo = mid ;
        }
        else {
            hi = mid;
        }
    }
    cout<<setprecision(10)<<mid<<endl;
    cout<<setprecision(10)<<pow(x,1.0/2)<<endl;

    //Time complexity = P * log(N * 10^d)
    // p = pth root ex : square, p = 2; cube, p = 3
    
}