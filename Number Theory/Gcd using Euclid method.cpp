#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b)
{
    if(a==0)return b;
    if(b==0)return a;

    if(b%a==0)return a;
    return gcd(b%a,a);

}


int main()
{
    int a, b;
    a = 0, b = 18;

    cout<<gcd(a,b)<<endl;
}