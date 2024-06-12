#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;


int fact(int n)
{
    if(n==1)return 1;
    return fact(n-1)*n;


}


int main()
{
    int n;
    cin>>n;

    cout<<fact(n);

}