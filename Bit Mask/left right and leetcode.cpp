#include<bits/stdc++.h>
using namespace std;

typedef                    long long ll;
#define nl                 cout<<"\n"
#define forn(i,e)          for(ll i=0;i<e;i++)

int rangeBitwiseAnd(int left, int right) {
    unsigned int b = 1;
    if(left==right)return (left&right);
    while(b<=left)b <<=1; b>>=1;
    if(left>1)left = b;
    b=1;
    while(b<=right) b<<=1; b>>=1;

    if(right>1)right =b;
    return (left&right);
}


int main()
{
    int l,r;
    cin>>l>>r;
    cout<<rangeBitwiseAnd(l,r);
    
}